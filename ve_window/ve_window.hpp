#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace ve
{
    class VeWindow
    {
    private:
        void initWindow();

        int width;
        int height;
        bool framebufferResized = false;

        std::string windowName;
        GLFWwindow *window;

        static void framebufferResizeCallback(GLFWwindow *window, int width, int height);

    public:
        VeWindow(const VeWindow &) = delete;
        VeWindow &operator=(const VeWindow &) = delete;

        VeWindow(int w, int h, std::string name);
        ~VeWindow();

        bool shouldClose() { return glfwWindowShouldClose(window); }
        bool wasWindowResized() { return framebufferResized; }
        void resetWindowResizedFlag() { framebufferResized = false; }
        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

        VkExtent2D getExtent() { return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)}; }
    };
}