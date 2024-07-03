#ifndef MANAGER_H
#define MANAGER_H

#include "Person.h"

class Manager : public Person {
private:
    char* manageDepartment;

public:
    Manager(const char* name, int age, const char* manageDepartment); // Constructor
    Manager(const Manager& other); // Copy constructor
    Manager(Manager&& other) noexcept; // Move constructor
    virtual ~Manager(); // Destructor

    Manager& operator=(const Manager& other); // Copy assignment operator
    Manager& operator=(Manager&& other) noexcept; // Move assignment operator

    const char* getManageDepartment() const; // Getter for manageDepartment
    void setManageDepartment(const char* manageDepartment); // Setter for manageDepartment
};

#endif // MANAGER_H
