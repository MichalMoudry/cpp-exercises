#!/bin/bash
path=./udemy/section12/dynamic_memory
cpp_version=c++17

g++ $path/main.cpp -std=$cpp_version -o ./output/main
./output/main