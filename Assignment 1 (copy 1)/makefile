#~ main: Hobbit.o Wizard.o Spell.o main.cpp
	#~ g++ -std=c++11 -static Hobbit.o Wizard.o Spell.o main.cpp -0 main

#~ Hobbit.o: Hobbit.cpp Hobbit.h
	#~ g++ -std=c++11 -static -c Hobbit.cpp

#~ Wizard.o: Wizard.cpp Wizard.h
	#~ g++ -std=c++11 -static -c Wizard.cpp



main: Spell.o main.cpp
	g++ -std=c++11 -static Spell.o main.cpp -o main
Spell.o: Spell.cpp Spell.h
	g++ -std=c++11 -static -c Spell.cpp
run: main 
	./main
