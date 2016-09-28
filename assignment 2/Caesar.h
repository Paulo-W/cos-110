#ifndef CAESAR_H
#define CAESAR_H

#include <string>
#include "SubstitutionCipher.h"

using namespace std;

class Caesar : public SubstitutionCipher 
{
	protected:
		int shift;
	public:
		Caesar ();
		void setShift (int);
		char encodeChar(char);
		char decodeChar(char);	
};
#endif