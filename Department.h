#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
using namespace std;

class Item;

class Department {
private:
    Item** inventory;
    int inventorySize;
    int inventoryMaxSize;
    char* name;

public:
    Department(const char* name, int inventoryMaxSize = 50); // Constructor
    Department(const Department& other); // Copy constructor
    Department(Department&& other); // Move constructor
    ~Department(); // Destructor

    Department& operator=(const Department& other); // Copy assignment operator
    Department& operator=(Department&& other); // Move assignment operator
    
    // Methods to add and remove items
    bool addItem(const Item& item); // Calls operator+
    bool removeItem(Item& item); // Calls operator-

    // Method to display all items - the inventory
    void showInventory() const; 

    const char* getName() const { return name; }; // Getter for name
    bool setName(const char* name); // Setter for name
    int getNumItems() const { return inventorySize; }; // Getter for numItems
    int getMaxNumItems() const { return inventoryMaxSize; }; // Getter for maxNumItems


    // Operator overloads
    Department& operator+(const Item& item); // Add item to inventory           Department + Item
    Department& operator-(Item& item); // Remove item from inventory      Department - Item
    Item* operator[](int index); // Access item in inventory                   Item* item = Department[index]

    friend ostream& operator<<(ostream& os, const Department& dp);

};

#endif // DEPARTMENT_H