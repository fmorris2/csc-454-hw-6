main: framework/model/*.cpp framework/simulation/*.cpp framework/event/*.cpp framework/pqueue/*.cpp hw3_model/*.cpp hw3_model/sub_models/*.cpp main.cpp
	g++ -std=c++11 -o main.exe main.cpp framework/model/*.cpp framework/event/*.cpp framework/pqueue/*.cpp framework/simulation/*.cpp hw3_model/*.cpp hw3_model/sub_models/*.cpp
