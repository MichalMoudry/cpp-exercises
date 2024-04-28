#!/bin/bash
path=./udemy/section12/pass_by_ref
cpp_version=c++17

g++ $path/main.cpp -std=$cpp_version -o ./output/main
./output/main