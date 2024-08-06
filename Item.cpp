#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "Item.h"

// Constructor
Item::Item(const char* name, double price) : name(nullptr), price(0)
{
    cout << "in item c'tor\n";
    setName(name);
    setPrice(price);
}

// Copy constructor
Item::Item(const Item& other) : name(nullptr), price(0)
{
    cout << "in item copy c'tor\n";
    *this = other; // Call copy assignment operator
}

// Move constructor
Item::Item(Item&& other) noexcept : name(nullptr), price(0)
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
        try
        {
            setName(other.name);
            setPrice(other.price);

        }
        catch (const InvalidItemNameException& e)
        {
            throw;
        }
        catch (const InvalidItemPriceException& e)
        {
            throw;
        }
    }
    return *this;
}

// Move assignment operator
Item& Item::operator=(Item&& other) noexcept
{
    cout << "in item move operator =\n";
    if (this != &other) 
    {
        std::swap(name, other.name);
        this->price = other.price;
    }
    return *this;
}


// Setter for name
void Item::setName(const char* name) 
{
    if (name == nullptr || name[0] == '\0')
    {
        throw InvalidItemNameException();
    }
    
    delete[] this->name; // Release existing name if any
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name); // Copy the new name
}

// Setter for price
void Item::setPrice(double price)
{
    if (price <= 0) 
        throw InvalidItemPriceException();

    this->price = price;
}

// Equality operator
bool Item::operator==(const Item& other) const
{
    return (strcmp(getName(), other.getName()) == 0 && getPrice() == other.getPrice());
}


ostream& operator<<(ostream& os, const Item& item)
{
    os << "Item: " << item.name << "\tPrice: $: " << item.price << "\n";
    return os;
}

