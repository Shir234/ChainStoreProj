#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <iostream>
using namespace std;

class InvalidNameException : public exception
{
private:
    string message;
public:
    InvalidNameException(const string& msg) : message(msg) {}
    const char* what() const noexcept override
    {
        return message.c_str();
    }
    
    //InvalidNameException() : invalid_argument("Name cannot be null or empty") {}
};


class InvalidMaxBranchesException : public invalid_argument 
{
public:
    InvalidMaxBranchesException() : invalid_argument("Branch maximum array size must be positive") {}
};

class BranchArrayFullException : public runtime_error 
{
public:
    BranchArrayFullException() : runtime_error("Branch array is full - cannot add any more branches") {}
};

class BranchIndexOutOfRangeException : public out_of_range 
{
public:
    BranchIndexOutOfRangeException() : out_of_range("Index is out of range") {}
};

class BranchNotFoundException : public runtime_error
{
public:
    BranchNotFoundException() : runtime_error("No branches in the store") {}
};

class MemoryAllocationException : public exception 
{
private:
    string message;
public:
    MemoryAllocationException(const string& msg) : message(msg) {}
    const char* what() const noexcept override 
    {
        return message.c_str();
    }
};



//EXCEPTIONS FOR ITEM

class InvalidItemPriceException : public invalid_argument 
{
public:
    InvalidItemPriceException() : invalid_argument("Item price must be positive") {}
};


///EXCEPTIONS FOR DEPARTMENT

class InvalidInventorySizeException : public invalid_argument 
{
public:
    InvalidInventorySizeException() : invalid_argument("Inventory array size must be positive") {}
};

class InventoryFullException : public runtime_error 
{
public:
    InventoryFullException() : runtime_error("Inventory is full") {}
};

class ItemNotFoundException : public runtime_error 
{
public:
    ItemNotFoundException() : runtime_error("Item not found in inventory") {}
};

//class InvalidInventoryIndexException : public out_of_range 
//{
//public:
//    InvalidInventoryIndexException() : out_of_range("Invalid inventory index") {}
//};


class DepartmentItemException : public runtime_error
{
public:
    DepartmentItemException(const string& msg) : runtime_error(msg) {}
};

class DepartmentMemoryException : public runtime_error
{
public:
    DepartmentMemoryException(const string& msg) : runtime_error(msg) {}
};

class InventoryEmptyException : public runtime_error
{
public:
    InventoryEmptyException() : runtime_error("The inventory is empty") {}
};

///EXCEPTIONS FOR BRANCH

class InvalidMaxDepartmentException : public invalid_argument
{
public:
    InvalidMaxDepartmentException() : invalid_argument("Department maximum array size must be positive") {}
};

class InvalidMaxEmployeesException : public invalid_argument
{
public:
    InvalidMaxEmployeesException() : invalid_argument("Maximum number of employees must be positive") {}
};

class DepartmentArrayFullException : public runtime_error 
{
public:
    DepartmentArrayFullException() : runtime_error("Department array is full") {}
};

class EmployeeArrayFullException : public runtime_error 
{
public:
    EmployeeArrayFullException() : runtime_error("Employee array is full") {}
};

class DepartmentNotFoundException : public runtime_error
{
public:
    DepartmentNotFoundException() : runtime_error("No departments in the branch") {}
};


///EXCEPTIONS FOR PERSON
//Added new exception for Person - age
class InvalidPersonAgeException : public invalid_argument
{
public:
    InvalidPersonAgeException() : invalid_argument("Age can be only between 1 and 120") {}
};
#endif
