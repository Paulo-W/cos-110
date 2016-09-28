main: Exception.o CharString.o main.cpp
	g++ -std=c++11 -static Exception.o CharString.o main.cpp -o main

Exception.o: Exception.h Exception.cpp

CharString.o: CharString.h CharString.cpp

run: main
	./main