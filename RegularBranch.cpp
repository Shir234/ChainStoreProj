#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "RegularBranch.h"
#include <cstring> // For string operations

// Constructor
RegularBranch::RegularBranch(const char* name, int maxNumDepartments, int maxNumEmployees, const char* address)
    : Branch(maxNumDepartments), employees(nullptr), numEmployees(0), maxNumEmployees(maxNumEmployees), address(nullptr) {
    setAddress(address);
    employees = new Employee[maxNumEmployees];
}

// Copy constructor
RegularBranch::RegularBranch(const RegularBranch& other)
    : Branch(other), employees(nullptr), numEmployees(0), maxNumEmployees(0), address(nullptr) {
    *this = other; // Call copy assignment operator
}

// Move constructor
RegularBranch::RegularBranch(RegularBranch&& other) noexcept
    : Branch(std::move(other)), employees(nullptr), numEmployees(0), maxNumEmployees(0), address(nullptr) {
    *this = std::move(other); // Call move assignment operator
}

// Destructor
RegularBranch::~RegularBranch() {
    delete[] address;
    delete[] employees;
}

// Copy assignment operator
RegularBranch& RegularBranch::operator=(const RegularBranch& other) {
    if (this != &other) {
        Branch::operator=(other); // Call base class assignment operator
        setAddress(other.address);
        delete[] employees;
        maxNumEmployees = other.maxNumEmployees;
        numEmployees = other.numEmployees;
        employees = new Employee[maxNumEmployees];
        for (int i = 0; i < numEmployees; ++i) {
            employees[i] = other.employees[i];
        }
    }
    return *this;
}

// Move assignment operator
RegularBranch& RegularBranch::operator=(RegularBranch&& other) noexcept {
    if (this != &other) {
        Branch::operator=(std::move(other)); // Call base class move assignment operator
        std::swap(address, other.address);
        std::swap(employees, other.employees);
        std::swap(numEmployees, other.numEmployees);
        std::swap(maxNumEmployees, other.maxNumEmployees);
    }
    return *this;
}

// Method to add an employee
bool RegularBranch::addEmployee(const Employee& employee) {
    if (numEmployees == maxNumEmployees)
        return false;

    employees[numEmployees] = employee;
    numEmployees++;
    return true;
}

// Method to remove an employee by name
bool RegularBranch::removeEmployee(const char* employeeName) {
    for (int i = 0; i < numEmployees; ++i) {
        if (strcmp(employees[i].getName(), employeeName) == 0) {
            // Shift elements to fill the gap
            for (int j = i; j < numEmployees - 1; ++j) {
                employees[j] = employees[j + 1];
            }
            numEmployees--;
            return true;
        }
    }
    return false; // Employee not found
}

// Getter for address
const char* RegularBranch::getAddress() const {
    return address;
}

// Setter for address
void RegularBranch::setAddress(const char* address) {
    delete[] this->address;
    this->address = strdup(address);
}
