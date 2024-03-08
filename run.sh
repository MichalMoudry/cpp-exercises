#!/bin/bash
path=./udemy/section9/do_while_loop
cpp_version=c++17

g++ $path/main.cpp -std=$cpp_version -o ./output/main
./output/main