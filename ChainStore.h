#pragma once
#ifndef CHAINSTORE_H
#define CHAINSTORE_H

class Branch;

class ChainStore {
private:
    char* name;
    Branch* branches;
    int numBranches;
    int maxNumBranches;
public:
    ChainStore(const char* name, int maxNumBranches = 10);   //default c'tor
    ChainStore(const ChainStore& other);// copy c'tor
    ChainStore(ChainStore&& other); // move c'tor
    ~ChainStore();                  //d'tor

    const ChainStore& operator=(const ChainStore& other);   //operator=
    const ChainStore& operator=(ChainStore&& other);        //move operator

    void setName(const char* name);
    //set all others?

    char* getName() { return name; }
    bool addBranch(const Branch& branch);

    //void addBranch(Branch* branch);
    //std::string getName() const;
    //void setName(const std::string& name);
    //void displayChainStoreDetails() const;
};

#endif // CHAINSTORE_H