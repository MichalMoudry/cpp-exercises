cpp_version := c++14
path := "./udemy/section20/stl_algorithms"
#path=./udemy/vehicle_purchase

run:
	g++ $(path)/*.cpp -std=$(cpp_version) -o ./output/main
	./output/main