#include <iostream>
#include <iomanip>
#include "Caesar.h"

Caesar::Caesar()
{
	//~ set shift to zero
	shift=0;
}
char Caesar::encodeChar(char c)
{

	//declare a constant variable to store the maximum Ascii value for characters.
	//declare a variable that will store the interger value of the ascii value of the character plus the shifte value.
	// this value has to be an integer because when you try to add numbers to a character after it has reached its limit it loops over into a -128 value intead of the expected 128 value,
	//~because of the characters data type range
	//if the overShift happens minus 126 from the variable this will send it back into range
	// then add 32 this will place it in the specifica range we are looking for
	int overShift=0;
	const int MAX =126;

	char newChar = '\0';

	/*
	shift = 94
	c = 130

	overShift = 130 + 94
			= 224 > 126
		overshift - 126 = 98
		overshit + 32 = 130
		overshift -1 = 129

	*/

	if (shift==0)
		setShift(0);

		overShift=(int)c+shift;

		if (overShift > MAX)
		{
			overShift -= 126;
			overShift += 32;
			newChar= overShift-1; //we -1 because we must take into account that we are using maximum and minum vlaues which do not start or end at zero
		}
		else
		{
			newChar=(int)c + shift;
		}

		//cout << c << " -> " << newChar << endl;
	return newChar;
}

char Caesar::decodeChar(char c)
{
	//the same applies to an underShift, if the variable becomes too small it will loop backwards instead of what we would expect
	//however for this example more worried about keeping the variable in the range we require
	//therefore the underShift variable is not really required but used to keep the code simple and easier to debugg
	//the only difference here is that we +126 and -32 to keep them in range
	int underShift=0;
	const int MIN =32;

	char newChar = '\0';

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

	//cout << c << " -> " << newChar << endl;
	return newChar;

}
void Caesar::setShift(int sh)
{
	bool test=false;
	// this is for the error handeling for the first time we need a shift variable , if the output is zero which is what is should be set to in the default constructor the error message please enter
	//a positive shift value will be displayed. this acts as the initial cout statement for enetering in the shift value
	//remember this is only being called becasue shift value was left out in main.cpp
	//and because we check if it was left out in the encode function in Substitution.cpp if it is it calls this setShift function with the value of zero and performs the error handeling
	//making it a while loop means that it will loop continuously untill a valid integer is put in but we rally only need to check it with the input file values for it to be ok
	while(test==false)
	{
		try
		{
			if (sh <= 0)
			{
				throw ("Please provide a positive shift value");
			}
			else if (sh > 94)
			{
				throw ("Maximum shift is 94 for ASCII, please try again");
			}
			else
			{
				test=true;
				shift=sh;
			}
		}catch (const char* msg)
		{
			cout<< msg << endl;
			cin>> sh;
		}
	}
}
