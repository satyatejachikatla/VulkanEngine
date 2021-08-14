#pragma once

#include <ve_window/ve_window.hpp>
#include <ve_pipeline/ve_pipeline.hpp>
#include <ve_device/ve_device.hpp>

namespace ve {
    class FirstApp {

        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

        private:
        
        VeWindow veWindow{WIDTH, HEIGHT, "Hello World"};
        VeDevice veDevice{veWindow};
        VePipeline vePipeline{
            veDevice,
            "shaders/simple_shader/simple_shader.vert.spv",
            "shaders/simple_shader/simple_shader.frag.spv",
            VePipeline::defaultPipelineConfigInfo(WIDTH,HEIGHT)
            };
    };
}