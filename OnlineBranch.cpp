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
    try
    {
        setUrl(other.url);
    }
    catch (...)
    {
        delete[] url;
        throw;
    }
}

// Move constructor
OnlineBranch::OnlineBranch(OnlineBranch&& other) noexcept : Branch(std::move(other)), url(nullptr)
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
        OnlineBranch temp(other);  // This might throw, but *this is still intact
        // Swap the contents of temp with this
        swap(url, temp.url);
    }
    cout << "end online = operator";
    return *this;
}

// Move assignment operator
OnlineBranch& OnlineBranch::operator=(OnlineBranch&& other) noexcept
{
    if (this != &other) 
    {
        Branch::operator=(std::move(other)); // Call base class move assignment operator
        std::swap(url, other.url);
    }
    return *this;
}


// Setter for URL
void OnlineBranch::setUrl(const char* url) 
{
    if (url == nullptr || url[0] == '\0')
        throw InvalidNameException("URL cannot be null or empty");
    
    char* newUrl = new char[strlen(url) + 1];
    strcpy(newUrl, url);
    delete[] this->url;
    this->url = newUrl;

    //cout << "ONLINE SET URL BEFORE DELETE";
    //delete[] this->url;
    //cout << "ONLINE SET URL after DELETE";
    //this->url = new char[strlen(url) + 1];
    //strcpy(this->url, url);
    cout << "ONLINE SET URL end";
    //if (url != nullptr)
    //{
    //    delete[] this->url; // Release existing name if any
    //    int len = strlen(url) + 1; // +1 for null terminator
    //    this->url = new char[len];
    //    strcpy(this->url, url); // Copy the new name
    //    return true;
    //}
    //return false;
}


void OnlineBranch::toOs(ostream& os) const
{
    os << "URL: " << (url ? url : "N/A") << endl;

}
