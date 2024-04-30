#!/bin/bash
path=./udemy/section12/exercise4
cpp_version=c++17

g++ $path/main.cpp -std=$cpp_version -o ./output/main
./output/main