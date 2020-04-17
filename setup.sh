#!/bin/bash

##
## checkout the unity testing framework
##
if ! [ -d micro/unity ]; then
    echo "Checking out Unity source code..."
    git clone https://github.com/ThrowTheSwitch/Unity.git micro/unity
fi
