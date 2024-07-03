#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Item;

class Department {
private:
    Item** items;
    int numItems;
    int maxNumItems;
    char* name;
public:
    Department(const char* name, int maxNumItems = 50); // Constructor
    Department(const Department& other); // Copy constructor
    Department(Department&& other); // Move constructor
    ~Department(); // Destructor

    Department& operator=(const Department& other); // Copy assignment operator
    Department& operator=(Department&& other); // Move assignment operator

    bool addItem(const Item& item); // Method to add an item
    bool removeItem(const char* itemName); // Method to remove an item by name
    void showInventory() const; // Method to display all items in the department

    //Department(const std::string& name);
    //virtual ~Department();
    //void addItem(const Item& item);
    //void removeItem(const Item& item);
    //std::string getName() const;
    //virtual void displayInventoryDetails() const;
};

#endif // DEPARTMENT_H