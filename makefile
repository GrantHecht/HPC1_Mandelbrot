
# Link command
main: main.o GridPoint.o
	g++ main.o GridPoint.o -o main

main.o: main.cpp GridPoint.hpp
	g++ -c main.cpp

GridPoint.o: GridPoint.cpp 
	g++ -c GridPoint.cpp
