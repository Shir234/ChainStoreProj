#pragma once
#ifndef REGULARBRANCH_H
#define REGULARBRANCH_H

#include "Branch.h"
#include "Employee.h"

class RegularBranch : virtual public Branch {
private:
    Employee* employees;
    int numEmployees;
    int maxNumEmployees;
    char* address;

public:
    RegularBranch(const char* name, int maxNumDepartments = 10, int maxNumEmployees = 50, const char* address = ""); // Constructor
    RegularBranch(const RegularBranch& other); // Copy constructor
    RegularBranch(RegularBranch&& other) noexcept; // Move constructor
    virtual ~RegularBranch(); // Destructor

    RegularBranch& operator=(const RegularBranch& other); // Copy assignment operator
    RegularBranch& operator=(RegularBranch&& other) noexcept; // Move assignment operator

    bool addEmployee(const Employee& employee); // Method to add an employee
    bool removeEmployee(const char* employeeName); // Method to remove an employee by name
    const char* getAddress() const; // Getter for address
    void setAddress(const char* address); // Setter for address
};

#endif // REGULARBRANCH_H
