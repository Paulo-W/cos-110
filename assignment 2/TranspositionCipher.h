#ifndef TRANSPOSITIONCIPHER_H
#define TRANSPOSITIONCIPHER_H

#include <string>
#include "Cipher.h"

using namespace std;

class TranspositionCipher : public Cipher
{
	protected:
		char ** createMatrix(int);
		void deleteMatrix(char **, int);
		void fillMatrix(char **, int, string);
		int calculateSide(int);
};
#endif