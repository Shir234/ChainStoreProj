#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "RegularBranch.h"
#include "Employee.h"
#include <string> 

// Constructor
RegularBranch::RegularBranch(const char* name, int maxNumDepartments, const char* address, int maxNumEmployees)
	: Branch(name, maxNumDepartments), employees(nullptr), numEmployees(0), maxNumEmployees(maxNumEmployees), address(nullptr)
{
	if (maxNumEmployees <= 0)
		throw InvalidMaxEmployeesException();

	setAddress(address);
	employees = new Employee * [maxNumEmployees];
}

// Copy constructor
RegularBranch::RegularBranch(const RegularBranch& other)
	: Branch(other), employees(nullptr), numEmployees(0), maxNumEmployees(0), address(nullptr)
{
	try
	{
		setAddress(other.address);
		maxNumEmployees = other.maxNumEmployees;
		numEmployees = other.numEmployees;
		employees = new Employee * [maxNumEmployees];

		for (int i = 0; i < numEmployees; i++)
			employees[i] = new Employee(*other.employees[i]);
	}
	catch (const InvalidNameException& e)
	{
		employees = nullptr; // avoid double deletion
		numEmployees = 0;
		maxNumEmployees = 0;
		throw; // Re-throw exception
	}
	catch (const bad_alloc& e)
	{
		if (employees)
		{
			for (int i = 0; i < numEmployees; ++i)
				delete employees[i];
			delete[] employees;
			delete[] address;
		}
		throw MemoryAllocationException("Failed to allocate memory in copy c'tor");
	}
	catch (...)
	{
		if (employees)
		{
			for (int i = 0; i < numEmployees; ++i)
				delete employees[i];
			delete[] employees;
			delete[] address;
		}
		throw;
	}
}

// Move constructor
RegularBranch::RegularBranch(RegularBranch&& other) noexcept
	: Branch(std::move(other)), employees(nullptr), numEmployees(0), maxNumEmployees(0), address(nullptr)
{
	*this = std::move(other); // Call move assignment operator
}

// Destructor
RegularBranch::~RegularBranch()
{
	delete[] address;
	for (int i = 0; i < numEmployees; i++)
		delete employees[i];

	delete[] employees;
}

// Copy assignment operator
RegularBranch& RegularBranch::operator=(const RegularBranch& other)
{
	if (this != &other)
	{
		RegularBranch temp(other);  // Create a temporary using copy constructor
		// Swap the contents of temp with this
		swap(maxNumEmployees, temp.maxNumEmployees);
		swap(numEmployees, temp.numEmployees);
		swap(employees, temp.employees);
		swap(address, temp.address);

		// Call base class assignment operator
		Branch::operator=(other);
	}
	return *this;
}

// Move assignment operator
RegularBranch& RegularBranch::operator=(RegularBranch&& other) noexcept
{
	if (this != &other)
	{
		Branch::operator=(std::move(other)); // Call base class move assignment operator
		std::swap(address, other.address);
		std::swap(employees, other.employees);
		std::swap(numEmployees, other.numEmployees);
		std::swap(maxNumEmployees, other.maxNumEmployees);
	}
	return *this;
}

// Setter for address
void RegularBranch::setAddress(const char* address)
{
	if (address == nullptr || address[0] == '\0')
		throw InvalidNameException("Address cannot be null or empty");

	delete[] this->address;
	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
}

// Method to add an employee
void RegularBranch::addEmployee(const Employee& employee)
{
	if (isEmployeeArrayFull())
		throw EmployeeArrayFullException();

	employees[numEmployees] = new Employee(employee);
	numEmployees++;

}

void RegularBranch::toOs(ostream& os) const
{
	os << "Address: " << address << endl;
	os << "Number of employees: " << numEmployees << endl;
	for (int i = 0; i < numEmployees; ++i)
		os << "\t" << i + 1 << ") " << *employees[i]; // Employee has operator<<
}

