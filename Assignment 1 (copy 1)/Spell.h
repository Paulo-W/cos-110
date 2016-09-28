/* 
 * Class Spell
 */

#ifndef SPELL_H
#define SPELL_H

#include <string>
#include <iostream>
using namespace std;

class Spell {
private:
    string name;
    int difficultyLevel;
    int skillLevel;
public:
    Spell(string name="Unknown", int difficultyLevel=10, int skillLevel = 5);
    Spell(const Spell& sp);
    ~Spell();
    void setName(string n);
    string getName() const;
    void setDifficultyLevel(int d);
    int getDifficultyLevel() const;
    void setSkillLevel(int s);
    int getSkillLevel() const;
	Spell& operator=(const Spell &s);
	Spell& operator ++();
	Spell operator ++(int);
	Spell& operator --();
	Spell operator --(int);
	Spell& operator -=(int value);
	// Declare as friend, ostream needs access to our privates 
	friend ostream& operator  <<(ostream & spell, const Spell &s);
};

#endif	/* SPELL_H */