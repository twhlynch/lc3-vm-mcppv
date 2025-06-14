#include "Shader.hpp"

#include "../Logging.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string assetsPath = "assets/";
    if (!std::filesystem::exists(assetsPath)) {
        assetsPath = "/usr/local/share/mcppv/assets/";
        if (!std::filesystem::exists(assetsPath)) {
            ERROR("Assets not found");
            std::exit(EXIT_FAILURE);
        }
    }

    std::string vs = loadFile(assetsPath + vertexPath);
    std::string fs = loadFile(assetsPath + fragmentPath);
    _programID = linkProgram(vs, fs);
}

Shader::~Shader() { glDeleteProgram(_programID); }

void Shader::use() { glUseProgram(_programID); }

std::string Shader::loadFile(const std::string& path) {
    INFO("Loading " << path);

    std::ifstream file(path);

    if (!file) {
        ERROR("Failed to load: " << path);
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

GLuint Shader::compileShader(GLenum type, const std::string& src) {
    GLuint shader = glCreateShader(type);
    const char* cstr = src.c_str();
    glShaderSource(shader, 1, &cstr, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        ERROR("Shader compilation error: " << log);
    }

    return shader;
}

GLuint Shader::linkProgram(const std::string& vs, const std::string& fs) {
    GLuint vertex = compileShader(GL_VERTEX_SHADER, vs);
    GLuint fragment = compileShader(GL_FRAGMENT_SHADER, fs);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (!success) {
        char log[512];
        glGetProgramInfoLog(program, 512, nullptr, log);
        ERROR("Shader linking error: " << log);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return program;
}

GLuint Shader::getProgramID() const { return _programID; }