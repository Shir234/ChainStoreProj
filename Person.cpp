#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Person.h"
#include <string> // For string operations

int Person::nextId = 1; // Initialize static member variable


// Constructor
Person::Person(const char* name, int age) : name(nullptr), age(age), id(nextId++)
{
    setName(name);
}

// Copy constructor
Person::Person(const Person& other): name(nullptr), id(nextId++)
{
    *this = other; // Call copy assignment operator
}

// Move constructor
Person::Person(Person&& other) : name(nullptr), id(nextId++)
{
    *this = std::move(other); // Call move assignment operator
}

// Copy assignment operator
Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        setAge(other.age);
        setName(other.name);
    }
    return *this;
}

// Move assignment operator
Person& Person::operator=(Person&& other)
{
    if (this != &other)
    {
        setAge(other.age);
        std::swap(name, other.name);
    }
    return *this;
}

// Destructor
Person::~Person() 
{
    delete[] name;
}

// Setter for name
bool Person::setName(const char* name) 
{
    if (name != nullptr)
    {
        delete[] this->name; // Release existing name if any
        int len = strlen(name) + 1; // +1 for null terminator
        this->name = new char[len];
        strcpy(this->name, name); // Copy the new name
        return true;
    }
    return false;
}

// Setter for age
bool Person::setAge(int age) 
{
    if (age > 0 && age <= 120) {
        this->age = age;
        return true;
    }
    return false;
}

// Output operator 
ostream& operator<<(ostream& os, const Person& person)
{
    os << "id: " << person.getId() << "\t" << "Name: " << person.getName() << "\t" << "age : " << person.getAge();
    person.toOs(os);
    return os;
}