#!/bin/bash
rm -rf build
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH -DQt5_DIR=$Qt5_DIR ..
make
