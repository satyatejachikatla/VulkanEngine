#include <ve_window/ve_window.hpp>

namespace ve {

    VeWindow::VeWindow(int w,int h,std::string name) : width(w) , height(h), windowName(name) {
        initWindow();
    }

    void VeWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width,height,windowName.c_str(),nullptr,nullptr);
    }


    VeWindow::~VeWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }


}