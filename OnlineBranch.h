#ifndef ONLINEBRANCH_H
#define ONLINEBRANCH_H

#include <iostream>
#include "Branch.h"

class OnlineBranch : virtual public Branch
{
protected:
    char* url;          

public:
    OnlineBranch(const char* name, int maxNumDepartments, const char* url); // Constructor
    OnlineBranch(const OnlineBranch& other); // Copy constructor
    OnlineBranch(OnlineBranch&& other) noexcept; // Move constructor
    virtual ~OnlineBranch(); // Destructor
    OnlineBranch& operator=(const OnlineBranch& other); // Copy assignment operator
    OnlineBranch& operator=(OnlineBranch&& other) noexcept; // Move assignment operator

    const char* getUrl() const { return url; } // Getter for url
    void setUrl(const char* url); // Setter for url

   // virtual void displayBranchDetails() ;
    Branch* clone() const override { return new OnlineBranch(*this); } // Implement clone method

    // Operator overloads
   // friend ostream& operator<<(ostream& os, const OnlineBranch& branch);
    virtual void toOs(ostream& os) const override;


};

#endif // ONLINEBRANCH_H