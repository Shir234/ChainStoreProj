#ifndef REGULARBRANCH_H
#define REGULARBRANCH_H

#include "Branch.h"
#include "Employee.h"

class RegularBranch : virtual public Branch {
protected:
    Employee** employees;
    int numEmployees;
    int maxNumEmployees;
    char* address;

public:
    RegularBranch(const char* name, int maxNumDepartments, const char* address, int maxNumEmployees = 50); // Constructor
    RegularBranch(const RegularBranch& other); // Copy constructor
    RegularBranch(RegularBranch&& other) noexcept; // Move constructor
    virtual ~RegularBranch(); // Destructor
    RegularBranch& operator=(const RegularBranch& other); // Copy assignment operator
    RegularBranch& operator=(RegularBranch&& other) noexcept; // Move assignment operator

    void addEmployee(const Employee& employee); // Method to add an employee
    void removeEmployee(Employee& employee); // Method to remove an employee by name
    const char* getAddress() const { return address; } // Getter for address
    void setAddress(const char* address); // Setter for address
    int getNumEmployees() const { return numEmployees; }
    Employee* getEmployee(int index) const; 

    ////void displayBranchDetails();
    virtual Branch* clone() const override { return new RegularBranch(*this); }// Implement clone method

    // Operator overloads
    //friend ostream& operator<<(ostream& os, const RegularBranch& branch);

    virtual void toOs(ostream& os) const override;
    bool isEmployeeArrFull() const { return numEmployees >= maxNumEmployees; }
};

#endif // REGULARBRANCH_H
