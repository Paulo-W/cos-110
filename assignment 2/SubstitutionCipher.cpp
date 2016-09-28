#include <string>
#include <iostream>
#include "SubstitutionCipher.h"

string SubstitutionCipher::encode(string s)
{
		int length= s.length();
		string newString = "";

		for (int i=0; i < length; i++)
		{
			// = -> +=
			newString+=encodeChar(s[i]);
		}
	return newString;
}
string SubstitutionCipher::decode(string s)
{
	int length= s.length();
	string newString = "";

	for (int i=0; i < length; i++)
	{
		// = -> +=
		newString+=decodeChar(s[i]);
	}

	return newString;
}
