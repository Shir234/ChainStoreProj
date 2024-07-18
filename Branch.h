#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>
using namespace std;

class Department;

class Branch {
private:
    char* name;
    Department** departments;
    int numDepartments;
    int maxNumDepartments;

public:
    Branch(const char* name, int maxNumDepartments = 10); // Constructor
    Branch(const Branch& other); // Copy constructor
    Branch(Branch&& other); // Move constructor
    virtual ~Branch(); // Destructor

    Branch& operator=(const Branch& other); // Copy assignment operator
    Branch& operator=(Branch&& other); // Move assignment operator

    bool addDepartment(const Department& department); // Method to add a department
    
    // Getters and Setters
    int getNumDepartments() const { return numDepartments; }
    int getMaxNumDepartments() const { return maxNumDepartments; }
    Department* getDepartment(int index) const; 
    const char* getName() const { return name; }; // Getter for name
    bool setName(const char* name); // Setter for name
 
    ////virtual void displayBranchDetails();
    virtual Branch* clone() const = 0; // Pure virtual clone method

    // Operator overloads
    friend ostream& operator<<(ostream& os, const Branch& branch);
    Department* operator[](int index); // Access department from array

    //////////TRY TO DO THIS INSTEAD DISPLAY
    virtual void toOs(ostream& os) const{}
    bool isDepArrayFull() const { return numDepartments >= maxNumDepartments; }
    void showDepArray() const;
};

#endif // BRANCH_H
