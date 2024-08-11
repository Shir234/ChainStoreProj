#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "OnlineRegularBranch.h"

// Constructor
OnlineRegularBranch::OnlineRegularBranch(const char* name, const char* uml, const char* address, int maxNumDepartments, int maxNumEmployees)
	: Branch(name, maxNumDepartments),
	OnlineBranch(name, maxNumDepartments, uml),
	RegularBranch(name, maxNumDepartments, address, maxNumEmployees)
{

}

void OnlineRegularBranch::toOs(ostream& os) const
{
	os << "Address: " << address << endl;
	os << "Number of employees: " << numEmployees << endl;
	for (int i = 0; i < numEmployees; ++i)
		os << "\t" << i + 1 << ") " << *employees[i]; // Employee has operator<<
	os << "URL: " << (url ? url : "N/A") << endl;
}
