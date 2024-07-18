#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    char* position;

public:
    Employee(const char* name, int age, const char* position); // Constructor
    ~Employee(); // Destructor

    const char* getPosition() const;// Getter for position
    bool setPosition(const char* position); // Setter for position
    
    bool operator==(const Employee& other) const;
    friend ostream& operator<<(ostream& os, const Employee& employee); // Output operator
    virtual void toOs(ostream& os) const {}
    friend class RegularBranch;
    friend class Manager;

private:
    Employee(const Employee& other); // Copy constructor
    Employee(Employee&& other); // Move constructor
    Employee& operator=(const Employee& other); // Copy assignment operator
    Employee& operator=(Employee&& other); // Move assignment operator

};

#endif // EMPLOYEE_H
