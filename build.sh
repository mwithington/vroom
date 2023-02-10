#!/bin/bash

echo "Building project..."

cd ./build

echo "[ - Clean build dir]"
rm -rf ./build/*

echo "[ - CMake]"
cmake -G "Unix Makefiles" ..

echo "[ - Make]"
make

cd ..

echo "Done."
