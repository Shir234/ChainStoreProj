#include "ChainStore.h"
#include "Branch.h"

// Default c'tor
ChainStore::ChainStore(const char* name, int maxNumBranches) 
    : maxNumBranches(maxNumBranches), numBranches(0), name(nullptr), branches(nullptr)
{
    //check max number of branches and also throw
    if (maxNumBranches <= 0)
        throw InvalidMaxBranchesException();

    try
    {
        setName(name);
        branches = new Branch * [maxNumBranches];
    }
    catch (const InvalidNameException& e)
    {
        delete[] branches;
        throw;
    }
    catch (const MemoryAllocationException& e)
    {
        delete[] this->name;
        delete[] branches;
        throw MemoryAllocationException("Failed to allocate memory for branches");
    }

}

// copy c'tor
ChainStore::ChainStore(const ChainStore& other) : name(nullptr), branches(nullptr), numBranches(0)
{
    *this = other;  // operator=
}

// move c'tor
ChainStore::ChainStore(ChainStore&& other) noexcept : name(nullptr), branches(nullptr), numBranches(0)
{
    *this = std::move(other); //call move operator
}

//d'tor
ChainStore::~ChainStore()
{
    cout << "\nBEFORE DTOR STORE\n";
    delete[] name;
    cout << "after name delete\n";
    for (int i = 0; i < numBranches; i++)
        delete branches[i];
    cout << "after branches delete\n";
    delete[] branches;
    cout << "end of dtor\n";
}

////operator=
//const ChainStore& ChainStore::operator=(const ChainStore& other)
//{
//    if (this != &other)
//    {
//        setName(other.name);
//        for (int i = 0; i < numBranches; i++)
//            delete branches[i];
//        delete[] branches;
//
//        maxNumBranches = other.maxNumBranches;
//        numBranches = other.numBranches;        //get new array size
//        branches = new Branch*[maxNumBranches];    //allocate memory for branches array
//        //for (int i = 0; i < numBranches; ++i)
//        //    branches[i] = new Branch(*other.branches[i]);
//        for (int i = 0; i < numBranches; ++i)
//        {
//            // Use the clone function
//           branches[i] = other.branches[i]->clone();
//        }
//    }
//    return *this;
//}


//operator=
const ChainStore& ChainStore::operator=(const ChainStore& other)
{
    if (this != &other)
    {
        Branch** newBranches = nullptr;
        int successfulClones = 0;
        try
        {
            newBranches = new Branch * [other.maxNumBranches];
            // Initialize all pointers to nullptr
            for (int i = 0; i < other.maxNumBranches; ++i)
                newBranches[i] = nullptr;
            
            // Clone branches
            for (successfulClones = 0; successfulClones < other.numBranches; ++successfulClones)
            {
                newBranches[successfulClones] = other.branches[successfulClones]->clone();
            }

            setName(other.name);
            for (int j = 0; j < numBranches; j++)
                delete branches[j];
            delete[] branches;

            branches = newBranches;
            numBranches = other.numBranches;
            maxNumBranches = other.maxNumBranches;
        }
        catch (const InvalidNameException& e)
        {
            if (newBranches)
            {
                for (int j = 0; j < successfulClones; j++)
                    delete branches[j];
                delete[] branches;
            }
            throw;
        }
        catch (const bad_alloc& e)
        {
            if (newBranches)
            {
                for (int i = 0; i < successfulClones; ++i)
                    delete newBranches[i];
                delete[] newBranches;
            }
            throw MemoryAllocationException("Failed to allocate memory in copy assignment");
        }
        catch (...)
        {
            if (newBranches)
            {
                for (int i = 0; i < successfulClones; ++i)
                    delete newBranches[i];
                delete[] newBranches;
            }
            throw;
        }
    }
    return *this;
}

//move operator
const ChainStore& ChainStore::operator=(ChainStore&& other) noexcept
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
void ChainStore::setName(const char* name)
{
    if (name == nullptr || name[0] == '\0')
        throw InvalidNameException("Chain Store's name cannot be null or empty");
    
    delete[] this->name; // Release existing name if any
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name); // Copy the new name
}

void ChainStore::addBranch(const Branch& branch)
{
    if (isArrayFull())
    {
        throw BranchArrayFullException();
    }
    try
    {
        branches[numBranches] = branch.clone();
        numBranches++;
    }
    catch (const bad_alloc& e)
    {
        throw MemoryAllocationException("Failed to allocate memory for new branch");
    }
    catch (...)
    {
        throw;
    }
    //branches[numBranches] = branch.clone();
    //numBranches++;
}

//// Getter for branch
Branch* ChainStore::operator[](int index)
{
    if (index < 0 || index >= numBranches)
        throw BranchIndexOutOfRangeException();

    return branches[index];
}

// Output operator (ostream operator<<)
ostream& operator<<(ostream& os, const ChainStore& chainStore)
{
    os << "--------------------------------------------------------------------------------------------------------------------\n";
    os << "Chain Store Name: " << chainStore.name << "\nNumber of Branches: " << chainStore.numBranches << "\n";
    for (int i = 0; i < chainStore.numBranches; ++i)
        os << *chainStore.branches[i] << "\n"; // Use Branch's operator<<
    os << "--------------------------------------------------------------------------------------------------------------------\n";
    return os;
}

void ChainStore::showBranchesArray() const
{
    for (int i = 0; i < numBranches; i++)
        cout << i + 1 << ". " << branches[i]->getName() << "\n";
}