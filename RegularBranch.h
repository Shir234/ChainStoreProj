#ifndef REGULARBRANCH_H
#define REGULARBRANCH_H

#include "Branch.h"
#include "Employee.h"

class RegularBranch : virtual public Branch {
private:
    Employee** employees;
    int numEmployees;
    int maxNumEmployees;
    char* address;

public:
    RegularBranch(const char* name, int maxNumDepartments, const char* address, int maxNumEmployees = 50); // Constructor
    RegularBranch(const RegularBranch& other); // Copy constructor
    RegularBranch(RegularBranch&& other); // Move constructor
    virtual ~RegularBranch(); // Destructor

    RegularBranch& operator=(const RegularBranch& other); // Copy assignment operator
    RegularBranch& operator=(RegularBranch&& other); // Move assignment operator

    bool addEmployee(const Employee& employee); // Method to add an employee
    bool removeEmployee(Employee& employee); // Method to remove an employee by name
    const char* getAddress() const { return address; } // Getter for address
    bool setAddress(const char* address); // Setter for address
    int getNumEmployees() const { return numEmployees; }
    Employee* getEmployee(int index) const; 

    void displayBranchDetails();
    Branch* clone() const override; // Implement clone method

    // Operator overloads
    friend ostream& operator<<(ostream& os, const RegularBranch& branch);

};

#endif // REGULARBRANCH_H
