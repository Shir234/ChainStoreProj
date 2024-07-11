#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
private:
    char* manageDepartment;

public:
    Manager(const char* name, int age, const char* position, const char* manageDepartment); // Constructor
    Manager(const Manager& other) = delete; // Copy constructor
    Manager(Manager&& other) = delete; // Move constructor
    ~Manager(); // Destructor

    Manager& operator=(const Manager& other) = delete; // Copy assignment operator
    Manager& operator=(Manager&& other) = delete; // Move assignment operator

    const char* getManageDepartment() const { return manageDepartment; } // Getter for manageDepartment
    bool setManageDepartment(const char* manageDepartment); // Setter for manageDepartment

    friend ostream& operator<<(ostream& os, const Manager& manager); // Output operator

};

#endif // MANAGER_H
