#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "OnlineBranch.h"
#include <string> 

// Constructor
OnlineBranch::OnlineBranch(const char* name, int maxNumDepartments, const char* url)
    : Branch(name, maxNumDepartments), url(nullptr)
{
    cout << "in online c'tor\n";
    setUrl(url);
}

// Copy constructor
OnlineBranch::OnlineBranch(const OnlineBranch& other): Branch(other), url(nullptr) 
{
    cout << "in online copy c'tor\n";
    setUrl(other.url);
    //*this = other; // Call copy assignment operator
}

// Move constructor
OnlineBranch::OnlineBranch(OnlineBranch&& other) : Branch(std::move(other)), url(nullptr) 
{
    *this = std::move(other); // Call move assignment operator
}

// Destructor
OnlineBranch::~OnlineBranch() 
{
    cout << "int online d'tor\n";
    delete[] url;
}

// Copy assignment operator
OnlineBranch& OnlineBranch::operator=(const OnlineBranch& other) 
{
    if (this != &other) 
    {
        Branch::operator=(other); // Call base class assignment operator
        cout << "after barnch call online = operator";
        setUrl(other.url);
    }
    cout << "end online = operator";
    return *this;
}

// Move assignment operator
OnlineBranch& OnlineBranch::operator=(OnlineBranch&& other) 
{
    if (this != &other) 
    {
        Branch::operator=(std::move(other)); // Call base class move assignment operator
        std::swap(url, other.url);
    }
    return *this;
}

// Setter for URL
bool OnlineBranch::setUrl(const char* url) 
{
    if (url != nullptr)
    {
        delete[] this->url; // Release existing name if any
        int len = strlen(url) + 1; // +1 for null terminator
        this->url = new char[len];
        strcpy(this->url, url); // Copy the new name
        return true;
    }
    return false;
}

//// Display branch details
//void OnlineBranch::displayBranchDetails()
//{
//    Branch::displayBranchDetails();
//    cout << "Online Branch Details:\n";
//    cout << "URL: " << (url ? url : "N/A") << endl;
//}
//
//// Output operator (ostream operator<<)
//ostream& operator<<(ostream& os, const OnlineBranch& branch) 
//{
//    os << static_cast<const Branch&>(branch); // Use Branch's operator<<
//    os << "URL: " << (branch.url ? branch.url : "N/A") << endl;
//    return os;
//}

void OnlineBranch::toOs(ostream& os) const
{
    os << "URL: " << (url ? url : "N/A") << endl;

}

//Branch* OnlineBranch::clone() const 
//{
//    cout << "in online clone";
//    return new OnlineBranch(*this);
//}