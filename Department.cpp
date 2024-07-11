#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "Department.h"
#include "Item.h" 

// Constructor
Department::Department(const char* name, int inventoryMaxSize)
    : inventoryMaxSize(inventoryMaxSize), inventorySize(0), name(nullptr)
{
    setName(name);
    inventory = new Item*[inventoryMaxSize];
}

// Copy constructor
Department::Department(const Department& other)
    : inventory(nullptr), inventorySize(0), inventoryMaxSize(0), name(nullptr)
{
    *this = other; // Call copy assignment operator
}

// Move constructor
Department::Department(Department&& other)
    : inventory(nullptr), inventorySize(0), inventoryMaxSize(0), name(nullptr)
{
    *this = std::move(other); // Call move assignment operator
}

// Destructor
Department::~Department()
{
    delete[] name;
    for (int i = 0; i < inventorySize; ++i)
    {
        delete inventory[i];
    }
    delete[] inventory;
}

// Copy assignment operator
Department& Department::operator=(const Department& other)
{
    if (this != &other) 
    {
        delete[] name;
        for (int i = 0; i < inventorySize; ++i)
            delete inventory[i];
        delete[] inventory;

        // Copy data from other Department
        inventoryMaxSize = other.inventoryMaxSize;
        inventorySize = other.inventorySize;
        setName(other.name);
        inventory = new Item*[inventoryMaxSize];
        for (int i = 0; i < inventorySize; i++) 
        {
            inventory[i] = new Item(*other.inventory[i]);
        }
    }
    return *this;
}

// Move assignment operator
Department& Department::operator=(Department&& other)
{
    if (this != &other) 
    {
        std::swap(name, other.name);
        std::swap(inventory, other.inventory);
        std::swap(inventorySize, other.inventorySize);
        std::swap(inventoryMaxSize, other.inventoryMaxSize);
    }
    return *this;
}

// Method to add an item
bool Department::addItem(const Item& item)
{
    if (inventorySize == inventoryMaxSize)
        return false;

    inventory[inventorySize] = new Item(item);
    inventorySize++;
    //*this + item; // Use operator+
    return true;
}

// Method to remove an item
bool Department::removeItem(Item& item)
{
    for (int i = 0; i < inventorySize; ++i) 
    {
        if (*inventory[i] == item) // Item has an equality operator (operator==)
        {
            // Shift elements to fill the gap
            for (int j = i; j < inventorySize - 1; ++j) 
            {
                inventory[j] = inventory[j + 1];
            }
            inventorySize--;
            return true;
        }
    }
    return false; // Item not found
}

// Method to display all items in the department
void Department::showInventory() const
{
    cout << "Inventory of Department " << name << ":\n";
    for (int i = 0; i < inventorySize; ++i) {
        cout << *inventory[i] << "\n"; // Use Item's operator<<
    }
    cout <<endl;
}

// Setter for name
bool Department::setName(const char* name)
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

// Add item to inventory      Department + Item
Department& Department::operator+(const Item& item) 
{
    if (inventorySize < inventoryMaxSize)
    {
        inventory[inventorySize++] = new Item(item);    // Item has a copy constructor
    }
    return *this;
}

// Remove item from inventory    Department - Item
Department& Department::operator-(const Item& item) 
{
    for (int i = 0; i < inventorySize; ++i)
    {
        if (*inventory[i] == item) // Item has an equality operator (operator==)
        { 
            delete inventory[i];
            // Shift remaining elements
            for (int j = i; j < inventorySize - 1; ++j)
            {
                inventory[j] = inventory[j + 1];
            }
            --inventorySize;
            break;
        }
    }
    return *this;
}

// Access item in inventory         item = Department[index]
//////THIS SHOULD RETURN NULL OR THROW EXEPTION WHEN INDEX IS INVALID
Item& Department::operator[](int index) 
{
    if (index < 0 || index > inventorySize)
        return *inventory[0];

    return *inventory[index];
}

// Output operator (ostream operator<<)
ostream& operator<<(ostream& os, const Department& department)
{
    os << "Name: " << department.name << "\tInventory Size: " << department.inventorySize
        << "\tInventory Max Size: " << department.inventoryMaxSize
        << "\nInventory:\n";
    for (int i = 0; i < department.inventorySize; i++)
        os << *(department.inventory[i]) << "\n";  // Use Item's operator<<

    return os;
}