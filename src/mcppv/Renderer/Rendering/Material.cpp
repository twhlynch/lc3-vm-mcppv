#include "Material.hpp"
#include "../Logging.hpp"
#include "../Rendering/Shader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

Material::Material() : _renderType(Triangles), _wireframe(false), _cullBackface(true) {}
Material::Material(std::string& imagePath) : Material() {
    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    std::string assetsPath = "assets/";
    if (!std::filesystem::exists(assetsPath)) {
        assetsPath = "/usr/local/share/mcppv/assets/";
        if (!std::filesystem::exists(assetsPath)) {
            ERROR("Assets not found");
            std::exit(EXIT_FAILURE);
        }
    }

    int width, height, nrChannels;
    unsigned char* data =
        stbi_load((assetsPath + "textures/" + imagePath).c_str(), &width, &height, &nrChannels, 0);
    if (!data) {
        WARN("Failed to load: " << imagePath);
        data =
            stbi_load((assetsPath + "textures/error.png").c_str(), &width, &height, &nrChannels, 0);
    }
    if (data) {
        GLenum format = GL_RGB;
        if (nrChannels == 4)
            format = GL_RGBA;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 1)
            format = GL_RED;

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    stbi_image_free(data);
}
Material::~Material() {}

void Material::draw(Mesh* mesh, Shader* shader) {
    if (_cullBackface) {
        glCullFace(GL_BACK);
        glEnable(GL_CULL_FACE);
    } else {
        glDisable(GL_CULL_FACE);
    }
    glFrontFace(GL_CW);

    if (_wireframe) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDisable(GL_CULL_FACE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        if (_cullBackface) {
            glEnable(GL_CULL_FACE);
        }
    }

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture);

    GLint texLoc = glGetUniformLocation(shader->getProgramID(), "tex");
    if (texLoc != -1)
        glUniform1i(texLoc, 0);

    glBindVertexArray(mesh->_VAO);
    glDrawArrays(_renderType, 0, static_cast<GLsizei>(mesh->_vertexCount));
}

void Material::setRenderType(RenderType type) { _renderType = type; }
void Material::setWireframe(bool value) { _wireframe = value; }
void Material::setCullBackface(bool value) { _cullBackface = value; }