#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Manager.h"
#include <string> 

// Constructor
Manager::Manager(const char* name, int age, const char* position, const char* manageDepartment)
    : Employee(name, age, position), manageDepartment(nullptr)
{
    cout << "in Manager c'tor\n";
    setManageDepartment(manageDepartment);
}

// Copy constructor
Manager::Manager(const Manager& other) : Employee(other), manageDepartment(nullptr)
{
    //setManageDepartment(other.manageDepartment);
    *this = other;
}

// Move constructor
Manager::Manager(Manager&& other) noexcept : Employee(std::move(other)), manageDepartment(nullptr)
{
    *this = std::move(other); // Call move assignment operator
}

// Destructor
Manager::~Manager() 
{
    cout << "in Manager d'tor\n";
    delete[] manageDepartment;
}

// Copy assignment operator
Manager& Manager::operator=(const Manager& other)
{
    if (this != &other)
    {
        Employee::operator=(other); // Call base class assignment operator
        setManageDepartment(other.manageDepartment);
    }
    return *this;
}

// Move assignment operator
Manager& Manager::operator=(Manager&& other) noexcept
{
    if (this != &other)
    {
        Employee::operator=(std::move(other)); // Call base class move assignment operator
        delete[] manageDepartment;
        std::swap(manageDepartment, other.manageDepartment);
    }
    return *this;
}

// Setter for manageDepartment
bool Manager::setManageDepartment(const char* manageDepartment)
{
    if (manageDepartment == nullptr || manageDepartment[0] == '\0')
        throw InvalidNameException("Manage department cannot be null or empty");
    
    delete[] this->manageDepartment;
    this->manageDepartment = new char[strlen(manageDepartment) + 1];
    strcpy(this->manageDepartment, manageDepartment);
}

void Manager::toOs(ostream& os) const
{
    os << "\nemployee position: " << getPosition() << "\n";
    os << "manager department: " << getManageDepartment() << "\n";
}