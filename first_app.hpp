#pragma once

#include <ve_window/ve_window.hpp>
#include <ve_pipeline/ve_pipeline.hpp>

namespace ve {
    class FirstApp {

        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

        private:
        
        VeWindow veWindow{WIDTH, HEIGHT, "Hello World"};
        VePipeline vePipeline{"shaders/simple_shader.vert.spv","shaders/simple_shader.frag.spv"};
    };
}