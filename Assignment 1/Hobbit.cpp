#include "Hobbit.h"

Hobbit::Hobbit(){
}

Hobbit::~Hobbit()
{
}

void Hobbit::setName(string n){
	name =n;
}
string Hobbit::getName() const{
	return name; 
}
