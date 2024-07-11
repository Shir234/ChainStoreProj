#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    char* position;
    Employee(const Employee& other); // Copy constructor
    Employee& operator=(const Employee& other); // Copy assignment operator
public:
    Employee(const char* name, int age, const char* position); // Constructor
    Employee(Employee&& other) = delete; // Move constructor
    ~Employee(); // Destructor

    Employee& operator=(Employee&& other) = delete; // Move assignment operator

    const char* getPosition() const;// Getter for position
    bool setPosition(const char* position); // Setter for position
    
    bool operator==(const Employee& other) const;
    friend ostream& operator<<(ostream& os, const Employee& employee); // Output operator
    friend class RegularBranch;
};

#endif // EMPLOYEE_H
