#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "Item.h"

// Constructor
Item::Item(const char* name) : name(nullptr)
{
    setName(name);
}

// Copy constructor
Item::Item(const Item& other) : name(nullptr)
{
    *this = other; // Call copy assignment operator
}

// Move constructor
Item::Item(Item&& other) : name(nullptr)
{
    *this = std::move(other); // Call move assignment operator
}

// Destructor
Item::~Item()
{
    delete[] name;
}

// Copy assignment operator
Item& Item::operator=(const Item& other)
{
    if (this != &other) {
        setName(other.name);
    }
    return *this;
}

// Move assignment operator
Item& Item::operator=(Item&& other)
{
    if (this != &other) {
        std::swap(name, other.name);
    }
    return *this;
}


// Setter for name
void Item::setName(const char* name) {
    delete[] this->name;
    this->name = strdup(name);  //check later
}

