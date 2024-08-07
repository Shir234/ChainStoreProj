#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    char* position;

public:
    Employee(const char* name, int age, const char* position);  // Constructor
    ~Employee();                                                // Destructor

    const char* getPosition() const;
    void setPosition(const char* position);
    bool operator==(const Employee& other) const;
    virtual void toOs(ostream& os) const override;
    friend class RegularBranch;

protected:
    Employee(const Employee& other);                // Copy constructor
    Employee(Employee&& other) noexcept;            // Move constructor
    Employee& operator=(const Employee& other);     // Copy assignment operator
    Employee& operator=(Employee&& other) noexcept; // Move assignment operator
};

#endif // EMPLOYEE_H