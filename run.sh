#!/bin/bash
path=./udemy/section18/exceptions
#path=./udemy/vehicle_purchase
cpp_version=c++14

g++ $path/*.cpp -std=$cpp_version -o ./output/main
./output/main