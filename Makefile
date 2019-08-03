main.out:	main.o Matriz.o
	g++ -std=c++11 main.o Matriz.o -o main

main.o:	main.cpp
	g++ -std=c++11 -c main.cpp

Matriz.o:	Matriz.cpp	Matriz.h
	g++ -std=c++11 -c Matriz.cpp 
