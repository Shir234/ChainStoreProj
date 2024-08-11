#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "Item.h"

// Constructor
Item::Item(const char* name, int price) : name(nullptr), price(0)
{
	setName(name);
	setPrice(price);
}

// Copy constructor
Item::Item(const Item& other) : name(nullptr), price(0)
{
	*this = other; // Call copy assignment operator
}

// Move constructor
Item::Item(Item&& other) noexcept : name(nullptr), price(0)
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
	if (this != &other)
	{
		try
		{
			setName(other.name);
			setPrice(other.price);

		}
		catch (...)
		{
			delete[] name;
			name = nullptr;
			price = 0;
			throw;
		}
	}
	return *this;
}

// Move assignment operator
Item& Item::operator=(Item&& other) noexcept
{
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
		throw InvalidNameException("Item name cannot be null or empty");

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

// Setter for price
void Item::setPrice(int price)
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
