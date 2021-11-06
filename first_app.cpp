#include <first_app.hpp>

#include <simple_render_system/simple_render_system.hpp>

// libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include <iostream>
#include <stdexcept>
#include <array>

namespace ve
{

    FirstApp::FirstApp()
    {
        loadGameObjects();
    }

    FirstApp::~FirstApp()
    {
    }

    void FirstApp::run()
    {
        SimpleRenderSystem simpleRenderSystem{veDevice,veRenderer.getSwapChainRenderPass()};

        while (!veWindow.shouldClose())
        {
            glfwPollEvents();
            if (auto commandBuffer = veRenderer.beginFrame())
            {
                veRenderer.beginSwapChainRenderPass(commandBuffer);
                simpleRenderSystem.renderGameObjects(commandBuffer,gameObjects);
                veRenderer.endSwapChainRenderPass(commandBuffer);
                veRenderer.endFrame();
            }
        }

        vkDeviceWaitIdle(veDevice.device());
    }

    void FirstApp::loadGameObjects()
    {
        std::vector<VeModel::Vertex> vertices{
            {{.0f, -.5f}, {1.f, 0.f, .0f}},
            {{.5f, .5f}, {0.f, 1.f, .0f}},
            {{-.5f, .5f}, {0.f, 0.f, 1.f}}};

        auto veModel = std::make_shared<VeModel>(veDevice, vertices);
        auto triangle = VeGameObject::createGameObject();

        triangle.model = veModel;
        triangle.color = {.1f, .8f, .1f};
        triangle.transform2d.translation.x = .2f;
        triangle.transform2d.scale = {2.f, .5f};
        triangle.transform2d.rotation = .25 * glm::two_pi<float>();

        gameObjects.push_back(std::move(triangle));
    }
}