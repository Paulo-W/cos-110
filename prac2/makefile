main: Adventurer.o  main.cpp
	g++ -std=c++11 -static Adventurer.o  main.cpp -o main 

Adventurer.o: Adventurer.cpp 
	g++ -static -std=c++11 -c Adventurer.cpp 

run: main
	./main
	


clean:
	rm mian *.o