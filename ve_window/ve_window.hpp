#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace ve {
    class VeWindow {
        private:

        void initWindow();

        const int width;
        const int height;

        std::string windowName;
        GLFWwindow* window;

        public:

        VeWindow(const VeWindow &) = delete;
        VeWindow & operator=(const VeWindow &) = delete;

        VeWindow(int w,int h,std::string name);
        ~VeWindow();

        bool shouldClose() { return glfwWindowShouldClose(window); }
        void createWindowSurface(VkInstance instance,VkSurfaceKHR *surface);

        VkExtent2D getExtent() { return {static_cast<uint32_t>(width),static_cast<uint32_t>(height)}; }
    };
}