#include <cstring>
#include <iostream>
#include "Wizard.h"


Wizard::Wizard(){//the constructor
	maxNumberOfSpells= 10;
	
	spells = new Spell [maxNumberOfSpells];
	for (int i=0; i < maxNumberOfSpells; i++){
		//strcpy(spells, ""); // set the values inside of spell to blank
		spells[i] = Spell("");
	};
	
	numberOfSpells = 0; 
	hasBeenSummoned =false;
	age = 20;
	numberOfLossedSpells = 0;
	hasCompletedTraining = false;
}

Wizard::Wizard(const Wizard& w){//the copy constructor
	maxNumberOfSpells = w.maxNumberOfSpells;
	numberOfSpells = w.numberOfSpells;
	hasBeenSummoned = w.hasBeenSummoned;
	age = w.age;
	numberOfLossedSpells = w.numberOfLossedSpells;
	hasCompletedTraining = w.hasCompletedTraining;
	
	spells = new Spell [maxNumberOfSpells];
	
	for (int i=0; i < maxNumberOfSpells ; i++)
	{
		spells[i]= w.spells[i]; 
	}
	
}

Wizard::~Wizard(){// the destructor 
	delete [] spells;
}

void Wizard::addSpell(const Spell& s){
	if (numberOfSpells <= maxNumberOfSpells){
		// use a post increment to first store the value s inside spells at the subscript value of ie 0 which will then be incremented to 1 after the value has been stored in the array
		spells[numberOfSpells++]= s; 
	}
	else {
		// make the new spell list 5 cells larger than the previous one 
		maxNumberOfSpells += 5;
		Spell* newlist= new Spell [maxNumberOfSpells]; 
		
		for (int i = 0; i < numberOfSpells; i++)
		{
			// copy the old spell list into the new one
			newlist[i]= spells [i];
		}
		
		//after the previous speel list has been copied into the newlist array delete the old array and make spells point to the new array 
		delete [] spells; 
		spells = newlist;
	}
}
void Wizard::deleteSpell(string name){
	
	int temp=0;
	for (int i=0; i < numberOfSpells; i++)
	{
		if (spells[i].getName() == name )
		{
			temp =i; 
			break; 
		}
		else 
		{
			temp= -1;
		}
	}
	if (temp == -1 )
	{
		cout<<"that spell was not found in the list";
	}
	else
	{
		// add one to the position of j so that we select the value after the one we want to remove 
		// then make the previous value equal to the current value of j and replace them 
		for (int j = temp +1; j < numberOfSpells; j++)
		{ 
			spells[j-1]= spells [j];
		}
		
		numberOfSpells--; 
		numberOfLossedSpells++; 
	}
}
int Wizard::getNumberOfSpells() const{
	return numberOfSpells;	
}
void Wizard::setMaxNumberOfSpells(int m){
	maxNumberOfSpells =m; 
}
int Wizard::getMaxNumberOfSpells() const{
	return maxNumberOfSpells;
}
void Wizard::setAge(int a){
	age= a;
}
int Wizard::getAge() const{
	return age;
}
int Wizard::getNumberOfLossedSpells() const{
	return numberOfLossedSpells;
}
Spell& Wizard::getSpell(int index) const{
	return spells[index];
}
bool Wizard::getHasCompletedTraining () const{
	return hasCompletedTraining;
}
bool Wizard::getHasBeenSummoned () const{
	return hasBeenSummoned;
}


