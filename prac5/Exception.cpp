#include <string>
#include "Exception.h"

Exception::Exception(string problem){
	this->reason= problem; 
	
}
string Exception::what() const{
	return reason; 
}
