#include <iostream>
#include <cstdlib>
#include <assert.h>

#include "Adventurer.h"

using namespace std;

/*
void printDebug(string name, string **ptr, int offsetCount)
{
    cout << "------ POINTER DEBUG (**string)------\n";

    for (int i = 0; i < offsetCount; i++)
    {
        cout << i << ":\n";

        cout << "(" << name << " + " << i << ") = " << ptr + i<< endl;
        cout << "*(" << name << " + " << i << ") = " << *(ptr + i) << endl;
        cout << "**(" << name << " + " << i << ") = " << **(ptr + i) << endl;
    }

    cout << "-------------------------------------\n";
}

int testAddItem()
{
    int fails = 0;

    cout << "TEST: pickUpItem(), getItem() ... \n";

    cout << "- setMaxNumberOfItems() ...\n";

    Adventurer jane;
    jane.setName("Jane");

    jane.setMaxNumberOfItems(5);

    for (int i = 0; i < 5; i++)
    {
        cout << "Pickup: FULL_1_" + to_string(i) << endl;

        if (jane.pickUpItem("FULL_1_" + to_string(i), 1) == false)
        {
            cout << "\tFAIL: Failed to pickup all items.\n";
        }
    }

    jane.setMaxNumberOfItems(15);
    for (int i = 0; i < 5; i++)
    {
        string **item = jane.getItem(i);

        cout << **(item + 0) << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "Pickup: FULL_2_" + to_string(i) << endl;
        if (jane.pickUpItem("FULL_2_" + to_string(i), 1) == false)
        {
            cout << "\tFAIL: Failed to pickup all items.\n";
        }
    }

    for (int i = 0; i < jane.getMaxNumberOfItems(); i++)
    {
        string **item = jane.getItem(i);

        cout << **(item + 0) << endl;
    }

    jane.setMaxNumberOfItems(3);
    for (int i = 0; i < jane.getMaxNumberOfItems(); i++)
    {
        string **item = jane.getItem(i);

        cout << "Resize: " << **(item + 0) << endl;
    }

    cout << "- Pickup and get single item ...\n";
    string desc = "Shovel";
    double weight = 4;

    Adventurer bob;
    bob.setName("Bob");

    bob.setMaxCarryWeight(5);
    bob.setMaxNumberOfItems(5);

    bob.setCurrentCarryWeight(0);
    bob.setCurrentNumberOfItems(0);

    bool pickup = bob.pickUpItem(desc, weight);

    if (pickup)
    {
        // **item -> *index[]
        //                  (0) -> name
        //                  (1) -> weight

        string **item = bob.getItem(0);

        if (**(item + 0) != desc)
        {
            cout << "\tFAIL: " << *(item + 0) << " != " << desc << "\n";
            fails++;
        }

        if (**(item + 1) != to_string(weight))
        {
            cout << "\tFAIL: " << *(item + 1) << " != " << weight << "\n";
            fails++;
        }
    }
    else
    {
        cout << "\tFAIL: Unable to pickup item.\n";
        fails++;
    }

    cout << "- Pickup when inventory full ...\n";
    Adventurer john;
    john.setName("John");

    john.setMaxCarryWeight(50);
    john.setMaxNumberOfItems(15);
    john.setCurrentCarryWeight(0);
    john.setCurrentNumberOfItems(0);

    for (int i = 0; i < john.getMaxNumberOfItems(); i++)
    {
        cout << i << endl;
        if (john.pickUpItem("FULL", 1) == false)
        {
            cout << "\tFAIL: Failed to pickup all items.\n";
        }
    }

    if (john.pickUpItem("FULL", 1) == true)
    {
        cout << "\tFAIL: Picked up an items when inventory full!\n";
    }

    return fails;

}

int testName()
{
    int fails = 0;

    cout << "TEST: setName(), getName() ...\n";
    string name = "John Miller";

    Adventurer bob;
    bob.setName(name);

    if (bob.getName() != name)
    {
        cout << "\tFAIL: ";
        cout << name << " != " << bob.getName() << "\n";
        fails++;
    }

    return fails;
}

bool runTests()
{

    int fails = 0;

    fails += testName();
    fails += testAddItem();

    cout << "Tests failed: " << fails << endl;

    if (fails == 0)
        return true;
    else
        return false;
}

*/

bool pickupItemIncrementsCurrentNumberOfItems()
{
    Adventurer jane;
    jane.setMaxNumberOfItems(10);
    jane.setMaxCarryWeight(100);
    jane.setCurrentNumberOfItems(0);

    assert(0==jane.getCurrentNumberOfItems());

    // Fill inventory
    for (int i = 0; i < jane.getMaxNumberOfItems(); i++)
    {
        assert(true==jane.pickUpItem("item_" + to_string(i), 2));
    }

    assert(10==jane.getCurrentNumberOfItems());

    return true;
}

