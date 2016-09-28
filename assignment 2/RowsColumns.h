#ifndef ROWSCOLUMNS_H
#define ROWSCOLUMNS_H

#include <string>
#include "TranspositionCipher.h"

using namespace std;

class RowsColumns : public TranspositionCipher
{
	public:
		string encode(string);
		string decode(string);
};
#endif