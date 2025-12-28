cpp_version := c++14
path := "./udemy/section21/StatefulLambdas"
#path=./udemy/vehicle_purchase

run:
	g++ $(path)/*.cpp -std=$(cpp_version) -o ./output/main
	./output/main