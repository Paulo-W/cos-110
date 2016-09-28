#ifndef CIPHER_H
#define CIPHER_H

#include <string>
using namespace std;

class Cipher
{
	public:
		virtual string encode(string)=0;
		virtual string decode(string)=0;
};
#endif