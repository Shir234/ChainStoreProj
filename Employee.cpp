#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Employee.h"
#include <cstring> // For string operations

// Constructor
Employee::Employee(const char* name, int age, const char* position)
    : Person(name, age), position(nullptr) {
    setPosition(position);
}

// Copy constructor
Employee::Employee(const Employee& other)
    : Person(other), position(nullptr) {
    setPosition(other.position);
}

// Move constructor
Employee::Employee(Employee&& other) noexcept
    : Person(std::move(other)), position(other.position) {
    other.position = nullptr;
}

// Destructor
Employee::~Employee() {
    delete[] position;
}

// Copy assignment operator
Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        Person::operator=(other); // Call base class assignment operator
        setPosition(other.position);
    }
    return *this;
}

// Move assignment operator
Employee& Employee::operator=(Employee&& other) noexcept {
    if (this != &other) {
        Person::operator=(std::move(other)); // Call base class move assignment operator
        std::swap(position, other.position);
    }
    return *this;
}

// Getter for position
const char* Employee::getPosition() const {
    return position;
}

// Setter for position
void Employee::setPosition(const char* position) {
    delete[] this->position;
    this->position = strdup(position);
}
