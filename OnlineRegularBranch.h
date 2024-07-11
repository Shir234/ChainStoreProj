#pragma once
#ifndef ONLINEREGULARBRANCH_H
#define ONLINEREGULARBRANCH_H

#include "OnlineBranch.h"
#include "RegularBranch.h"

class OnlineRegularBranch : public OnlineBranch, public RegularBranch 
{
public:
    OnlineRegularBranch(const char* name, const char* uml, const char* address, int maxNumDepartments = 10, int maxNumEmployees = 50); // Constructor
    virtual void displayBranchDetails();

};

#endif // ONLINEREGULARBRANCH_H
