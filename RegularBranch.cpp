#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "RegularBranch.h"
#include "Employee.h"
#include <string> 

// Constructor
RegularBranch::RegularBranch(const char* name, int maxNumDepartments, const char* address, int maxNumEmployees)
    : Branch(maxNumDepartments), employees(nullptr), numEmployees(0), maxNumEmployees(maxNumEmployees), address(nullptr) 
{
    setAddress(address);
    employees = new Employee*[maxNumEmployees];
}

// Copy constructor
RegularBranch::RegularBranch(const RegularBranch& other)
    : Branch(other), employees(nullptr), numEmployees(0), maxNumEmployees(0), address(nullptr) 
{
    *this = other; // Call copy assignment operator
}

// Move constructor
RegularBranch::RegularBranch(RegularBranch&& other) 
    : Branch(std::move(other)), employees(nullptr), numEmployees(0), maxNumEmployees(0), address(nullptr) 
{
    *this = std::move(other); // Call move assignment operator
}

// Destructor
RegularBranch::~RegularBranch() 
{
    delete[] address;
    for (int i = 0; i < numEmployees; i++)
        delete employees[i];
    delete[] employees;
}

// Copy assignment operator
RegularBranch& RegularBranch::operator=(const RegularBranch& other) 
{
    if (this != &other) 
    {
        Branch::operator=(other); // Call base class assignment operator
        setAddress(other.address);
        for (int i = 0; i < numEmployees; i++)
            delete employees[i];
        delete[] employees;

        maxNumEmployees = other.maxNumEmployees;
        numEmployees = other.numEmployees;
        employees = new Employee*[maxNumEmployees];
 
        for (int i = 0; i < numEmployees; i++) 
            employees[i] = new Employee(*other.employees[i]);
        
    }
    return *this;
}

// Move assignment operator
RegularBranch& RegularBranch::operator=(RegularBranch&& other) 
{
    if (this != &other) 
    {
        Branch::operator=(std::move(other)); // Call base class move assignment operator
        std::swap(address, other.address);
        std::swap(employees, other.employees);
        std::swap(numEmployees, other.numEmployees);
        std::swap(maxNumEmployees, other.maxNumEmployees);
    }
    return *this;
}

// Method to add an employee
bool RegularBranch::addEmployee(const Employee& employee) 
{
    if (numEmployees == maxNumEmployees)
        return false;

    employees[numEmployees] = new Employee(employee);
    numEmployees++;
    return true;
}

// Method to remove an employee
bool RegularBranch::removeEmployee(Employee& employee) 
{
    for (int i = 0; i < numEmployees; ++i) 
    {
        if (*employees[i] == employee) 
        {
            // Shift elements to fill the gap
            for (int j = i; j < numEmployees - 1; ++j) 
            {
                employees[j] = employees[j + 1];
            }
            numEmployees--;
            return true;
        }
    }
    return false; // Employee not found
}



// Setter for address
bool RegularBranch::setAddress(const char* address) 
{
    if (address != nullptr)
    {
        delete[] this->address; // Release existing name if any
        int len = strlen(address) + 1; // +1 for null terminator
        this->address = new char[len];
        strcpy(this->address, address); // Copy the new name
        return true;
    }
    return false;
}

// Getter for employee
Employee* RegularBranch::getEmployee(int index) const
{
    if (index < 0 || index >= numEmployees)
        return nullptr;

    return employees[index];
}

void RegularBranch::displayBranchDetails()
{
    Branch::displayBranchDetails();
    cout << "Address: " <<address << endl;
    cout << "\nNumber of employees: " << numEmployees << " employee(s):\n";
    for (int i = 0; i < numEmployees; ++i)
        cout << *employees[i] << "\n"; // Employee has operator<<
}

// Output operator (ostream operator<<)
   //NOT SURE ABOUT THE IMPLEMENATION
ostream& operator<<(ostream& os, const RegularBranch& branch)
{
    os << static_cast<const Branch&>(branch); // Use Branch's operator<<
    os << "Address: " << branch.address << endl;
    os << "\nNumber of employees: " << branch.numEmployees << " employee(s):\n";
    for (int i = 0; i < branch.numEmployees; ++i)
        os << *branch.employees[i] << "\n"; // Employee has operator<<

    return os;
}