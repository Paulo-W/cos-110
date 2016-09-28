#include <string>
#ifndef EXCEPTION_H
#define EXCEPTION_H
using namespace std;

class Exception
{
	private:
		string reason;
	
	public:
		Exception(string problem);
		string what() const;
};
#endif

