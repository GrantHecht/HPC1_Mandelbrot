
# Link command
all: main.o GridPoint.o
	g++ main.o GridPoint.o -o main

main.o: main.cpp GridPoint.hpp
	g++ -I. -c main.cpp

GridPoint.o: GridPoint.cpp 
	g++ -I. -c GridPoint.cpp

clean:
	rm -rf *.o
