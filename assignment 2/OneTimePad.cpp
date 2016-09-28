#include <cstdlib>
#include <string>
#include <iostream>
#include "OneTimePad.h"

OneTimePad::OneTimePad(long int s)
{
	seed = s;

}
string OneTimePad::encode(string e)
{
	int length= e.length();
	string newString;

	srand(seed);
	for (int i=0; i < length; i++)
	{
		newString+=encodeChar(e[i]);
	}
	return newString;
}
string OneTimePad::decode(string d)
{
	int length= d.length();
	string newString;

	srand(seed);
	for (int i=0; i < length; i++)
	{
		newString+=decodeChar(d[i]);
	}
	return newString;
}

char OneTimePad::encodeChar(char c)
{
	char newChar = '\0';
	const int MAX=126, MAX_RN=94, MIN_RN=1;
	int shift=0;
	shift= (rand() % (MAX_RN-MIN_RN+1)) + MIN_RN;


	int overShift=0;

	overShift=(int)c+shift;
	if (overShift > MAX)
	{
		overShift -= 126;
		overShift += 32;
		newChar= overShift-1;
	}
	else
	{
		newChar=(int)c + shift;
	}

	return newChar;

}
char OneTimePad::decodeChar(char c)
{
	char newChar = '\0';
	const int MIN=32, MAX_RN=94, MIN_RN=1;
	shift= (rand() % (MAX_RN-MIN_RN+1)) + MIN_RN;
	int underShift=0;

	underShift= int(c)-shift;
	if (underShift< MIN)
	{
		underShift += 126;
		underShift -= 32;
		newChar=underShift +1;// same as before
	}
	else
	{
		newChar=(int)c- shift;

	}



	return newChar;
}

void OneTimePad::setSeed(long int s)
{
	seed =s;
}
