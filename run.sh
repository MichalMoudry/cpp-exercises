#!/bin/bash
path=./udemy/section13/implementing_methods_2
cpp_version=c++14

g++ $path/*.cpp -std=$cpp_version -o ./output/main
./output/main