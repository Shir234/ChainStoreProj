#pragma once
#ifndef ONLINEREGULARBRANCH_H
#define ONLINEREGULARBRANCH_H

#include "OnlineBranch.h"
#include "RegularBranch.h"

class OnlineRegularBranch : public OnlineBranch, public RegularBranch 
{
public:
    OnlineRegularBranch(const char* name, const char* url, const char* address, int maxNumDepartments = 10, int maxNumEmployees = 50); // Constructor
    ~OnlineRegularBranch();
    virtual void displayBranchDetails();
    Branch* clone() const override; // Implement clone method

};

#endif // ONLINEREGULARBRANCH_H
