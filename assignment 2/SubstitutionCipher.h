#ifndef SUBSTITUTIONCIPHER_H
#define SUBSTITUTIONCIPHER_H

#include <string>
#include "Cipher.h"


using namespace std;

class SubstitutionCipher : public Cipher
{
	public:
		virtual char encodeChar(char)=0;
		virtual char decodeChar(char)=0; 
		string encode(string);
		string decode(string);
};
#endif