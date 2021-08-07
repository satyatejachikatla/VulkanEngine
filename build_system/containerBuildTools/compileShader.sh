#!/bin/bash

if [ "$1" == "" ]; then
    exit 1
fi

/usr/local/bin/glslc $1.vert -o $1.vert.spv
if [ $? -ne 0 ]; then
    exit 1
fi
/usr/local/bin/glslc $1.frag -o $1.frag.spv
if [ $? -ne 0 ]; then
    exit 1
fi