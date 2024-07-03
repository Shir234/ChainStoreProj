#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    char* position;

public:
    Employee(const char* name = "", int age = 0, const char* position = ""); // Constructor
    Employee(const Employee& other); // Copy constructor
    Employee(Employee&& other) noexcept; // Move constructor
    virtual ~Employee(); // Destructor

    Employee& operator=(const Employee& other); // Copy assignment operator
    Employee& operator=(Employee&& other) noexcept; // Move assignment operator

    const char* getPosition() const; // Getter for position
    void setPosition(const char* position); // Setter for position
};

#endif // EMPLOYEE_H
