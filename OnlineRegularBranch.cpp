#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "OnlineRegularBranch.h"

// Constructor
OnlineRegularBranch::OnlineRegularBranch(const char* name, const char* uml, const char* address, int maxNumDepartments, int maxNumEmployees)
    : Branch(maxNumDepartments), OnlineBranch(name, maxNumDepartments, uml), RegularBranch(name, maxNumDepartments, maxNumEmployees, address) {
    // Constructor implementation, delegating to base classes
}
