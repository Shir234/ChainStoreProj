#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "OnlineRegularBranch.h"

// Constructor
OnlineRegularBranch::OnlineRegularBranch(const char* name, const char* uml, const char* address, int maxNumDepartments, int maxNumEmployees)
    : Branch(name, maxNumDepartments), OnlineBranch(name, maxNumDepartments, uml), RegularBranch(name, maxNumDepartments, address, maxNumEmployees)
{
    
}

// Destructor
OnlineRegularBranch::~OnlineRegularBranch() 
{

}
void OnlineRegularBranch::displayBranchDetails()
{
    Branch::displayBranchDetails();
    cout << "Online Details:\n";
    cout << "UML: " << getUml();    
    cout << "\nRegular Details:\n";
    cout << "Address: " << getAddress();
    cout << "\nNumber of employees: " << getNumEmployees() << " employee(s):\n";
    for (int i = 0; i < getNumEmployees(); ++i)
        cout << *getEmployee(i) << "\n"; // Employee has operator<<
}

// Output operator (ostream operator<<)
ostream& operator<<(ostream& os, const OnlineRegularBranch& branch)
{
    os << "Branch with:" << branch.getNumDepartments() << " department(s):\n";
    for (int i = 0; i < branch.getNumDepartments(); ++i)
        os << branch.getDepartment(i) << "\n"; // Department has operator<<
    os << "UML: " << branch.getUml() << "\n";
    os << "Address: " << branch.getAddress();
    os << "\nNumber of employees: " << branch.getNumEmployees() << " employee(s):\n";
    for (int i = 0; i < branch.getNumEmployees(); ++i)
        os << branch.getEmployee(i) << "\n"; // Employee has operator<<

    return os;
}

Branch* OnlineRegularBranch::clone() const
{
    return new OnlineRegularBranch(*this);
}