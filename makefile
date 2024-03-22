all: program

program: main.o lib.o
	g++ main.o lib.o -o main

lib.o: lib.cpp
	g++ -c lib.cpp

main.o : main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o program
