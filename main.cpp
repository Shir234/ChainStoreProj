#include <iostream>
using namespace std;

//HELPERS OR MINI FUNCTIONS TO USE IN THE MAIN FUNCTIONS
#include "HelperFunctions.h"

int main()
{
    try
    {
        runChainStoreSystem();
    }
    catch (const exception& e)
    {
        cout << "Fatal error: " << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cout << "Unknown fatal error occurred." << endl;
        return 1;
    }
    return 0;
}



//ChainStore* store = new ChainStore("STORE", 4);
//RegularBranch br("REGULAR", 3, "Ramat-Gan", 10);
//RegularBranch br1("REGULAR222", 33, "Ramat-Gan 234", 1);

//Department dep("DEP", 3);
//br.addDepartment(dep);
//br1.addDepartment(dep);

//store->addBranch(br);
//store->addBranch(br1);

//Branch* selectedBranch = nullptr;
//Department* selectedDepartment = nullptr;

//if (!getBranchAndDepartment(store, selectedBranch, selectedDepartment))
//    return 1;
//cout << *selectedBranch << endl;
//cout << *selectedDepartment << endl;