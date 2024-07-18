#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "Branch.h"
#include "Department.h"

// Constructor
Branch::Branch(const char* name, int maxNumDepartments) : name(nullptr), maxNumDepartments(maxNumDepartments), numDepartments(0)
{
    setName(name);
    departments = new Department*[maxNumDepartments];
}

// Copy constructor
Branch::Branch(const Branch& other)
    : name(nullptr), departments(nullptr), numDepartments(0), maxNumDepartments(0)
{
    *this = other; // Call copy assignment operator
}

// Move constructor
Branch::Branch(Branch&& other) 
    : name(nullptr), departments(nullptr), numDepartments(0), maxNumDepartments(0)
{
    *this = std::move(other); // Call move assignment operator
}

// Destructor
Branch::~Branch() 
{
    for (int i = 0; i < numDepartments; i++)
        delete departments[i];
    delete[] departments;
    delete[] name;
}

// Copy assignment operator
Branch& Branch::operator=(const Branch& other)
{
    if (this != &other) 
    {
        cout << "in branch =";
        delete[] name;
        for (int i = 0; i < numDepartments; i++)
            delete departments[i];
        delete[] departments;
        
        maxNumDepartments = other.maxNumDepartments;
        numDepartments = other.numDepartments;
        setName(other.name);
        departments = new Department*[maxNumDepartments];
        for (int i = 0; i < numDepartments; i++) 
            departments[i] = new Department(*other.departments[i]); 
    }
    cout << "end branch =";
    return *this;
}

// Move assignment operator
Branch& Branch::operator=(Branch&& other)
{
    if (this != &other) 
    {
        std::swap(name, other.name);
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
    return this->departments[index];
}

// Getter for department
Department* Branch::operator[](int index)  
{
    if (index < 0 || index >= numDepartments)
        return nullptr;

    return departments[index];
}

// Setter for name
bool Branch::setName(const char* name)
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
//
//void Branch::displayBranchDetails()
//{
//    cout << "Branch name: " << name << " with: " << numDepartments << " department(s) : \n";
//    for (int i = 0; i < numDepartments; ++i)
//        cout << *departments[i] << "\n"; // Department has operator<<
//}

//// Output operator (ostream operator<<)
//ostream& operator<<(ostream& os, const Branch& branch) 
//{
//    os << "Branch name: " << branch.name << " with: " << branch.numDepartments << " department(s) : \n";
//    for (int i = 0; i < branch.numDepartments; ++i) 
//        os << *branch.departments[i] << "\n"; // Department has operator<<
//    return os;
//}

// Output operator (ostream operator<<)
ostream& operator<<(ostream& os, const Branch& branch)
{
    os << "----------------------------------------\n";
    os << "Branch name: " << branch.name << " with: " << branch.numDepartments << " department(s) : \n";
    for (int i = 0; i < branch.numDepartments; ++i)
        os << *branch.departments[i] << "\n"; // Department has operator<<

    branch.toOs(os);
  //  os << "----------------------------------------\n";
    return os;
}

void Branch::showDepArray() const
{
    for (int i = 0; i < numDepartments; i++)
        cout << i + 1 << ". " << getDepartment(i)->getName() << "\n";
}