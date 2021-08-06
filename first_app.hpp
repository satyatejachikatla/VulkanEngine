#pragma once

#include <ve_window/ve_window.hpp>

namespace ve {
    class FirstApp {

        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

        private:
        
        VeWindow veWindow{WIDTH, HEIGHT, "Hello World"};

    };
}