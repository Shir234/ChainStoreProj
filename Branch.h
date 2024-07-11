#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>
using namespace std;

class Department;

class Branch {
private:
    Department** departments;
    int numDepartments;
    int maxNumDepartments;

public:
    Branch(int maxNumDepartments = 10); // Constructor
    Branch(const Branch& other); // Copy constructor
    Branch(Branch&& other); // Move constructor
    virtual ~Branch(); // Destructor

    Branch& operator=(const Branch& other); // Copy assignment operator
    Branch& operator=(Branch&& other); // Move assignment operator

    bool addDepartment(const Department& department); // Method to add a department
    
    // Getters and Setters
    int getNumDepartments() const { return numDepartments; }
    int getMaxNumDepartments() const { return maxNumDepartments; }
    Department* getDepartment(int index) const; //DO WE NEED THIS?

    virtual void displayBranchDetails();        //CANNOT BE PURE VIRTUAL FUNCTION!!
   
    // Operator overloads
    friend ostream& operator<<(ostream& os, const Branch& branch);
    Department* operator[](int index); // Access department from array

};

#endif // BRANCH_H
