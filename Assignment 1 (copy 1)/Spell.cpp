#include <cstring>
#include <iomanip>
#include <iostream>
#include "Spell.h"

// Remove default args, they are alread defined in header
Spell::Spell(string name, int difficultyLevel, int skillLevel){
	// TODO: Set default values. this->name = name ...
	this ->name = name; 
	this ->difficultyLevel = difficultyLevel;
	this ->skillLevel= skillLevel;
	
}

Spell::Spell(const Spell& sp){
	// TODO:
	// 	Need to make a deep copy of the given spell
	// 	Assign the members of sp to this.
	
	// Spell = sp;
	name = sp.name;
	difficultyLevel= sp.difficultyLevel;
	skillLevel = sp.skillLevel;
	
	
}
Spell::~Spell(){

}
void Spell::setName(string n){
	name= n;
}
string Spell::getName() const{
	return name;
}
void Spell::setDifficultyLevel(int d){
	difficultyLevel = d;
}
int Spell::getDifficultyLevel() const{
	return difficultyLevel;
}
void Spell::setSkillLevel(int s){
	
	// TODO:
	// Set skill level if s > 0
	
	// if negative, we ignore, fool user
	
	if (s > 0 ){
		skillLevel = s;
	}
	
	//~ if (s <= 0){
		//~ return -1;
	//~ }
	//~ else {
		//~ skillLevel = s;
	//~ }
	
}
int Spell::getSkillLevel() const{
	return skillLevel; 
}

// the opperators that needed to change
Spell& Spell::operator=(const Spell &s){
	// makes a copy constructor so that the copy constructor can just asign one obect to another to make a deep copy
	name = s.name;
	difficultyLevel= s.difficultyLevel;
	skillLevel = s.skillLevel;
	
	return *this;
}
Spell& Spell::operator ++(){
	//  TODO: ++var, return this
	
	//simple increments the value and the returns the value 
	skillLevel++; 
	
	// Return this spell
	return *this;
}
Spell Spell::operator ++(int){
	// TODO: var++, return tmp spell before we increment 
	//first store the original value then return then increment the skill then return the original value 
	//the value sent through will be the same value sent back but the skills level will be incremented if called again
	
	Spell s(*this);
	skillLevel++; 
	
	// TODO: Return tmp spell without modified values
	//		By creating a copy before we modify this. we then return by val and not reference
	//		When return by val, it should make a copy.
	//		With ref it will point to a local variable that has gone out of scope
	
	return s;
	
}
Spell& Spell::operator --(){
	// TODO: call setSkillLevel(skillLevel - 1) ? It does what we need?
	
	//same as before however now a test must be made on wether or not the value is within the range of the skillLevel
	
	setSkillLevel(skillLevel -1);
	return *this;
}

Spell Spell::operator --(int){
	// TODO: Return tmp spell without modified values
	//		By creating a copy before we modify this. we then return by val and not reference
	//		When return by val, it should make a copy.
	//		With ref it will point to a local variable that has gone out of scope
	
	// this one was slightly more complicted 
	//first store the original value in a variable then decriment the skillLevel
	//call the setSkillLevel function to perform the test not on the original value but instead on the decrimented value 
	//because if 1 was passed in we will be 1 any way and as soon as the decrimented value 0 goes through bounds checking -1 will be returned 
	// this is why we did not send in the skillLevel and made a variable because the skillLevel will be incremented back to 1 if it is too small but if it was set to -1 we would to increment it twice
	Spell s(*this);
	
	if (skillLevel>0)
	{
		skillLevel--;
		return s;
	}
	else {
		return s;
	}
}
Spell& Spell::operator -=(int value){
	//take in an integer value and the object in as arguments
	// then subtract the skillLevel of the object (the spell) from the value and then istead of passing the value to the set function, beacus its easier to simply just check the value you have already
	//created to store the of the object minus the value, check to make sure that the value is still within the range of the spells
	
	// TODO: access skillLevel directly
	
	setSkillLevel(skillLevel - value);
	
		return *this;
	
}
ostream& operator  <<(ostream & spell, const Spell &s){
	//one just displays the values of the object
	// TODO: Access members directly. i.e name, skillLevel
	// TODO: Check formatting, specs require ...<< right << setw(x) <<...
	//		<iomanip>
	spell <<right<<setw(30)<< s.name;
	spell <<right<<setw(5)<< s.difficultyLevel;
	spell <<right<<setw(5)<< s.skillLevel;
	
	return spell;
}





























