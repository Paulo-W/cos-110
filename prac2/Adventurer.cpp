#include <iostream>
#include <string>
#include <cstdlib>
#include "Adventurer.h"

//Implement or define your class here
int Adventurer::numberOfAdventurers=0;

Adventurer::Adventurer()
 {
 	numberOfAdventurers++;
 	maxCarryWeight = 150;
 	currentCarryWeight = 0;
 	currentNumberOfItems= 0;
 	maxNumberOfItems = 8;
	name = "Steeve";
 	health = 100;
	 
	 
	 //items [index][0] = pointer to item string 
	 //items [index][1] = pointer to item weight 
	 //***items -> **index[] -> *item [0-1] -> string 
	 
	 //items [0] = items *(items +i)
	 //items [1][j] = *(*(items +i) +j)
	 // **(*(items +i ) +j)= string at value ij 
	 
	 
	 items = new string **[maxNumberOfItems];
	 
	 for (int i =0; i < maxNumberOfItems; i ++ )
	{
		items[i]= new string *[2];  // this syntax stores the string values on the heap and creates two colums for our two arrarys // this is a pointr that points to an array on the heap
		*(*(items +i)+0) = NULL;
		*(*(items +i)+1)= NULL;
	}	

 }; //default constructor

 Adventurer::Adventurer(const Adventurer& a)
{   
	name = a.name;
	maxCarryWeight= a.maxCarryWeight;
	currentCarryWeight = a.currentCarryWeight;
	currentNumberOfItems = a.currentNumberOfItems;
	maxNumberOfItems = a.maxNumberOfItems;
	health = a.health;
	numberOfAdventurers++;
	
	 items = new string **[maxNumberOfItems];
	 
	 for (int i =0; i < maxNumberOfItems; i ++ )
{
	items[i]= new string *[2];  // this syntax stores the string values on the heap and creates two colums for our two arrarys // this is a pointr that points to an array on the heap
	
	*(*(items +i)+0) = NULL;
	*(*(items +i)+1)= NULL;
}	
	
	
	
};  //copy constructor
Adventurer::~Adventurer()
{
	delete [] items;
	 for (int i =0; i < maxNumberOfItems; i ++ )
	{
		if (*(*(items +i)+0) != NULL)
		{
			delete *(*(items +i)+0); 
		}
		if (*(*(items +i)+1) != NULL)
		{
			delete *(*(items +i)+0); 
		}
	}
};
bool Adventurer::pickUpItem(string it, double weight)
{
	bool test = true;
	int size;
	double totalWeight =0;
	
	currentCarryWeight += weight;
	
	totalWeight += currentCarryWeight +weight;
	
	string stringW = to_string(weight);
	size =stringW.find('.');
	stringW = stringW.substr(0, size);

	if (totalWeight < maxCarryWeight && currentNumberOfItems < maxNumberOfItems)
	{
		 //***items -> **index[] -> *item [0-1] -> string 
		// * -> the index 
		// ** -> item attribute 
		// ***-> the value
		
		string* ptr1 = new string (it);// storing new pointer on th loop that you can add to the index array pointer variables
		string* ptr2 = new string (stringW);
		
		//index 0 = itemArray because they are of the same type
		
		
		*(*(items +currentNumberOfItems)+0) = ptr1;
		*(*(items +currentNumberOfItems )+1)=  ptr2;// after this we need update the current number of items the array is pointing to 
		
		currentNumberOfItems++;
	}
	else
	{
		test = false;
	}
	
	return test;
};
bool Adventurer::dropItem(string it)
{
	
	
}
bool Adventurer::dropItem(int index)
{

};
void Adventurer::setName(string n)
{
	name =n;
};
string Adventurer::getName() const
{
	return name;
};
void Adventurer::setMaxCarryWeight(double w)
{
	maxCarryWeight =w;
};
double Adventurer::getMaxCarryWeight() const
{
	return maxCarryWeight;
};
void Adventurer::setCurrentCarryWeight(double w)
{
	currentCarryWeight = w;
};
double Adventurer::getCurrentCarryWeight() const
{
	return currentCarryWeight;
};    
void Adventurer::setMaxNumberOfItems(int n)
{
	
	// Move old index array to new one
	// arrayNew[0] = arrayOld[0]
	// Initialize empty items if we are increasing (Same as in contructor)
	// and add them to the new array at the end
	
	maxNumberOfItems = n;
};
int Adventurer::getMaxNumberOfItems() const
{
	return maxNumberOfItems;
};
void Adventurer::setCurrentNumberOfItems(int n)
{
	currentNumberOfItems =n;
};
int Adventurer::getCurrentNumberOfItems() const
{
	return currentNumberOfItems;
};
int Adventurer::getNumberOfAdventurers() const
{
	return numberOfAdventurers;
};
void Adventurer::setHealth(double h)
{
	health = h;
};
double Adventurer::getHealth() const
{
	return health;
};
string** Adventurer::getItem(int index) const
{
		return *items;
};
Adventurer& Adventurer::operator = (const Adventurer& a)
{
	setName(a.getName());
	setMaxCarryWeight (a.getMaxCarryWeight());
	setCurrentCarryWeight  (a.getCurrentCarryWeight());
	setCurrentNumberOfItems  (a.getCurrentNumberOfItems());
	setMaxNumberOfItems  (a.getMaxNumberOfItems());
	setHealth  (a.getHealth());
	numberOfAdventurers++;
	
	 items = new string **[maxNumberOfItems];
	
	 
	 for (int i =0; i < maxNumberOfItems; i ++ )
{
	items[i]= new string *[2];  // this syntax stores the string values on the heap and creates two colums for our two arrarys // this is a pointr that points to an array on the heap
	
	*(*(items +i)+0) =new string [i];
	*(*(items +i)+1)= new string [i];
}	
};