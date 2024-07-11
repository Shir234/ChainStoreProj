#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Manager.h"
#include <string> 

// Constructor
Manager::Manager(const char* name, int age, const char* position, const char* manageDepartment)
    : Employee(name, age, position), manageDepartment(nullptr)
{
    setManageDepartment(manageDepartment);
}

// Destructor
Manager::~Manager() 
{
    delete[] manageDepartment;
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

// Output operator 
ostream& operator<<(ostream& os, const Manager& manager)
{
    os << static_cast<const Employee&>(manager); // Use Employee's operator<<
    os << "\nmanager department: " << manager.getManageDepartment() << "\n";
    return os;
}
