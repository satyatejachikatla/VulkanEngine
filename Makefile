CFLAGS = -std=c++17 -O2 -I .
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

CPP_FILES = $(shell find . | grep -E ".cpp$$")
HPP_FILES = $(shell find . | grep -E ".hpp$$")
SHADER_PIPELINE_FILES= $(shell find . | grep -E "(.frag|.vert)$$")
SHADER_PIPELINE_FOLDERS= $(shell ls -d ./shaders/*)

SHADER_SPV_FILES = $(shell find . | grep -E ".spv$$")

VulkanTest: $(CPP_FILES) $(HPP_FILES) SpvBuild
	g++ $(CFLAGS) -o VulkanTest $(CPP_FILES) $(LDFLAGS)

SpvBuild : $(SHADER_PIPELINE_FILES)
	./build_system/containerBuildTools/compileShader.sh $(SHADER_PIPELINE_FOLDERS)

.PHONY: test clean

clean:
	rm -f VulkanTest
	rm -f $(SHADER_SPV_FILES)