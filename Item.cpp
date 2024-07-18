#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "Item.h"

// Constructor
Item::Item(const char* name, double price) : name(nullptr)
{
    cout << "in item c'tor\n";
    setName(name);
    setPrice(price);
}

// Copy constructor
Item::Item(const Item& other) : name(nullptr)
{
    cout << "in item copy c'tor\n";
    *this = other; // Call copy assignment operator
}

// Move constructor
Item::Item(Item&& other) : name(nullptr)
{
    cout << "in item move c'tor\n";
    *this = std::move(other); // Call move assignment operator
}

// Destructor
Item::~Item()
{
    cout << "in item d'tor\n";
    delete[] name;
}

// Copy assignment operator
Item& Item::operator=(const Item& other)
{
    cout << "in item operator =\n";
    if (this != &other) 
    {
        setName(other.name);
        setPrice(other.price);
    }
    return *this;
}

// Move assignment operator
Item& Item::operator=(Item&& other)
{
    cout << "in item move operator =\n";
    if (this != &other) 
    {
        std::swap(name, other.name);
        this->setPrice(other.price);
    }
    return *this;
}


// Setter for name
bool Item::setName(const char* name) 
{
    if (name != nullptr) 
    {
        delete[] this->name; // Release existing name if any
        int len = strlen(name) + 1; // +1 for null terminator
        this->name = new char[len];
        strcpy(this->name, name); // Copy the new name
        return true;
    }
    return false;
}

// Setter for price
bool Item::setPrice(double price)
{
    if (price > 0) 
    {
        this->price = price;
        return true;
    }
    return false;
}

// Equality operator
bool Item::operator==(const Item& other) const
{
    return (strcmp(name, other.name) == 0 && price == other.price);
}


ostream& operator<<(ostream& os, const Item& item)
{
    os << "Item: " << item.name << "\tPrice: $: " << item.price << "\n";
    return os;
}

