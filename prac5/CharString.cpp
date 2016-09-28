#include "CharString.h"
#include <iostream>
#include <string>
#include <cstring>

CharString::CharString(){
	int i=0;
	while (characters[i] !='\n')
	{
		numChars++;
		i++;
	}
	characters = new char [numChars];
}
CharString::CharString(const char* ch, int size){
	//constructor with parameters sets the array to what has bee assed through
	//when making a new data type always check what the data type of the pointer isdeclared as in the header
	//TODO initialized numChars with size and the dynamically allocated array with variable being passed through 
	characters = new char[size];
	for (int i =0; i< size; i++)
	{
		characters[i] = ch[i];
		if (characters[i] != '\n')
		{
			numChars++;
		}
		
	}
		
	
}
CharString::CharString(const CharString& s){
	// the copy constructor 
	numChars = s.numChars;
	characters = new char[numChars];
	
	for (int i =0; i< numChars; i++)
	{
		characters[i] = s.characters[i];
	}
	// this is becoming easy 
}	

CharString::~CharString(){
	// remeber to set the pointer to null as well
	delete [] characters;
	characters= 0;

}

// overloaded operators
// the assignment operator
const CharString CharString::operator= (const CharString &s){
	numChars = s.numChars;
	characters = new char[numChars];
	
	for (int i =0; i< numChars; i++)
	{
		characters[i] = s.characters[i];
	}
	
}

CharString CharString::operator+ (const CharString &s){
	// create a new object to store the length as we as the size of the strings added together
	//throw the exception if the string is empty
	try {
		if (s[0] !=' ')
		{
			int Chars = strlen(characters);
			int Chars2 = strlen(s.characters);
			int numChars = Chars + Chars2;
			char newArray [numChars];
			
			int k=0;
			for (int i=0; i < Chars; i++, k++)
			{
				newArray[k]= characters[i];
			}
			for (int i=0; i < Chars2; i++, k++)
			{
				newArray[k]= s.characters[i];
			}
			
			
			CharString Array= new CharString[numChars];
			Array.characters=newArray;
			
			return Array;
		}
		else if (s[0] ==' ')
		{
			throw Exception("The string is empty");
		}
	}
	catch(Exception e)
	{
		e.what();
	}
		
	
}
void CharString::operator+= (const CharString &s){
	try{	
		if (s[0] !=' ')
		{
			numChars += s.numChars;
			int Chars = numChars;
			char* newArray= new char [numChars];
			int k=0;
				for (int i=0; i < Chars; i++, k++)
				{
					newArray[k]= characters[i];
				}
				for (int i=0; i < strlen(s.characters); i++, k++)
				{
					newArray[k]= s.characters[i];
				}
			//~ newArray= characters + s.characters; 
				delete [] characters;
				characters= newArray;
		}
		else
		{
			throw Exception("The string is empty");
		}
	}	
	catch(Exception e)
	{
		e.what();
	}
		
}
CharString  CharString::operator- (const char &c){
	// throw an exeption if the string sent through is empty
	// else do some math 
	try {
		if (characters[0]== ' ')
		{
			throw Exception("The string is empty");
		}
		else 
		{
			int backArray= numChars;
			for (int i =0; i < numChars; i++)
			{
				if (c==characters[i])
				{	
					//set the counter variable to 1 more than the found character 
					//so that you can then shift the array over and delete the elements if it was found by the if statement
					//do this by saying counter variable -1 is equal to the counter vaiable that was set to postion of found character +1
					for (int j =i+1; j < numChars; j++)
					{
						characters[j-1]= characters[j];
						characters[backArray]=' ';
					}
					backArray--;
				}
			}
			if (characters[0]==' ')
			{
				throw Exception("The resultis an empty string!");
			}
			else 
			{
				return characters;
			}
		}
	}
	catch(Exception e) {
		e.what();
	}
}
void CharString::operator-= (const char &s){
	try {
		if (characters[0]== ' ')
		{
			throw Exception("The string is empty");
		}
		else
		{			
			int backArray= numChars;
			for (int i=0; i < numChars; i++)
				{
				if (s==characters[i])
					{	
						//set the counter variable to 1 more than the found character 
						//so that you can then shift the array over and delete the elements if it was found by the if statement
						//do this by saying counter variable -1 is equal to the counter vaiable that was set to postion of found character +1
						for (int j =i+1; j < numChars; j++)
							{
								characters[j-1]= characters[j];
								characters[backArray]=' ';
							}
						backArray--;
					}
			}
			if (characters[0]==' ')
			{
				throw Exception("The resultis an empty string!");
			}
		}
	}
	catch(Exception e)
	{
		e.what();
	}	
}
CharString CharString::operator* (const CharString &s){
	//the string must appear one after the other so 
	// create a new object so that we can add the new individual characters from each string one after the other to the new objects characer string 
	//then call the length function to set the length of the new object
	// if the strings are not equal in length throw an exception this means I only need to worry about one of the characters length and then double it to get the toal length of the string, 
	//I set the the length inside a variable so that i dont need to call the function every time the loopiteraters 
	try{
		if (strlen(characters) != strlen(s.characters))
		{
			throw Exception("Strings are unequal lengths!");
		}
		
		else if (strlen(characters) == strlen(s.characters))
		{
			int length= strlen(characters);
			const int SIZE=length *2;
			char* newArray= new char [numChars];
			//cant think of any other way to do this cause im lazy and running out of time but i checked this works so thank f***
			//make a counter variable, another variable equal  to 1 as well as another counter variable that you will increment twice instaed of once
			//increment the one you stored he value one in twice as well this is because
			// the final array has one character from the first array then one of the second and only then the next element from the first array
			//its kind of like an even odd thing but I couldnt figure out a % way of doing this so i left it as is
			int i,j,k;
			for (i=0, j=1, k=0; i< length; i++, j+=2,k+=2)
			{
				if (i==0)
				{
					newArray[i]=characters[i];
					newArray[j]=s.characters[i];
				}
				else
				{
					newArray[k]= characters[i];
					newArray[j]= s.characters[i];
				}
			}
			return newArray;
		}
	}
	catch(Exception e) {
		e.what(); 
	}	
}
void CharString::operator*= (const CharString &s){
	try{
		if (strlen(characters) != strlen(s.characters))
		{
			throw Exception("Strings are unequal lengths!");
		}
		
		else if (strlen(characters) == strlen(s.characters))
		{
			
			int length= strlen(characters);
			const int SIZE=length *2;
			char array [SIZE];
			//cant think of any other way to do this cause im lazy and running out of time but i checked this works so thank f***
			//make a counter variable, another equal  to 1 as well as another counter variable that you will increment twice instaed of once
			//increment the one initialed to one twice as well this is because
			// you want to storre the element of the first array two spaces further than the one it came before this is because in between them you are storing the element in the other array
			//its kind of like an even odd thing but ic couldnt figure out a % way of doing this so i left it as is
			int i,j,k;
			for (i=0, j=1, k=0; i< length; i++, j+=2,k+=2)
			{
				if (i==0)
				{
					array[i]=characters[i];
					array[j]=s.characters[i];
				}
				else
				{
					array[k]= characters[i];
					array[j]= s.characters[i];
				}
			}
			
			// once this is done create a new dynamically allocated array with with the values of the new one one and then delete the old one and update it with new
			char* newlist= new char [SIZE];
			for (int i=0; i < SIZE; i++)
				{
					newlist[i] = characters[i];
				}
			delete [] characters;
			characters= newlist;
		}
	}
	catch(Exception e) {
		e.what(); 
	}	
	
}
CharString CharString::operator/ (const CharString &s){
	try{
		if (characters[0]==' ' || s[0]==' ')
		{
			throw Exception("The string is empty");
		}
		else if (characters[0]!=' ' && s[0]!=' ')
		{
			bool match=false;
			
			// loop the arrays to see if the elemens match, if they do set the bool match to true (no exception will be thrown)
			// if they match set the element in that array to blank
			for (int array1=0; array1< numChars; array1++)
			{
				for (int array2=0; array2<s.numChars; array2++)
				{
					if (characters[array1]==s.characters[array2])
					{
						match= true;
						characters[array1]= ' ';
					}
				}
			}
			
			//loop through the array looking for any elements that are blank if there are elments that are blank ignore them
			//if the elements are not blank they will be shiftd up to the next available sapce in the array using the countr vaiable this should only get incremented if you find an element that is not a blank
			int counter=0; 
			char array [numChars];
				for (int i=0; i< numChars; i++)
				{
					if(characters[i]!= ' ')
					{
						array[counter]= characters[i];
						counter++;
					}
				}
			//create a new Charstring witht he correct size of the array that now has no characters that are the same witht the ones passed through
			//store the elements in the old array into the new array then delete the old array so that you can assign the new array into the old array making the old one new 
			char* newArray= new char [counter];
			for (int i=0; i < counter; i++)
				{
					newArray[i] = array[i];
				}
			
			if (match==false)
			{
				throw Exception("No character found!");
			}
			if (newArray[0]==' ')
			{
				throw Exception("The resultis an empty string!");
			}
			else {
				return newArray;
			}
		}
	}
	catch(Exception e) {
		e.what(); 
	}
}	

