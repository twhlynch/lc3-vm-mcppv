#include "Mesh.hpp"

#include "../Logging.hpp"

#include <cmath>

Mesh::Mesh(const std::vector<float> vertices, const std::vector<float> texCoords)
    : _vertices(vertices), _texCoords(texCoords) {
    _vertexCount = _vertices.size() / 3;
    if (_texCoords.empty())
        _texCoords = generateTexCoords(_vertices);

    glGenBuffers(1, &_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(float), _vertices.data(),
                 GL_STATIC_DRAW);

    glGenBuffers(1, &_UVVBO);
    glBindBuffer(GL_ARRAY_BUFFER, _UVVBO);
    glBufferData(GL_ARRAY_BUFFER, _texCoords.size() * sizeof(float), _texCoords.data(),
                 GL_STATIC_DRAW);

    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, _UVVBO);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &_VAO);
    glDeleteBuffers(1, &_VBO);
}

std::vector<float>* Mesh::GetVertices() { return &_vertices; }

Mesh* Mesh::operator+(const Mesh& other) const {
    std::vector<float> vertices;
    std::vector<float> texCoords;

    vertices.insert(vertices.end(), _vertices.begin(), _vertices.end());
    vertices.insert(vertices.end(), other._vertices.begin(), other._vertices.end());
    texCoords.insert(texCoords.end(), _texCoords.begin(), _texCoords.end());
    texCoords.insert(texCoords.end(), other._texCoords.begin(), other._texCoords.end());

    return new Mesh(vertices, texCoords);
}

std::vector<float> Mesh::generateTexCoords(const std::vector<float>& vertices) {
    std::vector<float> texCoords;

    size_t vertexCount = vertices.size() / 3;
    for (size_t i = 0; i < vertexCount; i += 6) { // triangles only
        std::vector<float> faceCoords = {
            0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        };
        texCoords.insert(texCoords.end(), faceCoords.begin(), faceCoords.end());
    }

    return texCoords;
}

Mesh* Mesh::WithQuad(float w, float h) {
    float hw = w * 0.5f;
    float hh = h * 0.5f;

    return new Mesh(
        {
            -hw,
            -hh,
            0.0f,
            hw,
            hh,
            0.0f,
            hw,
            -hh,
            0.0f,

            -hw,
            -hh,
            0.0f,
            -hw,
            hh,
            0.0f,
            hw,
            hh,
            0.0f,
        },
        {
            0.0f,
            1.0f,
            1.0f,
            0.0f,
            1.0f,
            1.0f,

            0.0f,
            1.0f,
            0.0f,
            0.0f,
            1.0f,
            0.0f,
        });
}

Mesh* Mesh::WithCube(float scale) {
    float hs = scale * 0.5f;

    return new Mesh(
        {
            -hs, -hs, hs,  hs,  hs,  hs,  hs,  -hs, hs, // front bottom left
            -hs, -hs, hs,  -hs, hs,  hs,  hs,  hs,  hs, // front top right

            -hs, -hs, -hs, hs,  hs,  -hs, -hs, hs,  -hs, // back bottom left
            -hs, -hs, -hs, hs,  -hs, -hs, hs,  hs,  -hs, // back top right

            -hs, -hs, -hs, -hs, hs,  hs,  -hs, -hs, hs, // left bottom left
            -hs, -hs, -hs, -hs, hs,  -hs, -hs, hs,  hs, // left top right

            hs,  -hs, -hs, hs,  hs,  hs,  hs,  hs,  -hs, // right bottom left
            hs,  -hs, -hs, hs,  -hs, hs,  hs,  hs,  hs,  // right top right

            -hs, hs,  -hs, hs,  hs,  hs,  -hs, hs,  hs, // top bottom left
            -hs, hs,  -hs, hs,  hs,  -hs, hs,  hs,  hs, // top top right

            -hs, -hs, -hs, hs,  -hs, hs,  hs,  -hs, -hs, // bottom bottom left
            -hs, -hs, -hs, -hs, -hs, hs,  hs,  -hs, hs,  // bottom top right
        },
        {
            0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,

            0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        });
}