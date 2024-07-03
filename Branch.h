#ifndef BRANCH_H
#define BRANCH_H

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

    //Need to add set get and display department
     
    
    //void addDepartment(Department* department);
    //const std::vector<Department*>& getDepartments() const;
    //virtual void displayBranchDetails() const = 0;
};

#endif // BRANCH_H#pragma once
