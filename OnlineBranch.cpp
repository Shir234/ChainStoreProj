#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "OnlineBranch.h"
#include <cstring> // For string operations

// Constructor
OnlineBranch::OnlineBranch(const char* name, int maxNumDepartments, const char* uml)
    : Branch(maxNumDepartments), uml(nullptr) {
    setUml(uml);
}

// Copy constructor
OnlineBranch::OnlineBranch(const OnlineBranch& other)
    : Branch(other), uml(nullptr) {
    *this = other; // Call copy assignment operator
}

// Move constructor
OnlineBranch::OnlineBranch(OnlineBranch&& other) noexcept
    : Branch(std::move(other)), uml(nullptr) {
    *this = std::move(other); // Call move assignment operator
}

// Destructor
OnlineBranch::~OnlineBranch() {
    delete[] uml;
}

// Copy assignment operator
OnlineBranch& OnlineBranch::operator=(const OnlineBranch& other) {
    if (this != &other) {
        Branch::operator=(other); // Call base class assignment operator
        setUml(other.uml);
    }
    return *this;
}

// Move assignment operator
OnlineBranch& OnlineBranch::operator=(OnlineBranch&& other) noexcept {
    if (this != &other) {
        Branch::operator=(std::move(other)); // Call base class move assignment operator
        std::swap(uml, other.uml);
    }
    return *this;
}

// Getter for UML
const char* OnlineBranch::getUml() const {
    return uml;
}

// Setter for UML
void OnlineBranch::setUml(const char* uml) {
    delete[] this->uml;
    this->uml = strdup(uml);
}
