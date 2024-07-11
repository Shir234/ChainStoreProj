//ChainStoreProj repository shared with anat?
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


void establishNetwork();
void addNewBranch();
void addDepartmentToBranch();
void addEmployeeToBranch();
void addItemToInventory();
void removeItemFromInventory();
void displayBranchDetails();
void displayInventoryDetails();

// Function to clear the input stream
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
            establishNetwork();
            break;
        case 2:
            addNewBranch();
            break;
        case 3:
            addDepartmentToBranch();
            break;
        case 4:
            addEmployeeToBranch();
            break;
        case 5:
            addItemToInventory();
            break;
        case 6:
            removeItemFromInventory();
            break;
        case 7:
            displayBranchDetails();
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

// Function definitions

void establishNetwork() 
{
    string networkName;
    cout << "Enter the name of the network: ";
    getline(cin, networkName);
    cout << "Network '" << networkName << "' established.\n";
}

void addNewBranch() 
{
    int branchType;
    cout << "Enter the type of branch (1: Regular, 2: Online, 3: Both): ";
    if (!(cin >> branchType) || branchType < 1 || branchType > 3) 
    {
        cout << "Invalid branch type. Please enter a number between 1 and 3.\n";
        cleanBuffer();
        return;
    }
    cleanBuffer();

    if (branchType == 1) 
    {
        string branchAddress;
        cout << "Enter the address for the new regular branch: ";
        getline(cin, branchAddress);
        cout << "Regular branch at '" << branchAddress << "' added.\n";
    }
    else if (branchType == 2) 
    {
        string branchUrl;
        cout << "Enter the URL for the new online branch: ";
        getline(cin, branchUrl);
        cout << "Online branch with URL '" << branchUrl << "' added.\n";
    }
    else if (branchType == 3) 
    {
        string branchAddress, branchUrl;
        cout << "Enter the address for the new combined branch: ";
        getline(cin, branchAddress);
        cout << "Enter the URL for the new combined branch: ";
        getline(cin, branchUrl);
        cout << "Combined branch at '" << branchAddress << "' with URL '" << branchUrl << "' added.\n";
    }
}

void addDepartmentToBranch() 
{
    int branchIndex;
    cout << "Select the branch to add a department to (enter index): ";
    if (!(cin >> branchIndex)) 
    {
        cout << "Invalid branch selection.\n";
        cleanBuffer();
        return;
    }
    cleanBuffer();

    string departmentName;
    cout << "Enter the name of the department to add: ";
    getline(cin, departmentName);
    cout << "Department '" << departmentName << "' added to branch " << branchIndex << ".\n";
}

void addEmployeeToBranch() 
{
    int branchIndex;
    cout << "Select the branch to add an employee to (enter index): ";
    if (!(cin >> branchIndex)) 
    {
        cout << "Invalid branch selection.\n";
        cleanBuffer();
        return;
    }
    cleanBuffer();

    string employeeName;
    int employeeAge;
    string employeePosition;

    cout << "Enter the name of the employee to add: ";
    getline(cin, employeeName);
    cout << "Enter the age of the employee: ";
    if (!(cin >> employeeAge)) 
    {
        cout << "Invalid input for age.\n";
        cleanBuffer();
        return;
    }
    cleanBuffer();
    cout << "Enter the position of the employee: ";
    getline(cin, employeePosition);

    cout << "Employee '" << employeeName << "' aged " << employeeAge << " added as " << employeePosition << " to branch " << branchIndex << ".\n";
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

void displayBranchDetails() 
{
    cout << "Displaying branch details.\n";
}

void displayInventoryDetails() 
{
    cout << "Displaying inventory details.\n";
}