void CharString::operator/= (const CharString &s){
	try{
		if (characters[0]==' ' || s[0]==' ')
		{
			throw Exception("The string is empty");
		}
		else if (characters[0]!=' ' && s[0]!=' ')
		{
			bool match=false;
			for (int array1=0; array1< numChars; array1++)
			{
				for (int array2=0; array2<s.numChars; array2++)
				{
					if (characters[array1]==s.characters[array2])
					{
						match= true;
						characters[array1]= ' ';
					}
				}
			}
			int counter=0; 
			char array [numChars];
				for (int i=0; i< numChars; i++)
				{
					if(characters[i]!= ' ')
					{
						array[counter]= characters[i];
						counter++;
					}
				}
			delete[] characters;
			for (int i=0; i < counter; i++)
			{
				characters[i] = array[i];
			}
			
			if (match==false)
			{
				throw Exception("No character found!");
			}
			if (characters[0]==' ')
			{
				throw Exception("The resultis an empty string!");
			}
		}
	}
	catch(Exception e) {
		e.what(); 
	}
	
}
char& CharString::operator[](int i) const{
	try{
		if (i>numChars|| i<0)
		{
			throw Exception("Index out of bounds!");
		}
		else
		{
			return characters[i];
		}
	}
	catch (Exception e){
		e.what(); 
	}
}


const int  CharString::length() const{
	int size=0;
	size= strlen(characters);
	return size;
}






















