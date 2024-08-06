#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
private:
    char* manageDepartment;

public:
    Manager(const char* name, int age, const char* position, const char* manageDepartment); // Constructor
    ~Manager(); // Destructor

    const char* getManageDepartment() const { return manageDepartment; } // Getter for manageDepartment
    bool setManageDepartment(const char* manageDepartment); // Setter for manageDepartment

    virtual void toOs(ostream& os) const override;

private:
    Manager(const Manager& other); // Copy constructor
    Manager(Manager&& other) noexcept; // Move constructor
    Manager& operator=(const Manager& other); // Copy assignment operator
    Manager& operator=(Manager&& other) noexcept; // Move assignment operator

};

#endif // MANAGER_H
