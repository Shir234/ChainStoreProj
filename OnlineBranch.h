#ifndef ONLINEBRANCH_H
#define ONLINEBRANCH_H

#include <iostream>
#include "Branch.h"

class OnlineBranch : virtual public Branch
{
private:
    char* uml;          

public:
    OnlineBranch(const char* name, int maxNumDepartments, const char* uml); // Constructor
    OnlineBranch(const OnlineBranch& other); // Copy constructor
    OnlineBranch(OnlineBranch&& other); // Move constructor
    virtual ~OnlineBranch(); // Destructor

    OnlineBranch& operator=(const OnlineBranch& other); // Copy assignment operator
    OnlineBranch& operator=(OnlineBranch&& other); // Move assignment operator

    const char* getUml() const { return uml; } // Getter for uml
    bool setUml(const char* uml); // Setter for uml

    virtual void displayBranchDetails() ;

    // Operator overloads
    //NOT SURE ABOUT THE IMPLEMENATION
    friend ostream& operator<<(ostream& os, const OnlineBranch& branch);
};

#endif // ONLINEBRANCH_H