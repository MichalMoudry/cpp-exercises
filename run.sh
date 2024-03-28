#!/bin/bash
path=./udemy/section10/assignment
cpp_version=c++17

g++ $path/main.cpp -std=$cpp_version -o ./output/main
./output/main