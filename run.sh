#!/bin/bash
path=./udemy/section9/switch/
cpp_version=c++17

g++ $path/main.cpp -std=$cpp_version -o main
./main