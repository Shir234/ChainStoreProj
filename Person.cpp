#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Person.h"
#include <string> // For string operations

// Constructor
Person::Person(const char* name, int age)
    : name(nullptr), age(age) {
    setName(name);
}

// Copy constructor
Person::Person(const Person& other)
    : name(nullptr), age(other.age) {
    setName(other.name);
}

// Move constructor
Person::Person(Person&& other) 
    : name(other.name), age(other.age) {
    other.name = nullptr;
}

// Destructor
Person::~Person() {
    delete[] name;
}

// Copy assignment operator
Person& Person::operator=(const Person& other) {
    if (this != &other) {
        setName(other.name);
        age = other.age;
    }
    return *this;
}

// Move assignment operator
Person& Person::operator=(Person&& other) {
    if (this != &other) {
        std::swap(name, other.name);
        std::swap(age, other.age);
    }
    return *this;
}

// Getter for name
const char* Person::getName() const {
    return name;
}

// Setter for name
void Person::setName(const char* name) {
    delete[] this->name;
    this->name = strdup(name);
}

// Getter for age
int Person::getAge() const {
    return age;
}

// Setter for age
void Person::setAge(int age) {
    this->age = age;
}
