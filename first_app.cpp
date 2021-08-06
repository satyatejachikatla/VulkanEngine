#include <first_app.hpp>

#include <iostream>

namespace ve {

    void FirstApp::run(){
        while(!veWindow.shouldClose()) {
            glfwPollEvents();
        }
    }

}