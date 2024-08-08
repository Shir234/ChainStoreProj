#pragma warning (disable: 4996)

#include <string>
#include "Branch.h"
#include "Department.h"

// Constructor
Branch::Branch(const char* name, int maxNumDepartments) : name(nullptr), numDepartments(0), maxNumDepartments(maxNumDepartments) 
{
    if (maxNumDepartments <= 0)
        throw InvalidMaxDepartmentException();
    
    try
    {
        setName(name);
        departments = new Department * [maxNumDepartments];
        for (int i = 0; i < maxNumDepartments; ++i)
            departments[i] = nullptr;
    }
    catch (const InvalidNameException& e)
    {
        delete[] departments;
        throw;
    }
    catch (const MemoryAllocationException& e)
    {
        delete[] this->name;
        delete[] departments;
        throw MemoryAllocationException("Failed to allocate memory for departments");
    }
}

// Copy constructor
Branch::Branch(const Branch& other)
    : name(nullptr), departments(nullptr), numDepartments(0), maxNumDepartments(0)
{
    *this = other; // Call copy assignment operator
}

// Move constructor
Branch::Branch(Branch&& other) noexcept
    : name(nullptr), departments(nullptr), numDepartments(0), maxNumDepartments(0)
{
    *this = move(other); // Call move assignment operator
}

// Destructor
Branch::~Branch() 
{
    cout << "BRANCG DTOR\n";
    if (departments)
    {
        for (int i = 0; i < numDepartments; i++)
            delete departments[i];
        
        cout << "after departments delete\n";
        delete[] departments;
        cout << "after departments delete 2\n";
    }
    delete[] name;
    cout << "after NAME delete\n";
    cout << "end of dtor\n";

}

// Copy assignment operator
Branch& Branch::operator=(const Branch& other)
{
    if (this != &other)
    {
        for (int i = 0; i < numDepartments; ++i)
            delete departments[i];
        delete[] departments;

        try
        {
            setName(other.name);
            maxNumDepartments = other.maxNumDepartments;
            numDepartments = other.numDepartments;
            departments = new Department * [maxNumDepartments];

            for (int i = 0; i < numDepartments; ++i)
                departments[i] = new Department(*other.departments[i]); // department have a copy constructor

            for (int i = numDepartments; i < maxNumDepartments; ++i)
                departments[i] = nullptr;
        }
        catch (const InvalidNameException& e)
        {
            departments = nullptr; // avoid double deletion
            numDepartments = 0;
            maxNumDepartments = 0;
            throw; // Re-throw exception
        }
        catch (const bad_alloc& e)
        {
            delete[] departments;
            departments = nullptr; // avoid double deletion
            numDepartments = 0;
            maxNumDepartments = 0;
            throw MemoryAllocationException("Failed to allocate memory in copy assignment");
        }
    }
    return *this;
}

// Move assignment operator
Branch& Branch::operator=(Branch&& other) noexcept
{
    if (this != &other) 
    {
        swap(name, other.name);
        swap(departments, other.departments);
        swap(numDepartments, other.numDepartments);
        swap(maxNumDepartments, other.maxNumDepartments);

        other.name = nullptr;
        other.departments = nullptr;
        other.numDepartments = 0;
        other.maxNumDepartments = 0;
    }
    return *this;
}

// Method to add a department
void Branch::addDepartment(const Department& department)
{
    if (isDepartmentArrayFull())
        throw DepartmentArrayFullException();

    departments[numDepartments] = new Department(department); 
    numDepartments++;
}

// Setter for name
void Branch::setName(const char* name)
{
    if (name == nullptr || name[0] == '\0')
        throw InvalidNameException("Branch name cannot be null or empty");
    
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// Getter for department
Department* Branch::operator[](int index)  
{
    if (index < 0 || index >= numDepartments)
        throw BranchIndexOutOfRangeException();

    return departments[index];
}

// Output operator (ostream operator<<)
ostream& operator<<(ostream& os, const Branch& branch)
{
    os << "----------------------------------------\n";
    os << "Branch name: " << branch.name << " \n";
    os << "Number of department(s): " << branch.numDepartments << endl;
    branch.toOs(os);
    os << "department(s): \n";
    for (int i = 0; i < branch.numDepartments; ++i)
        os << i + 1 << ". "  << *branch.departments[i]; // Department has operator<<

    return os;
}

void Branch::showDepartmentArray() const
{
    for (int i = 0; i < numDepartments; i++)
        cout << i + 1 << ". " << departments[i]->getName() << "\n";
}