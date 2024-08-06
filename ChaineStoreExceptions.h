#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <iostream>
using namespace std;

class InvalidNameException : public invalid_argument 
{
public:
    InvalidNameException() : invalid_argument("Name cannot be null or empty") {}
};

class InvalidMaxBranchesException : public invalid_argument 
{
public:
    InvalidMaxBranchesException() : invalid_argument("Maximum number of branches must be positive") {}
};

class BranchArrayFullException : public runtime_error 
{
public:
    BranchArrayFullException() : runtime_error("Branch array is full - cannot add any more branches") {}
};

class BranchIndexOutOfRangeException : public out_of_range 
{
public:
    BranchIndexOutOfRangeException() : out_of_range("Branch index is out of range") {}
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
class InvalidItemNameException : public invalid_argument 
{
public:
    InvalidItemNameException() : invalid_argument("Item name cannot be null or empty") {}
};

class InvalidItemPriceException : public invalid_argument 
{
public:
    InvalidItemPriceException() : invalid_argument("Item price must be positive") {}
};


///EXCEPTIONS FOR DEPARTMENT
class InvalidDepartmentNameException : public invalid_argument 
{
public:
    InvalidDepartmentNameException() : invalid_argument("Department name cannot be null or empty") {}
};

class InvalidInventorySizeException : public invalid_argument 
{
public:
    InvalidInventorySizeException() : invalid_argument("Inventory size must be positive") {}
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

class InvalidInventoryIndexException : public out_of_range 
{
public:
    InvalidInventoryIndexException() : out_of_range("Invalid inventory index") {}
};


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
#endif
