#include <iostream>
using namespace std;

#include <string>

#include "Item.h"
#include "Department.h"
#include "Person.h"
#include "Employee.h"
#include "Manager.h"
#include "Branch.h"
#include "RegularBranch.h"
#include "OnlineBranch.h"
#include "OnlineRegularBranch.h"
#include "ChainStore.h"
#define SIZE 100

void establishNetwork(ChainStore*& store);
void addNewBranch(ChainStore*& store);
void addDepartmentToBranch(ChainStore*& store);
void addEmployeeToBranch(ChainStore*& store);
void addItemToInventory();
void removeItemFromInventory();
void displayBranchDetails(ChainStore*& store);
void displayInventoryDetails();
Branch* getBranchFromStore(ChainStore*& store);

//// Function to clear the input stream
void cleanBuffer() 
{
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');
}

int main()
{
    ChainStore* store = nullptr;
 
    bool running = true;

    while (running) 
    {
        cout << "\nMenu:\n";
        cout << "1. Establishing a network\n";
        cout << "2. Adding a new branch\n";
        cout << "3. Adding a department to a branch\n";
        cout << "4. Adding an employee to a branch\n";
        cout << "5. Adding an item to inventory\n";
        cout << "6. Removing an item from inventory\n";
        cout << "7. Displaying branch details\n";
        cout << "8. Displaying inventory details\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        if (!(cin >> choice)) 
        {
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            cleanBuffer();
            continue;
        }
        cleanBuffer();

        switch (choice) 
        {
        case 1:
            establishNetwork(store);
            break;
        case 2:
            addNewBranch(store);
            break;
        case 3:
            addDepartmentToBranch(store);
            break;
        case 4:
            addEmployeeToBranch(store);
            break;
        case 5:
            addItemToInventory();
            break;
        case 6:
            removeItemFromInventory();
            break;
        case 7:
            displayBranchDetails(store);
            break;
        case 8:
            displayInventoryDetails();
            break;
        case 9:
            running = false;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 9.\n";
            break;
        }
    }

    return 0;
}

void establishNetwork(ChainStore*& store)
{
    char storeName[SIZE];
    int maxNumBranches = 0;
    cout << "Enter the name of the store: ";
    cin.getline(storeName, SIZE);
    cout << "Enter maximum number of branches: ";
    cin >> maxNumBranches;
    cleanBuffer();
    store = new ChainStore(storeName, maxNumBranches);
    cout << *store << "\n";


}
void addNewBranch(ChainStore*& store)
{
    char branchName[SIZE];
    int maxNumDepartments = 0;
    Branch* newBranch = nullptr;
    int branchType;

    if (store->isArrayFull())
    {
        cout << "Branch array is full - cannot add any more branches\n";
        return;
    }
    cout << "\nEnter the name of the branch: ";
    cin.getline(branchName, SIZE);

    cout << "\nEnter maximum number of departments: ";
    cin >> maxNumDepartments;
    if (maxNumDepartments < 1)
        maxNumDepartments = 10;
    cleanBuffer();

    do {
        cout << "Enter the type of branch (1: Regular, 2: Online, 3: Both): ";
        if (!(cin >> branchType) || branchType < 1 || branchType > 3)
        {
            cout << "Invalid branch type. Please enter a number between 1 and 3.\n";
            cleanBuffer(); // Assuming cleanBuffer is a function to clear the input buffer
        }
    } while (branchType < 1 || branchType > 3);

    char address[SIZE] = "";
    int numOfEmployees = 0;
    char urlBranch[SIZE] = "";

    if (branchType == 1 || branchType == 3)
    {
        cleanBuffer();
        cout << "\nEnter the address of the branch: ";
        cin.getline(address, SIZE);
  
        cout << "Please type the number of employees: ";
        cin >> numOfEmployees;
        if (numOfEmployees < 1)
            numOfEmployees = 1;

    }

    if (branchType == 2 || branchType == 3)
    {
        cleanBuffer();
        cout << "\nEnter the branch's URL: ";
        cin.getline(urlBranch, SIZE);
    }

    switch (branchType)
    {
    case 1:
        newBranch = new RegularBranch(branchName, maxNumDepartments, address, numOfEmployees);
        break;
    case 2:
        newBranch = new OnlineBranch(branchName, maxNumDepartments, urlBranch);
        break;
    case 3:
        newBranch = new OnlineRegularBranch(branchName, urlBranch, address, maxNumDepartments, numOfEmployees);
        break;
    }

    if (newBranch != nullptr)
    {
        if(store->addBranch(*newBranch))    
            cout << "Branch was successfully added to store\n";
        else
        {
            cout << "Branch was not added\n";
        }
    }
    return;
    
    
}

