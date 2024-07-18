#ifndef CHAINSTORE_H
#define CHAINSTORE_H

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
    ChainStore(const char* name, int maxNumBranches = 10);   //default c'tor
    ChainStore(const ChainStore& other);// copy c'tor
    ChainStore(ChainStore&& other); // move c'tor
    ~ChainStore();                  //d'tor

    const ChainStore& operator=(const ChainStore& other);   //operator=
    const ChainStore& operator=(ChainStore&& other);        //move operator

    bool setName(const char* name);
    char* getName() { return name; }
    int getNumBranches() { return numBranches; }
    bool addBranch(const Branch& branch);
    //bool addBranch(const RegularBranch& branch);
    //bool addBranch(const OnlineBranch& branch);
    //bool addBranch(const OnlineRegularBranch& branch);
    Branch* getBranch(int index) const;
    Branch* operator[](int index);

  ////  void displayChainStoreDetails() const;
    friend ostream& operator<<(ostream& os, const ChainStore& chainStore);
    bool isArrayFull();

};

#endif // CHAINSTORE_H