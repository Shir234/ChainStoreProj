#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Employee.h"
#include <string> 

// Constructor
Employee::Employee(const char* name, int age, const char* position) : Person(name, age), position(nullptr) 
{
    setPosition(position);
}

// Copy constructor
Employee::Employee(const Employee& other): Person(other), position(nullptr)
{
    *this = other;
}

// Move constructor
Employee::Employee(Employee&& other) : Person(other), position(nullptr)
{
    *this = std::move(other); // Call move assignment operator
}

// Destructor
Employee::~Employee() 
{
    delete[] position;
}

// Copy assignment operator
Employee& Employee::operator=(const Employee& other)
{
    if (this != &other)
    {
        Person::operator=(other); // Call base class assignment operator
        setPosition(other.position);
    }
    return *this;
}

// Move assignment operator
Employee& Employee::operator=(Employee&& other)
{
    if (this != &other)
    {
        Person::operator=(std::move(other)); // Call base class assignment operator
        
        std::swap(position, other.position);
    }
    return *this;
}
// Setter for position
bool Employee::setPosition(const char* position)
{
    if (position != nullptr) 
    {
        delete[] this->position;
        int len = strlen(position) + 1;
        this->position = new char[len];
        strcpy(this->position, position);
        return true;
    }
    return false;
}

// Getter for position
const char* Employee::getPosition() const 
{
    return position;
}

// Equality operator
bool Employee::operator==(const Employee& other) const
{
    return (this->getId() == other.getId());
}

void Employee::toOs(ostream& os) const
{
    os << "\n\t\tposition: " << getPosition() << "\n";
}