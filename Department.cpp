#pragma warning (disable: 4996)

#include <string>
#include "Department.h"
#include "Item.h" 

// Constructor
Department::Department(const char* name, int inventoryMaxSize)
	: inventoryMaxSize(inventoryMaxSize), inventorySize(0), name(nullptr)
{

	if (inventoryMaxSize <= 0)
		throw InvalidInventorySizeException();

	setName(name);
	inventory = new Item * [inventoryMaxSize];
}

// Copy constructor
Department::Department(const Department& other)
	: inventory(nullptr), inventorySize(0), inventoryMaxSize(0), name(nullptr)
{
	try
	{
		setName(other.name);
		inventoryMaxSize = other.inventoryMaxSize;
		inventory = new Item * [inventoryMaxSize];

		for (int i = 0; i < other.inventorySize; ++i)
		{
			inventory[i] = new Item(*other.inventory[i]);
			++inventorySize;
		}
	}
	catch (...)
	{
		for (int i = 0; i < inventorySize; ++i)
		{
			delete inventory[i];
		}
		delete[] inventory;
		delete[] name;
		throw;
	}
}

// Move constructor
Department::Department(Department&& other) noexcept
	: inventory(nullptr), inventorySize(0), inventoryMaxSize(0), name(nullptr)
{
	*this = move(other); // Call move assignment operator
}

// Destructor
Department::~Department()
{
	delete[] name;
	for (int i = 0; i < inventorySize; ++i)
		delete inventory[i];

	delete[] inventory;
}

// Copy assignment operator
Department& Department::operator=(const Department& other)
{
	if (this != &other)
	{
		Department temp(other);
		swap(name, temp.name);
		swap(inventory, temp.inventory);
		swap(inventorySize, temp.inventorySize);
		swap(inventoryMaxSize, temp.inventoryMaxSize);
	}
	return *this;
}

// Move assignment operator
Department& Department::operator=(Department&& other) noexcept
{
	if (this != &other)
	{
		swap(name, other.name);
		swap(inventory, other.inventory);
		swap(inventorySize, other.inventorySize);
		swap(inventoryMaxSize, other.inventoryMaxSize);
	}
	return *this;
}

// Method to add an item
void Department::addItem(const Item& item)
{
	if (isInventoryFull())
		throw InventoryFullException();

	try
	{
		inventory[inventorySize] = new Item(item);
		inventorySize++;
	}
	catch (const InvalidNameException& e)
	{
		throw DepartmentItemException("Failed to add item: " + string(e.what()));
	}
	catch (const InvalidItemPriceException& e)
	{
		throw DepartmentItemException("Failed to add item: " + string(e.what()));
	}
	catch (const bad_alloc& e)
	{
		throw DepartmentMemoryException("Failed to allocate memory for new item");
	}
}

// Method to remove an item
void Department::removeItem(Item& item)
{
	for (int i = 0; i < inventorySize; i++)
	{
		if (*inventory[i] == item) // Item has an equality operator (operator==)
		{
			delete inventory[i];
			for (int j = i; j < inventorySize - 1; j++)
				inventory[j] = inventory[j + 1];
			inventorySize--;
			return;
		}
	}
	throw ItemNotFoundException(); // Item not found
}

// Method to display all items in the department
void Department::showInventory() const
{
	cout << "Inventory of Department- " << name << "- :\n";
	if (inventorySize <= 0)
		throw InventoryEmptyException();

	for (int i = 0; i < inventorySize; ++i)
	{
		cout << i + 1 << "." << *inventory[i]; // Use Item's operator<<
	}
}

// Setter for name
void  Department::setName(const char* name)
{
	if (name == nullptr || name[0] == '\0')
		throw InvalidNameException("Department name cannot be null or empty");

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

// Add item to inventory      Department + Item
Department& Department::operator+(const Item& item)
{
	addItem(item);
	return *this;
}

// Remove item from inventory    Department - Item
Department& Department::operator-(Item& item)
{
	removeItem(item);
	return *this;
}


// Access item in inventory         item = Department[index]
Item* Department::operator[](int index)
{
	if (index < 0 || index >= inventorySize)
		throw BranchIndexOutOfRangeException();

	return inventory[index];
}

// Output operator (ostream operator<<)
ostream& operator<<(ostream& os, const Department& department)
{
	os << department.name << "\n\tInventory Size: " << department.inventorySize
		<< "\n\tInventory Max Size: " << department.inventoryMaxSize
		<< "\n\tInventory:\n";
	for (int i = 0; i < department.inventorySize; i++)
		os << "\t" << i + 1 << "." << *(department.inventory[i]);  // Use Item's operator<<

	return os;
}