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
Manager::Manager(Manager&& other) : Employee(std::move(other)), manageDepartment(nullptr)
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
Manager& Manager::operator=(Manager&& other)
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
    if (manageDepartment != nullptr)
    {
        delete[] this->manageDepartment;
        int len = strlen(manageDepartment) + 1;
        this->manageDepartment = new char[len];
        strcpy(this->manageDepartment, manageDepartment);
        return true;
    }
    return false;
}

//// Output operator 
//ostream& operator<<(ostream& os, const Manager& manager)
//{
//    os << static_cast<const Employee&>(manager); // Use Employee's operator<<
//    os << "manager department: " << manager.getManageDepartment() << "\n";
//    return os;
//}


void Manager::toOs(ostream& os) const
{
    os << "\t\tmanager department: " << manageDepartment << "\n";
}