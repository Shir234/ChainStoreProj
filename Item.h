#ifndef ITEM_H
#define ITEM_H

#include "ChaineStoreExceptions.h"

#include <iostream>
using namespace std;

class Item {
private:
    char* name;
    int price;

public:
    Item(const char* name, int price);      // Constructor
    Item(const Item& other);                // Copy constructor
    Item(Item&& other) noexcept;            // Move constructor
    ~Item();                                // Destructor
    Item& operator=(const Item& other);     // Copy assignment operator
    Item& operator=(Item&& other) noexcept; // Move assignment operator

    const char* getName() const { return name; };
    void setName(const char* name);
    int getPrice() const { return price; };
    void setPrice(int price);

    // Operator overloads
    bool operator==(const Item& other) const;
    friend ostream& operator<<(ostream& os, const Item& item);
};

#endif // ITEM_H