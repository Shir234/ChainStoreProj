#ifndef CHAINSTORE_H
#define CHAINSTORE_H

#pragma warning (disable: 4996)
#include "ChaineStoreExceptions.h"

#include <iostream>
using namespace std;

class Branch;
#include "RegularBranch.h"
#include "OnlineBranch.h"
#include "OnlineRegularBranch.h"


class ChainStore {
private:
    char* name;
    Branch** branches;
    int numBranches;
    int maxNumBranches;
public:
    ChainStore(const char* name, int maxNumBranches = 10) noexcept(false);   //default c'tor
    ChainStore(const ChainStore& other);// copy c'tor
    ChainStore(ChainStore&& other) noexcept; // move c'tor
    ~ChainStore();                  //d'tor

    const ChainStore& operator=(const ChainStore& other);   //operator=
    const ChainStore& operator=(ChainStore&& other) noexcept;        //move operator

    void setName(const char* name) noexcept(false);
    char* getName() const { return name; }
    int getNumBranches() const { return numBranches; }
    
    void addBranch(const Branch& branch) noexcept(false);
    Branch* operator[](int index) noexcept(false);

    friend ostream& operator<<(ostream& os, const ChainStore& chainStore);
    bool isArrayFull() const { return numBranches >= maxNumBranches; }
    void showBranchesArray() const;
};

#endif // CHAINSTORE_H