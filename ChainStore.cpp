#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "ChainStore.h"
#include "Branch.h"

// Default c'tor
ChainStore::ChainStore(const char* name, int maxNumBranches) : maxNumBranches(maxNumBranches), numBranches(0)
{
    this->name = strdup(name);      //later: check if not null etc...
    branches = new Branch[maxNumBranches];
}

// copy c'tor
ChainStore::ChainStore(const ChainStore& other) : name(nullptr), branches(nullptr), numBranches(0)
{
    *this = other;  //ca; operator=
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
    delete[] branches;
}

//operator=
const ChainStore& ChainStore::operator=(const ChainStore& other)
{
    if (this != &other)
    {
        setName(other.name);
        delete[] branches;                      //free current array
        maxNumBranches = other.maxNumBranches;
        numBranches = other.numBranches;        //get new array size
        branches = new Branch[maxNumBranches];    //allocate memory for branches array
        for (int i = 0; i < numBranches; ++i)
            branches[i] = other.branches[i];
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

//set name ----> change to bool and check input (validate)
void ChainStore::setName(const char* name)
{
    delete[]this->name;
    this->name = strdup(name);
}

bool ChainStore::addBranch(const Branch& branch)
{
    if (numBranches == maxNumBranches)
        return false;

    branches[numBranches] = Branch(branch);
    numBranches++;
    return true;
}