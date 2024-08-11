#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "ChaineStoreExceptions.h"

class Item;

class Department {
private:
	Item** inventory;
	int inventorySize;
	int inventoryMaxSize;
	char* name;

public:
	Department(const char* name, int inventoryMaxSize = 50);        // Constructor
	Department(const Department& other);                            // Copy constructor
	Department(Department&& other) noexcept;                        // Move constructor
	~Department();                                                  // Destructor
	Department& operator=(const Department& other);                 // Copy assignment operator
	Department& operator=(Department&& other) noexcept;             // Move assignment operator

	void addItem(const Item& item);
	void removeItem(Item& item);
	void showInventory() const;
	const char* getName() const { return name; };
	void setName(const char* name);
	int getNumItems() const { return inventorySize; };
	int getMaxNumItems() const { return inventoryMaxSize; };

	// Operator overloads
	Department& operator+(const Item& item);    // Add item to inventory        Department + Item
	Department& operator-(Item& item);          // Remove item from inventory   Department - Item
	Item* operator[](int index);                // Access item in inventory     Item* item = Department[index]
	friend ostream& operator<<(ostream& os, const Department& dp);
	bool isInventoryFull() const { return inventorySize >= inventoryMaxSize; }
};

#endif // DEPARTMENT_H