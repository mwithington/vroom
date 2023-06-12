#!/bin/bash

echo "Building project..."

if [ ! -d ./build ]; then
  mkdir ./build
fi

cd ./build

echo "[ - Clean build dir]"
rm -rf ./*

echo "[ - CMake]"
cmake -G "Unix Makefiles" ..
# cmake ..

echo "[ - Make]"
make
# mingw-make

cd ..

echo "Done."
