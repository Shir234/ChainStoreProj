#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <iostream>
using namespace std;

#include "ChainStore.h"
#include "Branch.h"
#include "RegularBranch.h"
#include "OnlineBranch.h"
#include "OnlineRegularBranch.h"
#include "Department.h"
#include "Item.h"
#include "Employee.h"
#include "Manager.h"

const int SIZE = 100;
const int MAX_ITERATIONS_LOOPS = 5;

// Utility functions
void cleanBuffer();
bool isValidInteger(const char* str);
int getValidIntegerInput(const char* prompt, int minValue = 0, int maxValue = 100);

// UI functions
void displayMenu();

// Chain store operations
void establishNetwork(ChainStore*& store);
void addNewBranch(ChainStore*& store);
void addDepartmentToBranch(ChainStore*& store);
void addEmployeeToBranch(ChainStore*& store);
void addItemToInventory(ChainStore*& store);
void removeItemFromInventory(ChainStore*& store);
void displayBranchDetails(ChainStore*& store);
void displayInventoryDetails(ChainStore*& store);
void displayChainStoreDetails(ChainStore*& store);
void cleanupAndExit(ChainStore*& store);

// Helper functions for operations
bool getBranchAndDepartment(ChainStore*& store, Branch*& selectedBranch, Department*& selectedDepartment);
Branch* getBranchFromStore(ChainStore*& store);
Department* getDepartmentFromBranch(Branch*& branch);
Branch* createBranch(int branchType, const char* name, int maxDepartments, const char* address, int numEmployees, const char* url);

// Main system function
void runChainStoreSystem();


#endif // HELPER_FUNCTIONS_H
