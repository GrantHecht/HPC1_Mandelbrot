
# Link command
all: main.o Grid.o GridPoint.o
	g++ main.o Grid.o GridPoint.o -o main

main.o: main.cpp Grid.hpp
	g++ -I. -c main.cpp

grid.o: Grid.cpp GridPoint.hpp
	g++ -I. -c Grid.cpp

GridPoint.o: GridPoint.cpp 
	g++ -I. -c GridPoint.cpp

clean:
	rm -rf *.o
