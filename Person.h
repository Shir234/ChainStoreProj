#ifndef PERSON_H
#define PERSON_H

class Person {
private:
    char* name;
    int age;

    int id; // Unique ID for each Person
    static int nextId; // Static variable to track next available ID

public:
    Person(const char* name, int age); // Constructor
    ~Person(); // Destructor

    const char* getName() const { return name; } // Getter for name
    bool setName(const char* name); // Setter for name

    int getAge() const { return age; } // Getter for age
    bool setAge(int age); // Setter for age
    int getId() const { return id; }   // Getter for ID

    virtual void toOs(ostream& os) const {}
    friend ostream& operator<<(ostream& os, const Person& person); // Output operator
protected:
    Person(const Person& other); // Copy constructor
    Person& operator=(const Person& other); // Copy assignment operator
    Person(Person&& other); // Move constructor
    Person& operator=(Person&& other); // Move assignment operator
};

#endif // PERSON_H
