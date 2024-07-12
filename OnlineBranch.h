#ifndef ONLINEBRANCH_H
#define ONLINEBRANCH_H

#include <iostream>
#include "Branch.h"

class OnlineBranch : virtual public Branch
{
private:
    char* url;          

public:
    OnlineBranch(const char* name, int maxNumDepartments, const char* url); // Constructor
    OnlineBranch(const OnlineBranch& other); // Copy constructor
    OnlineBranch(OnlineBranch&& other); // Move constructor
    virtual ~OnlineBranch(); // Destructor

    OnlineBranch& operator=(const OnlineBranch& other); // Copy assignment operator
    OnlineBranch& operator=(OnlineBranch&& other); // Move assignment operator

    const char* getUml() const { return url; } // Getter for url
    bool setUrl(const char* url); // Setter for url

    virtual void displayBranchDetails() ;
    Branch* clone() const override; // Implement clone method

    // Operator overloads
    friend ostream& operator<<(ostream& os, const OnlineBranch& branch);
};

#endif // ONLINEBRANCH_H