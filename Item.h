#pragma once
#ifndef ITEM_H
#define ITEM_H

class Item {
private:
    char* name;
    double price;

public:
    Item(const char* name); // Constructor
    Item(const Item& other); // Copy constructor
    Item(Item&& other); // Move constructor
    ~Item(); // Destructor

    Item& operator=(const Item& other); // Copy assignment operator
    Item& operator=(Item&& other); // Move assignment operator

    const char* getName() const { return name; }; // Getter for name
    void setName(const char* name); // Setter for name

    double getPrice() const { return price; }; // Getter for price


    //Item(const std::string& name);
    //std::string getName() const;
    //void setName(const std::string& name);
    //bool operator==(const Item& other) const;
};

#endif // ITEM_H