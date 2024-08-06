#ifndef ITEM_H
#define ITEM_H

#include "ChaineStoreExceptions.h"

#include <iostream>
using namespace std;

class Item {
private:
    char* name;
    double price;

public:
    Item(const char* name, double price); // Constructor
    Item(const Item& other); // Copy constructor
    Item(Item&& other) noexcept; // Move constructor
    ~Item(); // Destructor

    Item& operator=(const Item& other); // Copy assignment operator
    Item& operator=(Item&& other) noexcept; // Move assignment operator

    const char* getName() const { return name; }; // Getter for name
    void setName(const char* name); // Setter for name
 
    double getPrice() const { return price; }; // Getter for price
    void setPrice(double price); // Setter for price

    // Operator overloads
    bool operator==(const Item& other) const;
    friend ostream& operator<<(ostream& os, const Item& item);
};

#endif // ITEM_H