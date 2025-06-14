#include "Simulation.hpp"
#include <cmath>
#include <iostream>
#include <limits.h>

#include "Renderer/Clock.hpp"
#include "Renderer/Logging.hpp"
#include "Renderer/Math/Quaternion.hpp"
#include "Renderer/Math/Vector3.hpp"
#include "Renderer/Rendering/Material.hpp"
#include "Renderer/Rendering/Mesh.hpp"
#include "Renderer/Rendering/Renderer.hpp"
#include "Renderer/Rendering/Shader.hpp"
#include "Renderer/Rendering/Window.hpp"
#include "Renderer/Scene/Camera.hpp"
#include "Renderer/Scene/Controller.hpp"
#include "types.hpp"

#include <GLFW/glfw3.h>

namespace mcppv {

Simulation::Simulation() : _playerPosition(0) {
    // starting platform
    for (int x = -20; x < 20; x++) {
        for (int z = -20; z < 20; z++) {
            setBlock(mcpp::Coordinate(x, -2, z), mcpp::Blocks::STONE);
        }
    }

    // test all blocks
    // std::vector<std::pair<mcpp::Coordinate, mcpp::BlockType>> allBlocks = getAllBlocks();
    // for (auto pair : allBlocks)
    // {
    // 	setBlock(pair.first, pair.second);
    // }
}

void Simulation::postToChat(const std::__1::string& message) {
    std::cout << "CHAT: " << message << std::endl;
}

mcpp::Coordinate Simulation::getPlayerPosition() { return _playerPosition; }

void Simulation::setPlayerPosition(const mcpp::Coordinate& pos) { _playerPosition = pos; }

mcpp::BlockType Simulation::getBlock(const mcpp::Coordinate& loc) {
    for (const Block& block : _blocks) {
        if (block.coordinate == loc) {
            return block.blockType;
        }
    }
    return mcpp::Blocks::AIR;
}

void Simulation::setBlock(const mcpp::Coordinate& loc, const mcpp::BlockType& blockType) {
    for (size_t i = 0; i < _blocks.size(); i++) {
        if (_blocks[i].coordinate == loc) {
            if (blockType == mcpp::Blocks::AIR) {
                _blocks.erase(_blocks.begin() + i);
            } else {
                _blocks[i].blockType = blockType;
            }
            return;
        }
    }
    if (blockType != mcpp::Blocks::AIR) {
        _blocks.push_back({loc, blockType});
    }
}

int Simulation::getHeight(int x, int z) {
    int height = INT16_MIN; // int 16 for lc3 (i think?)
    for (const Block& block : _blocks) {
        if (block.coordinate.x == x && block.coordinate.z == z) {
            height = std::max(height, block.coordinate.y);
        }
    }
    return height;
}

void Simulation::render() {
    Window* window = new Window(800, 600, "Renderer");
    Renderer* renderer = new Renderer();

    Camera* camera =
        new Camera(45.0f, 800.0f / 600.0f, 0.1f, 200.0f); // far should match fog end in shader
    camera->setPosition(Vector3(0, 0, 0));

    renderer->setCamera(camera);

    Controller* controller = new Controller(camera, window);

    Shader* shader = new Shader("shaders/vert.glsl", "shaders/frag.glsl");

    Mesh* cubeMesh = Mesh::WithCube();

    Mesh* plane = Mesh::WithQuad();
    Mesh* rotatedPlane = Mesh::WithQuad();
    std::vector<float>* rotatedPlaneVertices = rotatedPlane->GetVertices();
    for (size_t i = 0; i < rotatedPlaneVertices->size(); i += 3) {
        std::swap(rotatedPlaneVertices->at(i), rotatedPlaneVertices->at(i + 2));
    }
    Mesh* foliageMesh = *plane + *rotatedPlane;

    for (Block block : _blocks) {
        std::string texturePath = getBlockTexture(block.blockType);
        Material* material = new Material(texturePath);

        Entity* entity = nullptr;
        ModelType modelType = getModelType(block.blockType);
        if (modelType == BLOCK) {
            entity = new Entity(cubeMesh, material, shader);
        }
        if (modelType == FOLIAGE) {
            entity = new Entity(foliageMesh, material, shader);
            material->setCullBackface(false);
            entity->setRotation(Quaternion::WithAxisAngle(Vector3(0, 1, 0), M_PI / 180 * 45));
        } else if (modelType == PLANE) {
            entity = new Entity(cubeMesh, material, shader);
            entity->setScale(Vector3(1, 0.05, 1));
            entity->setPosition(Vector3(0, -0.475f, 0));
        } else if (modelType == WALL) {
            entity = new Entity(cubeMesh, material, shader);
            entity->setScale(Vector3(1, 1, 0.1));
        } else if (modelType == SLAB) {
            entity = new Entity(cubeMesh, material, shader);
            entity->setScale(Vector3(1, 0.5, 1));
            entity->setPosition(Vector3(0, -0.25, 0));
        } else // fallback to block
        {
            entity = new Entity(cubeMesh, material, shader);
        }

        entity->setPosition(entity->getPosition() +
                            Vector3(block.coordinate.x, block.coordinate.y, block.coordinate.z));
        renderer->addEntity(entity, isTransparent(block.blockType));
    }

    Clock* clock = new Clock();
    while (!window->shouldClose()) {
        float delta = clock->getDelta();

        controller->update(delta);

        renderer->draw();

        window->update();
    }

    delete window;
    delete renderer;
    delete camera;
    delete controller;
    delete shader;
    delete cubeMesh;
    delete clock;
}

} // namespace mcppv