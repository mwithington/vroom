#!/bin/bash

echo "Building project..."

if [ ! -d ./build ]; then
  mkdir ./build
fi

cd ./build

echo "[ - Clean build dir]"
rm -rf ./*

echo "[ - CMake]"
if [ $USER == "tcd" ]
then
  cmake -G "Unix Makefiles" ../.tcd
elif [ $USER == "mww" ] || [ $USER == "michaelwithington" ]
then
  cmake -G "Unix Makefiles" ../.mww
else
  echo "USER env var not set..."
fi

echo "[ - Make]"
make

cd ..

echo "Done."
