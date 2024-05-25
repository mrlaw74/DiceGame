#!/bin/bash

# Set environment variables for Qt5
export CMAKE_PREFIX_PATH="/usr/local/opt/qt@5/lib/cmake"
export Qt5_DIR="/usr/local/opt/qt@5/lib/cmake/Qt5"

# Print environment variables for debugging
echo "CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH"
echo "Qt5_DIR=$Qt5_DIR"

rm -rf build
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH -DQt5_DIR=$Qt5_DIR ..
make
