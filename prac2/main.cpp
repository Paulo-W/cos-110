#include <iostream>
#include <string>
#include "Adventurer.h"


using namespace std;
/*
 * Add comments here
 */

int main() {
    //add code here to test your class

	Adventurer traveller;
	string name, ITname;
	double weight,maxWeight,maxItems;
	bool pickup=true;

    cout<<"Enter your name: ";
    cin>> name;

    cout<<"How many kilograms can you pick up: ";
    cin>> maxWeight;

    cout<<"How many objects can you carry: ";
    cin>> maxItems;

    traveller.setName(name);
    traveller.setMaxCarryWeight(maxWeight);
    traveller.setMaxNumberOfItems(maxItems);
   
    do 
    {
			
			cout <<"you find an object how much does it way: ";
			cin >> weight;
			cout <<"what item do you pick up: ";
			cin >> ITname;
			pickup = traveller.pickUpItem(ITname,weight);
	    
			
    }while (weight != -1 && pickup==true);
    
cout << "Your name is "<< traveller.getName()<<" you can carry "<<traveller.getMaxNumberOfItems()<< " items, and you can carry "<< traveller.getMaxCarryWeight();
 cout <<"kg"<<endl;

    return 0;
}