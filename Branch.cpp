#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "Branch.h"
#include "Department.h"

// Constructor
Branch::Branch(int maxNumDepartments) : maxNumDepartments(maxNumDepartments), numDepartments(0) 
{
    departments = new Department*[maxNumDepartments];
}

// Copy constructor
Branch::Branch(const Branch& other)
    : departments(nullptr), numDepartments(0), maxNumDepartments(0)
{
    *this = other; // Call copy assignment operator
}

// Move constructor
Branch::Branch(Branch&& other) 
    : departments(nullptr), numDepartments(0), maxNumDepartments(0)
{
    *this = std::move(other); // Call move assignment operator
}

// Destructor
Branch::~Branch() 
{
    for (int i = 0; i < numDepartments; i++)
        delete departments[i];
    delete[] departments;
}

// Copy assignment operator
Branch& Branch::operator=(const Branch& other)
{
    if (this != &other) 
    {
        for (int i = 0; i < numDepartments; i++)
            delete departments[i];
        delete[] departments;
        
        maxNumDepartments = other.maxNumDepartments;
        numDepartments = other.numDepartments;
        departments = new Department*[maxNumDepartments];
        for (int i = 0; i < numDepartments; i++) 
            departments[i] = new Department(*other.departments[i]); 
    }
    return *this;
}

// Move assignment operator
Branch& Branch::operator=(Branch&& other)
{
    if (this != &other) 
    {
        std::swap(departments, other.departments);
        std::swap(numDepartments, other.numDepartments);
        std::swap(maxNumDepartments, other.maxNumDepartments);
    }
    return *this;
}

// Method to add a department
bool Branch::addDepartment(const Department& department)
{
    if (numDepartments == maxNumDepartments)
        return false;

    departments[numDepartments] = new Department(department); 
    numDepartments++;
    return true;
}

// Getter for department
Department* Branch::getDepartment(int index) const 
{
    if (index < 0 || index >= numDepartments)
        return nullptr;

    return departments[index];
}

void Branch::displayBranchDetails()
{
    cout << "Branch with:" << numDepartments << " department(s):\n";
    for (int i = 0; i < numDepartments; ++i)
        cout << *departments[i] << "\n"; // Department has operator<<
}

// Getter for department
Department* Branch::operator[](int index)  
{
    if (index < 0 || index >= numDepartments)
        return nullptr;

    return departments[index];
}

// Output operator (ostream operator<<)
ostream& operator<<(ostream& os, const Branch& branch) 
{
    os << "Branch with:" << branch.numDepartments << " department(s):\n";
    for (int i = 0; i < branch.numDepartments; ++i) 
        os << *branch.departments[i] << "\n"; // Department has operator<<
   
    return os;
}