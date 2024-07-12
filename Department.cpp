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
    cout << "in depar c'tor\n";
    setName(name);
    inventory = new Item*[inventoryMaxSize];
}

// Copy constructor
Department::Department(const Department& other)
    : inventory(nullptr), inventorySize(0), inventoryMaxSize(0), name(nullptr)
{
    cout << "in depar copy c'tor\n";
    *this = other; // Call copy assignment operator
}

// Move constructor
Department::Department(Department&& other)
    : inventory(nullptr), inventorySize(0), inventoryMaxSize(0), name(nullptr)
{
    cout << "in depar move c'tor\n";
    *this = std::move(other); // Call move assignment operator
}

// Destructor
Department::~Department()
{
    cout << "in depar d'tor\n";
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
    cout << "in depar operator =\n";
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
    cout << "in depar move operator =\n";
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

// Add item to inventory      Department + Item
Department& Department::operator+(const Item& item)
{
    if (!this->addItem(item))
    {
        cout << "Item was not added\n";
        return *this;
    }
    cout << "Item added successfully\n";
    return *this;
}

// Method to remove an item
bool Department::removeItem(Item& item)
{
    for (int i = 0; i < inventorySize; i++) 
    {
        if (*inventory[i] == item) // Item has an equality operator (operator==)
        {
            delete inventory[i];
            // Shift elements to fill the gap
            for (int j = i; j < inventorySize - 1; j++) 
            {
                inventory[j] = inventory[j + 1];
            }
            inventorySize--;
            return true;
        }
    }
    return false; // Item not found
}

// Remove item from inventory    Department - Item
Department& Department::operator-(Item& item)
{
    if (!this->removeItem(item))
    {
        cout << "Item was not found to remove\n";
        return *this;
    }  

    cout << "Item removed successfully\n";
    return *this;
}

// Method to display all items in the department
void Department::showInventory() const
{
    cout << "Inventory of Department " << name << ":\n";
    for (int i = 0; i < inventorySize; ++i) 
    {
        cout << *inventory[i]; // Use Item's operator<<
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

// Access item in inventory         item = Department[index]
Item* Department::operator[](int index) 
{
    cout << "in operator []\n";
    if (index < 0 || index > inventorySize)
    {
        cout << "invalid index, returned null";
        return nullptr;
    }

    return inventory[index];
}

// Output operator (ostream operator<<)
ostream& operator<<(ostream& os, const Department& department)
{
    os << "Name: " << department.name << "\tInventory Size: " << department.inventorySize
        << "\tInventory Max Size: " << department.inventoryMaxSize
        << "\nInventory:\n";
    for (int i = 0; i < department.inventorySize; i++)
        os << *(department.inventory[i]);  // Use Item's operator<<

    return os;
}