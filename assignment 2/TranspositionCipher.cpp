#include "TranspositionCipher.h"
#include <string>
#include <math.h>

char** TranspositionCipher::createMatrix(int size)
{
	// create a 2d array and set the pinters to null
	char *** array;
	array = new char ** [size];
		for (int i=0; i <size; i++)
		{
			array[i]= new char *[size];
			for (int j=0;j < size; j++)
			{
				*(*(array +i)+j) = NULL;
			}
		}

	return *array;
}
void TranspositionCipher::deleteMatrix(char** array, int size)
{
	//~ delete the element s in the 2d array stored on the heap
	for (int i =0; i<size; i++ )
	{
		delete [] array [i];
	}
	delete [] array;
}
void TranspositionCipher::fillMatrix(char ** array, int size , string s)
{
	//calculate the total number of elements in the 2d array by multiply the sides by each other
	//then get the length of the strig this will determine how many extra elements need to be added to the array and will allow us to set them tothe lank spaces
	//create a new array with the size of the total amount of elements in the 2d array.
	//set the extra elements to blank then
	int square = size * size;
	int length = s.length();
	char newArray [square];

	for (int i=0; i < square; i++)
	{
		if (i > length)
		{
			newArray[i]= ' ';
		}
		else
		{
			newArray[i]= s[i];
		}
	}

	int counter=0;
	for (int i=0; i< size; i++)
	{
		for (int j=0; j < size; j++ )
		{
			char* ptr= new char (newArray[counter]);
			counter++;
			*(*(array +i)+j)= *ptr;
		}
	}

}
int TranspositionCipher::calculateSide(int size)
{
	//if the squar root of the parameter is equal to 0 a perfect square has been passed though and there is exactly enough space for the square integer
	//but if the square root is equal to a decimal number then you can not have half a square so you must increment the size by one adding a new coloum and row to the square
	//and there will be spaces at the end in this case
	double root=size;

	root = sqrt (root);
	size = root;
	root -= size;

	if (root == 0)
	{
		return size;
	}
	else if (root >0)
	{
		return ++size;
	}
}
