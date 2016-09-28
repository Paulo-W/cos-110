#ifndef ONETIMEPAD_H
#define ONETIMEPAD_H

#include <string>
#include "Caesar.h"

using namespace std;

class OneTimePad : protected Caesar 
{
	public:
		OneTimePad(long int);
		string encode(string);
		string decode(string);
		void setSeed(long int);
		char encodeChar(char);
		char decodeChar(char); 
		
	protected:
		long int seed;
};
#endif