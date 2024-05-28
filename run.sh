#!/bin/bash
path=./udemy/section13/section_challenge
cpp_version=c++17

g++ $path/*.cpp -std=$cpp_version -o ./output/main
./output/main