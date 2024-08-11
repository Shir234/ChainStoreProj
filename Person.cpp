#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Person.h"
#include <string> 

int Person::nextId = 1; // Initialize static member variable

// Constructor
Person::Person(const char* name, int age) : name(nullptr), age(age), id(nextId++)
{
	setName(name);
	setAge(age);
}

// Copy constructor
Person::Person(const Person& other) : name(nullptr), id(nextId++)
{
	*this = other; // Call copy assignment operator
}

// Move constructor
Person::Person(Person&& other) noexcept : name(nullptr), id(nextId++)
{
	*this = std::move(other); // Call move assignment operator
}

// Copy assignment operator
Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		setAge(other.age);
		setName(other.name);
	}
	return *this;
}

// Move assignment operator
Person& Person::operator=(Person&& other) noexcept
{
	if (this != &other)
	{
		setAge(other.age);
		std::swap(name, other.name);
	}
	return *this;
}

// Destructor
Person::~Person()
{
	delete[] name;
}

// Setter for name
void Person::setName(const char* name)
{
	if (name == nullptr || name[0] == '\0')
		throw InvalidNameException("Person name cannot be null or empty");

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

// Setter for age
void Person::setAge(int age)
{
	if (age < 1 || age > 120)
		throw InvalidPersonAgeException();

	this->age = age;
}

// Output operator 
ostream& operator<<(ostream& os, const Person& person)
{
	os << "id: " << person.getId() << "\t" << "Name: " << person.getName() << "\t" << "age : " << person.getAge();
	person.toOs(os);
	return os;
}