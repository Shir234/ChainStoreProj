#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Manager.h"
#include <cstring> // For string operations

// Constructor
Manager::Manager(const char* name, int age, const char* manageDepartment)
    : Person(name, age), manageDepartment(nullptr) {
    setManageDepartment(manageDepartment);
}

// Copy constructor
Manager::Manager(const Manager& other)
    : Person(other), manageDepartment(nullptr) {
    setManageDepartment(other.manageDepartment);
}

// Move constructor
Manager::Manager(Manager&& other) noexcept
    : Person(std::move(other)), manageDepartment(other.manageDepartment) {
    other.manageDepartment = nullptr;
}

// Destructor
Manager::~Manager() {
    delete[] manageDepartment;
}

// Copy assignment operator
Manager& Manager::operator=(const Manager& other) {
    if (this != &other) {
        Person::operator=(other); // Call base class assignment operator
        setManageDepartment(other.manageDepartment);
    }
    return *this;
}

// Move assignment operator
Manager& Manager::operator=(Manager&& other) noexcept {
    if (this != &other) {
        Person::operator=(std::move(other)); // Call base class move assignment operator
        std::swap(manageDepartment, other.manageDepartment);
    }
    return *this;
}

// Getter for manageDepartment
const char* Manager::getManageDepartment() const {
    return manageDepartment;
}

// Setter for manageDepartment
void Manager::setManageDepartment(const char* manageDepartment) {
    delete[] this->manageDepartment;
    this->manageDepartment = strdup(manageDepartment);
}
