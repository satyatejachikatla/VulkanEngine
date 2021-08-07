#include <ve_pipeline/ve_pipeline.hpp>

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace ve {
    VePipeline::VePipeline(const std::string& vertFilepath , const std::string& fragFilepath){
        createGraphicsPipeline(vertFilepath,fragFilepath);
    }

    std::vector<char> VePipeline::readFile(const std::string& filepath) {
        std::ifstream file(filepath,std::ios::ate | std::ios::binary);
        if(!file.is_open()) {
            throw std::runtime_error("failed to open file : " + filepath);
        }

        // Since we have opened the file in ios::ate , tellg gives size
        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();

        return buffer;
    }

    void VePipeline::createGraphicsPipeline(const std::string& vertFilepath , const std::string& fragFilepath) {
        auto vertCode = readFile(vertFilepath);
        auto fragCode = readFile(fragFilepath);

        std::cout << "Vertex Shader code loaded of size : " << vertCode.size() << std::endl;
        std::cout << "Fragment Shader code loaded of size : " << fragCode.size() << std::endl;
    }
}