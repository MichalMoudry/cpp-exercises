#!/bin/bash
#path=./udemy/section14/operator_overloading
path=./exercism/vehicle_purchase
cpp_version=c++14

g++ $path/*.cpp -std=$cpp_version -o ./output/main
./output/main