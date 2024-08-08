#ifndef BRANCH_H
#define BRANCH_H

#include "ChaineStoreExceptions.h"

class Department;

// Abstract class
class Branch {
private:
    char* name;
    Department** departments;
    int numDepartments;
    int maxNumDepartments;

public:
    Branch(const char* name, int maxNumDepartments = 10); // Constructor
    Branch(const Branch& other);                          // Copy constructor
    Branch(Branch&& other) noexcept;                      // Move constructor
    virtual ~Branch();                                    // Destructor
    Branch& operator=(const Branch& other);               // Copy assignment operator
    Branch& operator=(Branch&& other) noexcept;           // Move assignment operator
    void addDepartment(const Department& department);     // Method to add a department
    
    // Getters and Setters
    void setName(const char* name);
    int getNumDepartments() const { return numDepartments; }
    int getMaxNumDepartments() const { return maxNumDepartments; }
    const char* getName() const { return name; }
   
    virtual Branch* clone() const = 0; // Pure virtual clone method

    // Operator overloads
    Department* operator[](int index); // Access department from array - getter for department
    friend ostream& operator<<(ostream& os, const Branch& branch);
    
    void showDepartmentArray() const;
    virtual void toOs(ostream& os) const{}
    bool isDepartmentArrayFull() const { return numDepartments >= maxNumDepartments; }
};

#endif // BRANCH_H
