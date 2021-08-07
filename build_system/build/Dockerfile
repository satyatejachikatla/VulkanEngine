FROM ubuntu

# Update package list
RUN apt-get update

# Folder for downloads
RUN \
    mkdir /vendor

# Dependencies

# Vulkan Related installs
RUN \
    apt-get install -y \
    vulkan-tools \
    libvulkan-dev \
    vulkan-validationlayers-dev \
    spirv-tools

# GLFW
RUN \
    apt-get install -y \
    libglfw3-dev

# glslc

RUN \
    apt-get install -y \
    curl \
    wget

RUN \
    cd /vendor && \
    MY_CURL_OUTPUT=`curl -s https://storage.googleapis.com/shaderc/badges/build_link_linux_gcc_release.html` && \
    MY_WGET_URL=`echo $MY_CURL_OUTPUT | awk -F'url=' '{print $2}' | awk -F'\"' '{print $1}'` && \
    echo "wget $MY_WGET_URL"  && \
    wget $MY_WGET_URL && \
    mkdir /vendor/glslc && \
    mv install.tgz /vendor/glslc

RUN \
    cd /vendor/glslc && \
    tar -xvf install.tgz && \
    ln -sf /vendor/glslc/install/bin/glslc /usr/local/bin/glslc

# Build Tools

RUN apt install build-essential -y --no-install-recommends

# GLM

RUN apt-get install -y libglm-dev

# Dependencies for make

RUN \
    apt-get install -y \
    libxxf86vm-dev \
    libxi-dev

# To keep docker container up
RUN \
    mkdir /app
WORKDIR \
    /app
CMD tail -f /dev/null