void addDepartmentToBranch(ChainStore*& store)
{
  Branch* selectedBranch = getBranchFromStore(store);
  if (!selectedBranch)
  {
      return;
  }
        if (selectedBranch->isDepArrayFull())
        {
            cout << "Department array is full - cannot add any more departments\n";
            return;
        }
        // Get department details
        char departmentName[SIZE];
        int inventoryMaxSize = 0;
        cleanBuffer();
        cout << "\nEnter department name: ";
        cin.getline(departmentName, SIZE);

        cout << "\nEnter department's inventory max size: ";
        cin >> inventoryMaxSize;
       

        // Create and add department
        Department newDepartment(departmentName, inventoryMaxSize);

        if (selectedBranch->addDepartment(newDepartment)) {
            cout << "Department added successfully.\n";
        }
        else {
            cout << "Failed to add department. The branch may be full.\n";
        }
    }


void addEmployeeToBranch(ChainStore*& store)
{
    Branch* selectedBranch = getBranchFromStore(store);
    if (!selectedBranch)
    {
        return;
    }

}

void addItemToInventory() 
{
    int branchIndex, departmentIndex;
    cout << "Select the branch to add an item to (enter index): ";
    if (!(cin >> branchIndex)) 
    {
        cout << "Invalid branch selection.\n";
        cleanBuffer();
        return;
    }
    cleanBuffer();

    cout << "Select the department to add an item to (enter index): ";
    if (!(cin >> departmentIndex)) 
    {
        cout << "Invalid department selection.\n";
        cleanBuffer();
        return;
    }
    cleanBuffer();

    string itemName;
    cout << "Enter the name of the item to add to the inventory: ";
    getline(cin, itemName);
    cout << "Item '" << itemName << "' added to department " << departmentIndex << " in branch " << branchIndex << ".\n";
}

void removeItemFromInventory() 
{
    int branchIndex, departmentIndex;
    cout << "Select the branch to remove an item from (enter index): ";
    if (!(cin >> branchIndex)) 
    {
        cout << "Invalid branch selection.\n";
        cleanBuffer();
        return;
    }
    cleanBuffer();

    cout << "Select the department to remove an item from (enter index): ";
    if (!(cin >> departmentIndex)) 
    {
        cout << "Invalid department selection.\n";
        cleanBuffer();
        return;
    }
    cleanBuffer();

    string itemName;
    cout << "Enter the name of the item to remove from the inventory: ";
    getline(cin, itemName);
    cout << "Item '" << itemName << "' removed from department " << departmentIndex << " in branch " << branchIndex << ".\n";
}

void displayBranchDetails(ChainStore*& store) 
{
    cout << "Chain store details: \n" << *store;
}

void displayInventoryDetails() 
{
    cout << "Displaying inventory details.\n";
}

Branch* getBranchFromStore(ChainStore*& store)
{
    if (store->getNumBranches() == 0)
    {
        cout << "No branches available in the store.\n";
        return nullptr;
    }

    // List all branches
    cout << "Select a branch:\n";
    for (int i = 0; i < store->getNumBranches(); i++)
    {
        cout << i + 1 << ". " << store->getBranch(i)->getName() << "\n";
    }

    // Get branch selection
    int branchIndex;
    do
    {
        cout << "Enter branch number: ";
        cin >> branchIndex;
        if (branchIndex < 1 || branchIndex > store->getNumBranches())
            cout << "Invalid branch selection. Please enter a valid branch index\n";
    } while (branchIndex < 1 || branchIndex > store->getNumBranches());

    Branch* selectedBranch = store->getBranch(branchIndex - 1);
    return selectedBranch;
}