#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "ChainStore.h"
#include "Branch.h"
#include "RegularBranch.h"
#include "OnlineBranch.h"

// Default c'tor
ChainStore::ChainStore(const char* name, int maxNumBranches) : maxNumBranches(maxNumBranches), numBranches(0)
{
    setName(name);      
    branches = new Branch*[maxNumBranches];
}

// copy c'tor
ChainStore::ChainStore(const ChainStore& other) : name(nullptr), branches(nullptr), numBranches(0)
{
    *this = other;  // operator=
}

// move c'tor
ChainStore::ChainStore(ChainStore&& other) : name(nullptr), branches(nullptr), numBranches(0)
{
    *this = std::move(other); //call move operator
}

//d'tor
ChainStore::~ChainStore()
{
    delete[] name;
    for (int i = 0; i < numBranches; i++)
        delete branches[i];
    delete[] branches;
}

//operator=
const ChainStore& ChainStore::operator=(const ChainStore& other)
{
    if (this != &other)
    {
        setName(other.name);
        for (int i = 0; i < numBranches; i++)
            delete branches[i];
        delete[] branches;

        maxNumBranches = other.maxNumBranches;
        numBranches = other.numBranches;        //get new array size
        branches = new Branch*[maxNumBranches];    //allocate memory for branches array
        //for (int i = 0; i < numBranches; ++i)
        //    branches[i] = new Branch(*other.branches[i]);
        for (int i = 0; i < numBranches; ++i)
        {
            // Use the clone function
           branches[i] = other.branches[i]->clone();
        }
    }
    return *this;
}

//move operator
const ChainStore& ChainStore::operator=(ChainStore&& other)
{
    if (this != &other)
    {
        std::swap(name, other.name);
        std::swap(branches, other.branches);
        std::swap(numBranches, other.numBranches);
        std::swap(maxNumBranches, other.maxNumBranches);
    }
    return *this;
}

//set name 
bool ChainStore::setName(const char* name)
{
    if (name != nullptr)
    {
        delete[] this->name; // Release existing name if any
        int len = strlen(name) + 1; // +1 for null terminator
        this->name = new char[len];
        strcpy(this->name, name); // Copy the new name
        return true;
    }
    return false;
}

bool ChainStore::addBranch(const RegularBranch& branch)
{
    if (numBranches == maxNumBranches)
        return false;

 //   branches[numBranches] = new RegularBranch(branch);
    branches[numBranches] = branch.clone();
    numBranches++;
    return true;
}

bool ChainStore::addBranch(const OnlineBranch& branch)
{
    cout << "\nin online add\n";
    if (numBranches == maxNumBranches)
        return false;

    branches[numBranches] = branch.clone();
    numBranches++;
    cout << "\nend online add\n";
    return true;
}

bool ChainStore::addBranch(const OnlineRegularBranch& branch)
{
    cout << "\nin online add\n";
    if (numBranches == maxNumBranches)
        return false;

    branches[numBranches] = branch.clone();
    numBranches++;
    cout << "\nend online add\n";
    return true;
}

// Getter for branch
Branch* ChainStore::getBranch(int index) const
{
    return this->branches[index];
}

// Getter for branch
Branch* ChainStore::operator[](int index)
{
    if (index < 0 || index >= numBranches)
    {
        cout << "Invalid index, return null";
        return nullptr;
    }   

    return branches[index];
}

// Method to display all items in the department
    ///// DISPLAY PRINT EACH BRANCH AND SON DETAILS
void ChainStore::displayChainStoreDetails() const
{
    cout << "Chain Store Name: " << name << "\nNumber of Branches: " << numBranches << "\n";
    for (int i = 0; i < numBranches; ++i)
        branches[i]->displayBranchDetails() ; 
    
    cout << endl;
}

// Output operator (ostream operator<<)
    //// OS PRINT ONLY BRANCH DETAILS (no online or regular details)
ostream& operator<<(ostream& os, const ChainStore& chainStore)
{
    os << "Chain Store Name: " << chainStore.name << "\nNumber of Branches: " << chainStore.numBranches << "\n";
    for (int i = 0; i < chainStore.numBranches; ++i)
        os << *chainStore.branches[i] << "\n"; // Use Branch's operator<<
    
    return os;
}
