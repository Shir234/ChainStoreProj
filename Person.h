#ifndef PERSON_H
#define PERSON_H

class Person {
private:
    char* name;
    int age;

    int id; // Unique ID for each Person
    static int nextId; // Static variable to track next available ID

    Person(const Person& other); // Copy constructor
    Person& operator=(const Person& other); // Copy assignment operator

public:
    Person(const char* name, int age); // Constructor
    Person(Person&& other) = delete; // Move constructor
    ~Person(); // Destructor

    Person& operator=(Person&& other) = delete; // Move assignment operator

    const char* getName() const { return name; } // Getter for name
    bool setName(const char* name); // Setter for name

    int getAge() const { return age; } // Getter for age
    bool setAge(int age); // Setter for age
    int getId() const { return id; }   // Getter for ID

    friend ostream& operator<<(ostream& os, const Person& person); // Output operator
    friend class Employee;

};

#endif // PERSON_H
