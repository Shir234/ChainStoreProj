#ifndef PERSON_H
#define PERSON_H

#include "ChaineStoreExceptions.h"

class Person {
private:
	char* name;
	int age;

	int id;				// Unique ID for each Person
	static int nextId;  // Static variable to track next available ID
public:
	Person(const char* name, int age); // Constructor
	~Person();                         // Destructor

	const char* getName() const { return name; }
	void setName(const char* name);

	int getAge() const { return age; }
	void setAge(int age);
	int getId() const { return id; }

	virtual void toOs(ostream& os) const {}
	friend ostream& operator<<(ostream& os, const Person& person);
protected:
	Person(const Person& other);                // Copy constructor
	Person& operator=(const Person& other);     // Copy assignment operator
	Person(Person&& other) noexcept;            // Move constructor
	Person& operator=(Person&& other) noexcept; // Move assignment operator
};

#endif // PERSON_H
