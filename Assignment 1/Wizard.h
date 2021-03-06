/* 
 * Class Wizard
 */

#ifndef WIZARD_H
#define	WIZARD_H

#include "Spell.h"

class Wizard{
    
private:
    Spell* spells;
    int numberOfSpells;
    int maxNumberOfSpells;
    bool hasBeenSummoned;
    int age;
    int numberOfLossedSpells;
    bool hasCompletedTraining;
public:
    Wizard();
    Wizard(const Wizard& w);
    ~Wizard();
    void addSpell(const Spell& s);
    void deleteSpell(string name);
    int getNumberOfSpells() const;
    void setMaxNumberOfSpells(int m);
    int getMaxNumberOfSpells() const;
    void setAge(int a); 
    int getAge() const;
    int getNumberOfLossedSpells() const;
    Spell& getSpell(int index) const;
	bool getHasCompletedTraining ( ) const;
	bool getHasBeenSummoned ( ) const ;
	bool operator>(const Wizard &w);
	bool operator<(const Wizard &w);
	Wizard& operator +(const Spell &s);
	Wizard& operator -(const string s);

};

#endif	/* WIZARD_H */