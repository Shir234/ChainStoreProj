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
    RegularBranch(const char* name, int maxNumDepartments, const char* address, int maxNumEmployees = 50);  // Constructor
    RegularBranch(const RegularBranch& other);                                                              // Copy constructor
    RegularBranch(RegularBranch&& other) noexcept;                                                          // Move constructor
    virtual ~RegularBranch();                                                                               // Destructor
    RegularBranch& operator=(const RegularBranch& other);                                                   // Copy assignment operator
    RegularBranch& operator=(RegularBranch&& other) noexcept;                                               // Move assignment operator

    void addEmployee(const Employee& employee);                                                             
 //   void removeEmployee(Employee& employee); 
    const char* getAddress() const { return address; } 
    void setAddress(const char* address); 
    int getNumEmployees() const { return numEmployees; }
//    Employee* getEmployee(int index) const; 

    virtual Branch* clone() const override { return new RegularBranch(*this); }// Implement clone method


    virtual void toOs(ostream& os) const override;
    bool isEmployeeArrayFull() const { return numEmployees >= maxNumEmployees; }
};

#endif // REGULARBRANCH_H
