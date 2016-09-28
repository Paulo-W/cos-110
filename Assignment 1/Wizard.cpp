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
	
	spells = new Spell[maxNumberOfSpells];
	
	for (int i=0; i < maxNumberOfSpells ; i++)
	{
		spells[i]= Spell(w.spells[i]); 
	}
	
}

Wizard::~Wizard(){// the destructor 
	delete [] spells;
}

void Wizard::addSpell(const Spell& s){
	
	if (numberOfSpells < maxNumberOfSpells){
		//~ if (numberOfSpells <= maxNumberOfSpells){
		//~ spells[numberOfSpells++]= s; 
		for (int i= 0 ; i < maxNumberOfSpells; i++)
		{
			if (spells[i].getName() ==""){
				spells[i]= s;
				break;
			}
		}
	}
	else {
		// make the new spell list 5 cells larger than the previous one 
		maxNumberOfSpells ++;
		Spell* newlist= new Spell [maxNumberOfSpells]; 
		
		for (int i = 0; i < maxNumberOfSpells - 1; i++)
		{
			// copy the old spell list into the new one
			newlist[i]= spells [i];
		}
		newlist[maxNumberOfSpells-1] = s;
		
		//after the previous speel list has been copied into the newlist array delete the old array and make spells point to the new array 
		delete [] spells; 
		spells = newlist;
	}
	numberOfSpells++;
}
void Wizard::deleteSpell(string s){
	
	for (int i=0; i < maxNumberOfSpells; i++)
	{
		if (spells[i].getName() == s)
		{
			spells[i]= Spell("");
			numberOfLossedSpells++;
			numberOfSpells--;
		}
		
	}
}
int Wizard::getNumberOfSpells() const{
	return numberOfSpells;	
}
void Wizard::setMaxNumberOfSpells(int m){
	Spell* array = new Spell [m];
	
	
	if (maxNumberOfSpells < m){
		for (int i =0; i < maxNumberOfSpells ; i++)
		{
			array[i] = spells[i];
		}
		for (int i = maxNumberOfSpells; i < m ; i++){
			array[i] = Spell("");
		}
	}
	else if (maxNumberOfSpells > m){
			for (int i =0; i < m; i++)
		{
			array[i] = spells[i];
		}
	}
	
	delete [] spells;
	spells = array;
	maxNumberOfSpells= m;
	
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
bool Wizard::getHasCompletedTraining ( ) const{
	return hasCompletedTraining;
}

bool Wizard::getHasBeenSummoned ( ) const{
	return hasBeenSummoned;
}



//operators we need to implement
bool Wizard::operator>(const Wizard &w){
	
	
	//to look for the number of spells in the second wizard make a variable that will look at the wizards number of spells so that he does not use the maxNumber of spells from the second wizzard
	//int arr2 =w.numberOfSpells;
	// make 2 counter variables to determine which wizzard will end up having more skill points and to detemine which wizard will be greater than the other
	int wiz1Skills=0;
	int wiz2Skills=0;
	
	// firstly run through every element inside the first wizards array and then run throuh every element inside the second elements array to determine if the spells names match
	// then compare spells skill levels to determine which one is greater than the other
	// do not just make an else becuase you have to look out for what will happen when they are both equal
	
	for (int i=0; i < numberOfSpells; i++)
	{
		for (int j=0; j < w.numberOfSpells; j++){
			if (spells[i].getName() == w.spells[j].getName()){
				if (spells[i].getSkillLevel() > w.spells[j].getSkillLevel())
				{
					wiz1Skills++;
				}
				else if (spells[i].getSkillLevel() < w.spells[j].getSkillLevel())
				{
					wiz2Skills++; 
				}
			}
		}
	}
	// finally using the counter variables send back true or false depending o which one is greater than the other
	// if wiz 1 is greater than wiz 2 return true
	
	if (wiz1Skills > wiz2Skills){
		return true;
	}
	else{
		return false;
	}
}

bool Wizard::operator<(const Wizard &w){
	
	int arr2 =w.numberOfSpells; 
	int wiz1Skills=0;
	int wiz2Skills=0;
	
	// the same as above just switch operands
	
	for (int i=0; i < numberOfSpells; i++)
	{
		for (int j=0; j < w.numberOfSpells; j++){
			if (spells[i].getName() == w.spells[j].getName()){
				
				// also because bitchfork is bitchfork and wants code like this when you swithch operands like this remeber you have to switch wiz 2 and wiz 1 as well
				if (spells[i].getSkillLevel() < w.spells[j].getSkillLevel())
				{
					wiz2Skills++; 
				}
				else if (spells[i].getSkillLevel() > w.spells[j].getSkillLevel())
				{
					wiz1Skills++;
				}
			}
		}
	}
	
	if (wiz1Skills < wiz2Skills){
		return true;
	}
	else{
		return false;
	}
}
Wizard& Wizard::operator +(const Spell &s){
	addSpell(s);
	return (*this);	
}
Wizard& Wizard::operator -(const string s){
	deleteSpell(s);
	return (*this);
}



























