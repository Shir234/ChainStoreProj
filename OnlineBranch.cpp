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
OnlineBranch::OnlineBranch(OnlineBranch&& other) noexcept : Branch(move(other)), url(nullptr)
{
    *this = move(other); // Call move assignment operator
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
        Branch::operator=(other);  
        OnlineBranch temp(other);  
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
        Branch::operator=(move(other)); // Call base class move assignment operator
        swap(url, other.url);
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
    cout << "ONLINE SET URL end";
}

void OnlineBranch::toOs(ostream& os) const
{
    os << "URL: " << (url ? url : "N/A") << endl;
}