bool pickupItemIncrementsCurrentCaryWeight()
{
    Adventurer jane;
    jane.setMaxNumberOfItems(10);
    jane.setMaxCarryWeight(100);
    jane.setCurrentNumberOfItems(0);

    assert(0==jane.getCurrentNumberOfItems());

    // Fill inventory
    for (int i = 0; i < jane.getMaxNumberOfItems(); i++)
    {
        assert(true==jane.pickUpItem("item_" + to_string(i), 2));
    }

    assert(20==jane.getCurrentCarryWeight());

    return true;
}

bool pickupItemReturnsFalseIfMaxWeightReached(){
    Adventurer jane;
    jane.setMaxNumberOfItems(20);
    jane.setMaxCarryWeight(20);

    // Add max weight
    for (int i = 0; i < 10; i++)
    {
        assert(true==jane.pickUpItem("Weight_" + to_string(i), 2));
    }

    // Try to add another, should return false
    assert(false==jane.pickUpItem("Weight_", 2.74));

    return true;
}

bool pickupItemReturnsFalseIfMaxItemsReached(){
    Adventurer jane;
    jane.setMaxNumberOfItems(5);
    jane.setMaxCarryWeight(20);

    // Add 5 items
    for (int i = 0; i < jane.getMaxNumberOfItems(); i++)
    {
        assert(true==jane.pickUpItem("FULL_1_" + to_string(i), 1));
    }

    // Try to add another, should return false
    assert(false==jane.pickUpItem("Inventory Full", 1));

    return true;
}

bool pickupItemAddsItemAfterIncreasingMaxItems(){
    Adventurer jane;
    jane.setMaxNumberOfItems(10);
    jane.setMaxCarryWeight(20);

    // Fill inventory
    for (int i = 0; i < jane.getMaxNumberOfItems(); i++)
    {
        assert(true==jane.pickUpItem("Item_" + to_string(i), 1));
    }

    assert(10==jane.getCurrentNumberOfItems());

    // Increase inventory size
    jane.setMaxNumberOfItems(15);

    // Fill inventory again
    for (int i = 0; i < 5; i++)
    {
        assert(true==jane.pickUpItem("Item_" + to_string(i), 1));
    }

    assert(15==jane.getCurrentNumberOfItems());

    return true;
}

bool pickupItemAddsItemAfterIncreasingMaxWeight(){
    Adventurer jane;
    jane.setMaxNumberOfItems(10);
    jane.setMaxCarryWeight(5);

    // Fill inventory to max weight
    for (int i = 0; i < 5; i++)
    {
        assert(true==jane.pickUpItem("Item_" + to_string(i), 1));
    }

    assert(5==jane.getCurrentNumberOfItems());

    // Increase max weight
    jane.setMaxCarryWeight(20);

    // Fill inventory again
    for (int i = 0; i < 5; i++)
    {
        assert(true==jane.pickUpItem("Item_" + to_string(i), 1));
    }

    assert(10==jane.getCurrentNumberOfItems());

    return true;
}

bool pickupItemReturnsFalseWhenDecreasingMaxItems(){
    Adventurer jane;
    jane.setMaxNumberOfItems(10);
    jane.setMaxCarryWeight(10);

    // Fill inventory
    for (int i = 0; i < jane.getMaxNumberOfItems(); i++)
    {
        assert(true==jane.pickUpItem("Item_" + to_string(i), 1));
    }

    // Decrease inventory size
    jane.setMaxNumberOfItems(5);

    // Try to insert into full inventory
    assert(false==jane.pickUpItem("Item_6", 1));

    return true;
}

bool dropItemUpdatesCurrentNumberOfItemsAndWeight(){
    Adventurer jane;
    jane.setMaxNumberOfItems(10);
    jane.setMaxCarryWeight(20);

    // Fill inventory
    for (int i = 0; i < jane.getMaxNumberOfItems(); i++)
    {
        //cout << jane.getCurrentCarryWeight() << endl;

        assert(true==jane.pickUpItem("Item_" + to_string(i), 2));
    }

    assert(10==jane.getCurrentNumberOfItems());
    assert(20==jane.getCurrentCarryWeight());


    assert(jane.dropItem(0));
    assert(9==jane.getCurrentNumberOfItems());
    assert(18==jane.getCurrentCarryWeight());

    assert(jane.dropItem(jane.getCurrentNumberOfItems() - 1));
    assert(8==jane.getCurrentNumberOfItems());
    assert(16==jane.getCurrentCarryWeight());

    return true;
}

struct inventoryItem
{
    string name;
    string weight;
};

bool compareInventories(const inventoryItem list[], const Adventurer &b)
{
    for (int i = 0; i < b.getCurrentNumberOfItems(); i++)
    {
        string **tmpItemB = b.getItem(i);

        //cout << list[0].name << endl;
        //cout << **(tmpItemB + 0) << endl;

        if (list[i].name != **(tmpItemB + 0))
            return false;

        //cout << list[0].weight << endl;
        //cout << **(tmpItemB + 1) << endl;
        if (list[i].weight != **(tmpItemB + 1))
            return false;
    }

    return true;
}

