#pragma once
#ifndef ONLINEBRANCH_H
#define ONLINEBRANCH_H

#include "Branch.h"

class OnlineBranch : virtual public Branch
{
private:
    char* uml;          //new

public:
    OnlineBranch(const char* name, int maxNumDepartments, const char* uml); // Constructor
    OnlineBranch(const OnlineBranch& other); // Copy constructor
    OnlineBranch(OnlineBranch&& other) noexcept; // Move constructor
    ~OnlineBranch(); // Destructor

    OnlineBranch& operator=(const OnlineBranch& other); // Copy assignment operator
    OnlineBranch& operator=(OnlineBranch&& other) noexcept; // Move assignment operator

    const char* getUml() const; // Getter for uml
    void setUml(const char* uml); // Setter for uml


    //std::string getUrl() const;
    //void setUrl(const std::string& url);
    //void displayBranchDetails() const override;
};

#endif // ONLINEBRANCH_H