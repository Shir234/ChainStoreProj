#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "OnlineBranch.h"
#include <string> 

// Constructor
OnlineBranch::OnlineBranch(const char* name, int maxNumDepartments, const char* uml)
    : Branch(maxNumDepartments), uml(nullptr) 
{
    setUml(uml);
}

// Copy constructor
OnlineBranch::OnlineBranch(const OnlineBranch& other): Branch(other), uml(nullptr) 
{
    *this = other; // Call copy assignment operator
}

// Move constructor
OnlineBranch::OnlineBranch(OnlineBranch&& other) : Branch(std::move(other)), uml(nullptr) 
{
    *this = std::move(other); // Call move assignment operator
}

// Destructor
OnlineBranch::~OnlineBranch() 
{
    delete[] uml;
}

// Copy assignment operator
OnlineBranch& OnlineBranch::operator=(const OnlineBranch& other) 
{
    if (this != &other) 
    {
        Branch::operator=(other); // Call base class assignment operator
        setUml(other.uml);
    }
    return *this;
}

// Move assignment operator
OnlineBranch& OnlineBranch::operator=(OnlineBranch&& other) 
{
    if (this != &other) 
    {
        Branch::operator=(std::move(other)); // Call base class move assignment operator
        std::swap(uml, other.uml);
    }
    return *this;
}


// Setter for UML
bool OnlineBranch::setUml(const char* uml) 
{
    if (uml != nullptr)
    {
        delete[] this->uml; // Release existing name if any
        int len = strlen(uml) + 1; // +1 for null terminator
        this->uml = new char[len];
        strcpy(this->uml, uml); // Copy the new name
        return true;
    }
    return false;
}

// Display branch details
void OnlineBranch::displayBranchDetails()  
{
    Branch::displayBranchDetails();
    cout << "Online Branch Details:\n";
    cout << "UML: " << (uml ? uml : "N/A") << endl;
}

// Output operator (ostream operator<<)
   //NOT SURE ABOUT THE IMPLEMENATION
ostream& operator<<(ostream& os, const OnlineBranch& branch) 
{
    os << static_cast<const Branch&>(branch); // Use Branch's operator<<
    os << "UML: " << (branch.uml ? branch.uml : "N/A") << endl;
    return os;
}