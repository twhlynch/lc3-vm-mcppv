#pragma once

#include <glad/glad.h>

#include <vector>

class Material;
class Mesh {
    friend class Material;

  public:
    Mesh(const std::vector<float> vertices, const std::vector<float> texCoords = {});
    ~Mesh();

    std::vector<float>* GetVertices();

    Mesh* operator+(const Mesh& other) const;

    static std::vector<float> generateTexCoords(const std::vector<float>& vertices);

    static Mesh* WithQuad(float w = 1.0f, float h = 1.0f);
    static Mesh* WithCube(float scale = 1.0f);

  private:
    GLuint _VAO, _VBO, _UVVBO;
    size_t _vertexCount;
    std::vector<float> _vertices;
    std::vector<float> _texCoords;
};
