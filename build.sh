#!/bin/bash

echo "Building project..."

if [ ! -d ./out ]; then
  mkdir ./out
fi

cd ./out

echo "[ - Clean build dir]"
rm -rf ./*

echo "[ - CMake]"
if [ $USER == "tcd" ]
then
  cmake -G "Unix Makefiles" ../.tcd
elif [ $USER == "mww" ]
then
  cmake -G "Unix Makefiles" ../.mww
else
  echo "USER env var not set..."
fi

echo "[ - Make]"
make

cd ..

echo "Done."
