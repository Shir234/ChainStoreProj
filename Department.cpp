#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "Department.h"
#include "Item.h" 

// Constructor
Department::Department(const char* name, int maxNumItems)
    : maxNumItems(maxNumItems), numItems(0), name(nullptr)
{
    this->name = strdup(name);      //check input (validate)
    items = new Item*[maxNumItems];
}

// Copy constructor
Department::Department(const Department& other)
    : items(nullptr), numItems(0), maxNumItems(0), name(nullptr)
{
    *this = other; // Call copy assignment operator
}

// Move constructor
Department::Department(Department&& other)
    : items(nullptr), numItems(0), maxNumItems(0), name(nullptr)
{
    *this = std::move(other); // Call move assignment operator
}

// Destructor
Department::~Department()
{
    delete[] name;
    delete[] items;
}

// Copy assignment operator
Department& Department::operator=(const Department& other)
{
    if (this != &other) {
        delete[] name;
        delete[] items;

        // Copy data from other Department
        maxNumItems = other.maxNumItems;
        numItems = other.numItems;
        name = strdup(other.name);
        items = new Item*[maxNumItems];
        for (int i = 0; i < numItems; ++i) {
            items[i] = new Item(*other.items[i]);
        }
    }
    return *this;
}

// Move assignment operator
Department& Department::operator=(Department&& other)
{
    if (this != &other) {
        std::swap(name, other.name);
        std::swap(items, other.items);
        std::swap(numItems, other.numItems);
        std::swap(maxNumItems, other.maxNumItems);
    }
    return *this;
}

// Method to add an item
bool Department::addItem(const Item& item)
{
    if (numItems == maxNumItems)
        return false;

    items[numItems] = new Item(item);
    numItems++;
    return true;
}

// Method to remove an item by name
bool Department::removeItem(const char* itemName)
{
    for (int i = 0; i < numItems; ++i) {
        if (strcmp(items[i]->getName(), itemName) == 0)
        {
            // Shift elements to fill the gap
            for (int j = i; j < numItems - 1; ++j) {
                items[j] = items[j + 1];
            }
            numItems--;
            return true;
        }
    }
    return false; // Item not found
}

// Method to display all items in the department
void Department::showInventory() const
{
    cout << "Inventory of Department " << name << ":\n";
    for (int i = 0; i < numItems; ++i) {
       cout << items[i]->getName() << " - $" << items[i]->getPrice() << "\n";
    }
    cout <<endl;
}