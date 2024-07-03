#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "Branch.h"
#include "Department.h"

// Constructor
Branch::Branch(int maxNumDepartments) : maxNumDepartments(maxNumDepartments), numDepartments(0) {
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
Branch::~Branch() {
    delete[] departments;
}

// Copy assignment operator
Branch& Branch::operator=(const Branch& other)
{
    if (this != &other) {
        delete[] departments;
        maxNumDepartments = other.maxNumDepartments;
        numDepartments = other.numDepartments;
        departments = new Department*[maxNumDepartments];
        for (int i = 0; i < numDepartments; ++i) {
            departments[i] = new Department(*other.departments[i]);
            
        }
    }
    return *this;
}

// Move assignment operator
Branch& Branch::operator=(Branch&& other)
{
    if (this != &other) {
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

    departments[numDepartments] = new Department(department);   //or add a new one?
    numDepartments++;
    return true;
}