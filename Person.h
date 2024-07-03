#ifndef PERSON_H
#define PERSON_H

class Person {
private:
    char* name;
    int age;

public:
    Person(const char* name, int age = 0); // Constructor
    Person(const Person& other); // Copy constructor
    Person(Person&& other) ; // Move constructor
    virtual ~Person(); // Destructor

    Person& operator=(const Person& other); // Copy assignment operator
    Person& operator=(Person&& other) ; // Move assignment operator

    const char* getName() const; // Getter for name
    void setName(const char* name); // Setter for name

    int getAge() const; // Getter for age
    void setAge(int age); // Setter for age
};

#endif // PERSON_H
