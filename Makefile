CFLAGS = -std=c++17 -O2 -I .
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

CPP_FILES = $(shell find . | grep -E ".cpp$$")
HPP_FILES = $(shell find . | grep -E ".hpp$$")

VulkanTest: $(CPP_FILES) $(HPP_FILES)
	g++ $(CFLAGS) -o VulkanTest $(CPP_FILES) $(LDFLAGS)

.PHONY: test clean

clean:
	rm -f VulkanTest