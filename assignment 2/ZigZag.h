#ifndef ZIGZAG_H
#define ZIGZAG_H

#include <string>
#include "TranspositionCipher.h"

using namespace std;

class ZigZag : public TranspositionCipher
{
	public:
		string encode(string);
		string decode(string);
};
#endif