
CFLAGS = -std=c++17 -I.
LDFLAGS = `pkg-config --static --libs glfw3` -lvulkan

GLSLC = /usr/local/bin/glslc

# create list of all spv files and set as dependency
vertSources = $(shell find ./shaders -type f -name "*.vert")
vertObjFiles = $(patsubst %.vert, %.vert.spv, $(vertSources))
fragSources = $(shell find ./shaders -type f -name "*.frag")
fragObjFiles = $(patsubst %.frag, %.frag.spv, $(fragSources))
cppFiles = $(shell find . | grep -E ".cpp$$")
hppFiles = $(shell find . | grep -E ".hpp$$")

TARGET = a.out

all: $(TARGET)
	echo Done

$(TARGET): $(vertObjFiles) $(fragObjFiles)
$(TARGET): $(cppFiles) $(hppFiles)
	g++ $(CFLAGS) -o $(TARGET) $(cppFiles) $(LDFLAGS)

# make shader targets
%.spv: %
	${GLSLC} $< -o $@

.PHONY: clean

clean:
	rm -f $(TARGET)
	rm -f $(vertObjFiles) $(fragObjFiles)