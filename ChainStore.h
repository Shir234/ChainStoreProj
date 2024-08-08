#ifndef CHAINSTORE_H
#define CHAINSTORE_H

#pragma warning (disable: 4996)
#include "ChaineStoreExceptions.h"

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
    ChainStore(const char* name, int maxNumBranches = 10);        // Constructor
    ChainStore(const ChainStore& other);                          // Copy constructor
    ChainStore(ChainStore&& other) noexcept;                      // Move constructor
    ~ChainStore();                                                // Destructor
    ChainStore& operator=(const ChainStore& other);         // Copy assignment operator
    ChainStore& operator=(ChainStore&& other) noexcept;     // Move assignment operator

    void setName(const char* name);
    char* getName() const { return name; }
    int getNumBranches() const { return numBranches; }
    
    void addBranch(const Branch& branch);
    Branch* operator[](int index);

    friend ostream& operator<<(ostream& os, const ChainStore& chainStore);
    bool isArrayFull() const { return numBranches >= maxNumBranches; }
    void showBranchesArray() const;
};

#endif // CHAINSTORE_H