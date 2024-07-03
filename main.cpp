#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
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
//#include "FunctionDeclarations.h"

void establishNetwork();
void addNewBranch();
void addDepartmentToBranch();
void addEmployeeToBranch();
void addItemToInventory();
void removeItemFromInventory();
void displayBranchDetails();
void displayInventoryDetails();

// Function to clear the input stream
void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    bool running = true;

    while (running) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Establishing a network\n";
        std::cout << "2. Adding a new branch\n";
        std::cout << "3. Adding a department to a branch\n";
        std::cout << "4. Adding an employee to a branch\n";
        std::cout << "5. Adding an item to inventory\n";
        std::cout << "6. Removing an item from inventory\n";
        std::cout << "7. Displaying branch details\n";
        std::cout << "8. Displaying inventory details\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 1 and 9.\n";
            clearInputStream();
            continue;
        }
        clearInputStream();

        switch (choice) {
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
            std::cout << "Invalid choice. Please enter a number between 1 and 9.\n";
            break;
        }
    }

    return 0;
}

// Function definitions

void establishNetwork() {
    std::string networkName;
    std::cout << "Enter the name of the network: ";
    std::getline(std::cin, networkName);
    std::cout << "Network '" << networkName << "' established.\n";
}

void addNewBranch() {
    int branchType;
    std::cout << "Enter the type of branch (1: Regular, 2: Online, 3: Both): ";
    if (!(std::cin >> branchType) || branchType < 1 || branchType > 3) {
        std::cout << "Invalid branch type. Please enter a number between 1 and 3.\n";
        clearInputStream();
        return;
    }
    clearInputStream();

    if (branchType == 1) {
        std::string branchAddress;
        std::cout << "Enter the address for the new regular branch: ";
        std::getline(std::cin, branchAddress);
        std::cout << "Regular branch at '" << branchAddress << "' added.\n";
    }
    else if (branchType == 2) {
        std::string branchUrl;
        std::cout << "Enter the URL for the new online branch: ";
        std::getline(std::cin, branchUrl);
        std::cout << "Online branch with URL '" << branchUrl << "' added.\n";
    }
    else if (branchType == 3) {
        std::string branchAddress, branchUrl;
        std::cout << "Enter the address for the new combined branch: ";
        std::getline(std::cin, branchAddress);
        std::cout << "Enter the URL for the new combined branch: ";
        std::getline(std::cin, branchUrl);
        std::cout << "Combined branch at '" << branchAddress << "' with URL '" << branchUrl << "' added.\n";
    }
}

void addDepartmentToBranch() {
    int branchIndex;
    std::cout << "Select the branch to add a department to (enter index): ";
    if (!(std::cin >> branchIndex)) {
        std::cout << "Invalid branch selection.\n";
        clearInputStream();
        return;
    }
    clearInputStream();

    std::string departmentName;
    std::cout << "Enter the name of the department to add: ";
    std::getline(std::cin, departmentName);
    std::cout << "Department '" << departmentName << "' added to branch " << branchIndex << ".\n";
}

void addEmployeeToBranch() {
    int branchIndex;
    std::cout << "Select the branch to add an employee to (enter index): ";
    if (!(std::cin >> branchIndex)) {
        std::cout << "Invalid branch selection.\n";
        clearInputStream();
        return;
    }
    clearInputStream();

    std::string employeeName;
    int employeeAge;
    std::string employeePosition;

    std::cout << "Enter the name of the employee to add: ";
    std::getline(std::cin, employeeName);
    std::cout << "Enter the age of the employee: ";
    if (!(std::cin >> employeeAge)) {
        std::cout << "Invalid input for age.\n";
        clearInputStream();
        return;
    }
    clearInputStream();
    std::cout << "Enter the position of the employee: ";
    std::getline(std::cin, employeePosition);

    std::cout << "Employee '" << employeeName << "' aged " << employeeAge << " added as " << employeePosition << " to branch " << branchIndex << ".\n";
}

void addItemToInventory() {
    int branchIndex, departmentIndex;
    std::cout << "Select the branch to add an item to (enter index): ";
    if (!(std::cin >> branchIndex)) {
        std::cout << "Invalid branch selection.\n";
        clearInputStream();
        return;
    }
    clearInputStream();

    std::cout << "Select the department to add an item to (enter index): ";
    if (!(std::cin >> departmentIndex)) {
        std::cout << "Invalid department selection.\n";
        clearInputStream();
        return;
    }
    clearInputStream();

    std::string itemName;
    std::cout << "Enter the name of the item to add to the inventory: ";
    std::getline(std::cin, itemName);
    std::cout << "Item '" << itemName << "' added to department " << departmentIndex << " in branch " << branchIndex << ".\n";
}

void removeItemFromInventory() {
    int branchIndex, departmentIndex;
    std::cout << "Select the branch to remove an item from (enter index): ";
    if (!(std::cin >> branchIndex)) {
        std::cout << "Invalid branch selection.\n";
        clearInputStream();
        return;
    }
    clearInputStream();

    std::cout << "Select the department to remove an item from (enter index): ";
    if (!(std::cin >> departmentIndex)) {
        std::cout << "Invalid department selection.\n";
        clearInputStream();
        return;
    }
    clearInputStream();

    std::string itemName;
    std::cout << "Enter the name of the item to remove from the inventory: ";
    std::getline(std::cin, itemName);
    std::cout << "Item '" << itemName << "' removed from department " << departmentIndex << " in branch " << branchIndex << ".\n";
}

void displayBranchDetails() {
    std::cout << "Displaying branch details.\n";
}

void displayInventoryDetails() {
    std::cout << "Displaying inventory details.\n";
}