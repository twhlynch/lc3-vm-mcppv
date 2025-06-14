#pragma once

#include <glad/glad.h>

#include <filesystem>
#include <string>

class Shader {
  public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void use();

    GLuint getProgramID() const;

  private:
    std::string loadFile(const std::string& path);
    GLuint compileShader(GLenum type, const std::string& src);
    GLuint linkProgram(const std::string& vs, const std::string& fs);

    GLuint _programID;
};