bool compareInventories(const Adventurer &a, const Adventurer &b)
{

    if (a.getCurrentNumberOfItems() != b.getCurrentNumberOfItems())
        return false;

    if (a.getMaxNumberOfItems() != b.getMaxNumberOfItems())
        return false;

    for (int i = 0; i < a.getCurrentNumberOfItems(); i++)
    {
        string **tmpItemA = a.getItem(i);
        string **tmpItemB = b.getItem(i);

        //cout << **(tmpItemA + 0) << endl;
        if (**(tmpItemA + 0) != **(tmpItemB + 0))
            return false;

        //cout << **(tmpItemA + 1) << endl;
        if (**(tmpItemA + 1) != **(tmpItemB + 1))
            return false;
    }

    return true;
}

bool dropItemPreservesOtherItems()
{
    Adventurer jane;
    jane.setMaxNumberOfItems(5);
    jane.setMaxCarryWeight(10);

    // Fill inventory
    for (int i = 0; i < jane.getMaxNumberOfItems(); i++)
    {
        assert(true==jane.pickUpItem("item_" + to_string(i), 2));
    }

    // Drop first Item out of 5
    assert(true==jane.dropItem(0));

    inventoryItem list[4];
    for (int i = 0; i < 4; i++)
    {
        list[i].name = "item_" + to_string(i + 1);
        list[i].weight = to_string(2);
    }

    // Drop last item out of 4
    assert(true==jane.dropItem(3));

    inventoryItem list_2[3];
    for (int i = 0; i < 3; i++)
    {
        list_2[i].name = "item_" + to_string(i + 1);
        list_2[i].weight = to_string(2);
    }

    // Drop all items
    assert(true==jane.dropItem(0));
    assert(true==jane.dropItem(0));
    assert(true==jane.dropItem(0));



    assert(true==compareInventories(list_2, jane));

    return true;
}

bool equalsOperatorCreatesDeepCopy()
{

    Adventurer source;
    source.setName("Bob");
    source.setMaxNumberOfItems(16);
    source.setMaxCarryWeight(500);
    source.setHealth(12);

    // Fill inventory
    for (int i = 0; i < source.getMaxNumberOfItems(); i++)
    {
        assert(true==source.pickUpItem("item_" + to_string(i), 5));
    }

    Adventurer dest;
    dest = source;
    assert("Bob"==dest.getName());
    assert(16==dest.getMaxNumberOfItems());
    assert(500==dest.getMaxCarryWeight());
    assert(12==dest.getHealth());
    assert(16==dest.getCurrentNumberOfItems());
    assert(16*5==dest.getCurrentCarryWeight());
    assert(true==compareInventories(source, dest));

    return true;
}

bool constructorCreatesDeepCopy()
{
    Adventurer source;
    source.setName("John");
    source.setMaxNumberOfItems(69);
    source.setMaxCarryWeight(12060);
    source.setHealth(54);

    // Fill inventory
    for (int i = 0; i < source.getMaxNumberOfItems(); i++)
    {
        assert(true==source.pickUpItem("item_" + to_string(i), 5));
    }

    Adventurer dest(source);

    assert("John"==dest.getName());

    assert(69==dest.getMaxNumberOfItems());
    assert(12060==dest.getMaxCarryWeight());
    assert(54==dest.getHealth());
    assert(69==dest.getCurrentNumberOfItems());
    assert(69*5==dest.getCurrentCarryWeight());
    assert(true==compareInventories(source, dest));

    return true;
}

bool setMaxItems()
{
    Adventurer john;
    john.setMaxNumberOfItems(69);

    return true;
}
bool runUnitTests()
{
	
	
    //~ setMaxItems();

    pickupItemIncrementsCurrentNumberOfItems();
    //pickupItemIncrementsCurrentCaryWeight();
    //pickupItemReturnsFalseIfMaxItemsReached();
    //pickupItemReturnsFalseIfMaxWeightReached();
    //pickupItemAddsItemAfterIncreasingMaxItems();
    //pickupItemAddsItemAfterIncreasingMaxWeight();
    //pickupItemReturnsFalseWhenDecreasingMaxItems();
    //~ dropItemUpdatesCurrentNumberOfItemsAndWeight();
    //~ dropItemPreservesOtherItems();
    //~ equalsOperatorCreatesDeepCopy();
    //~ constructorCreatesDeepCopy();

    /*
    pickupItem
        - Updates currentNumberOfItems [DONE]
        - Updates currentCarryWeight [DONE]
        - Cannot pickup when maxItemsReached [DONE]
        - Cannot pickup when maxWeightReached [DONE]
        - Handles Double
    setMaxItems
        - Preserves items when increasing
        - Destroys items when decreasing
            - Updates currentCarryWeight
            - Updates currentNumberOfItems
        - Can add items again after increasing
    dropItem
        - Removes item from list and consolidates
        - Cannot drop item if out of index
        - Cannot drop item if name not found
        - Drop item preserves other items
        - Updates currentCarryWeight
        - Updates currentNumberOfItems
    Operator=
        - Creates deep copy
    Copy constructor
        - Creates deep copy
    */
    return true;
}

int main() {

    runUnitTests();
    //cout << "Testing has been attempted in unit tests.." << endl;

    return 0;
}
