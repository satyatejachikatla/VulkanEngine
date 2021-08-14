#!/bin/bash

if [ "$1" == "" ]; then
    echo No Parameters
    exit 1
fi

for shader_dir in $@
do  

    VIRT_FILE=`ls $shader_dir/*.vert`
    FRAG_FILE=`ls $shader_dir/*.frag`

    echo Building shader : $shader_dir
    echo Virt shader : $VIRT_FILE
    echo Frag shader : $FRAG_FILE

    /usr/local/bin/glslc $VIRT_FILE -o $VIRT_FILE.spv
    if [ $? -ne 0 ]; then
        exit 1
    fi
    /usr/local/bin/glslc $FRAG_FILE -o $FRAG_FILE.spv
    if [ $? -ne 0 ]; then
        exit 1
    fi
done