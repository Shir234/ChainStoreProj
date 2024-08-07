#pragma once
#ifndef ONLINEREGULARBRANCH_H
#define ONLINEREGULARBRANCH_H

#include "OnlineBranch.h"
#include "RegularBranch.h"

class OnlineRegularBranch : public OnlineBranch, public RegularBranch 
{
public:
    OnlineRegularBranch(const char* name, const char* url, const char* address, int maxNumDepartments = 10, int maxNumEmployees = 50); // Constructor
    OnlineRegularBranch(const OnlineRegularBranch& other) = default;
    OnlineRegularBranch(OnlineRegularBranch&& other) noexcept = default;
    OnlineRegularBranch& operator=(const OnlineRegularBranch& other) = default;
    OnlineRegularBranch& operator=(OnlineRegularBranch&& other) noexcept = default;
    ~OnlineRegularBranch() = default;
    
    Branch* clone() const override {return new OnlineRegularBranch(*this);} // Implement clone method

    virtual void toOs(ostream& os) const override;
};
#endif // ONLINEREGULARBRANCH_H
