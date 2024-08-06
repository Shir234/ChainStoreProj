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
void addItemToInventory(ChainStore*& store);
void removeItemFromInventory(ChainStore*& store);
void displayBranchDetails(ChainStore*& store);
void displayInventoryDetails(ChainStore*& store);
Branch* getBranchFromStore(ChainStore*& store);
Department* getDepartmentFromBranch(Branch*& branch);

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
	establishNetwork(store);
	bool running = true;

	while (running)
	{
		cout << "\nMenu:\n";
		//cout << "1. Establishing a network\n";
		cout << "1. Adding a new branch\n";
		cout << "2. Adding a department to a branch\n";
		cout << "3. Adding an employee to a branch\n";
		cout << "4. Adding an item to inventory\n";
		cout << "5. Removing an item from inventory\n";
		cout << "6. Displaying branch details\n";
		cout << "7. Displaying inventory details\n";
		cout << "8. Displaying Chain Store Details\n";
		cout << "9. Exit\n";
		cout << "Enter your choice: ";

		int choice;
		if (!(cin >> choice))
		{
			cout << "Invalid input. Please enter a number between 1 and 9.\n";
			continue;
		}

		switch (choice)
		{
		case 1:
			addNewBranch(store);
			break;
		case 2:
			addDepartmentToBranch(store);
			break;
		case 3:
			addEmployeeToBranch(store);
			break;
		case 4:
			addItemToInventory(store);
			break;
		case 5:
			removeItemFromInventory(store);
			break;
		case 6:
			displayBranchDetails(store);
			break;
		case 7:
			displayInventoryDetails(store);
			break;
		case 8:
			cout << *store << "\n";
			break;
		case 9:
			delete store;
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
	bool validInput = false;
	while (!validInput)
	{
		char storeName[SIZE];
		int maxNumBranches = 0;
		cout << "Enter the name of the store: ";
		//cleanBuffer();
		cin.getline(storeName, SIZE);
		cout << "Enter maximum number of branches: ";
		cin >> maxNumBranches;
		cleanBuffer();
		
		try
		{
			//cout << "in func: name + number " << maxNumBranches << " " << storeName;
			store = new ChainStore(storeName, maxNumBranches);
			validInput = true;
		}
		catch (InvalidMaxBranchesException& e)
		{
			cout << e.what() << endl;
			cout << "Enter valid input..\n";
		}
		catch (InvalidNameException& e)
		{
			cout << e.what() << endl;
			cout << "Enter valid input..\n";
		}
		catch (MemoryAllocationException& e)
		{
			cout << e.what() << endl;
			cout << "Enter valid input..\n";

		}
		catch (...)
		{
			cout << "Unknown error occurred";
		}
	}
	
	cout << *store << endl;
}

void addNewBranch(ChainStore*& store)
{
	Branch* newBranch = nullptr;
	try
	{
		char branchName[SIZE];
		int branchType, maxNumDepartments;
		
		cout << "\n--------- Create new branch ---------" << endl;
		cout << "Enter the name of the branch: ";
		cleanBuffer();
		cin.getline(branchName, SIZE);

		cout << "Enter maximum number of departments: ";
		cin >> maxNumDepartments;
		if (maxNumDepartments < 1)
			maxNumDepartments = 10;
		do
		{
			cout << "Enter the type of branch (1: Regular, 2: Online, 3: Both): ";
			if (!(cin >> branchType) || branchType < 1 || branchType > 3)
				cout << "Invalid branch type. Please enter a number between 1 and 3.\n";
		} while (branchType < 1 || branchType > 3);
		
		char address[SIZE] = "";
		int numOfEmployees = 0;
		char urlBranch[SIZE] = "";

		if (branchType == 1 || branchType == 3)
		{
			cout << "Enter the address of the branch: ";
			cleanBuffer();
			cin.getline(address, SIZE);

			cout << "Enter the number of employees: ";
			cin >> numOfEmployees;
			if (numOfEmployees < 1)
				numOfEmployees = 10;
		}

		if (branchType == 2 || branchType == 3)
		{
			cout << "Enter the branch's URL: ";
			cleanBuffer();
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
			store->addBranch(*newBranch);
			cout << "Branch was successfully added to store\n";
			delete newBranch;
		}
	}
	catch (BranchArrayFullException& e)
	{
		cout << e.what() << endl;
		delete newBranch;
	}
	catch (...)
	{
		cout << "Unknown error occurred";
	}

}

void addDepartmentToBranch(ChainStore*& store)
{
	Branch* selectedBranch = getBranchFromStore(store);
	if (!selectedBranch)
		return;

	if (selectedBranch->isDepArrayFull())
	{
		cout << "Department array is full - cannot add any more departments\n";
		return;
	}
	cout << "\n--------- Create new department ---------" << endl;

	char departmentName[SIZE];
	int inventoryMaxSize;

	cout << "Enter department name: ";
	cleanBuffer();
	cin.getline(departmentName, SIZE);

	cout << "Enter department's inventory max size: ";
	cin >> inventoryMaxSize;

	Department newDepartment(departmentName, inventoryMaxSize);

	if (selectedBranch->addDepartment(newDepartment)) 
	{
		cout << "Department added successfully.\n";
	}
	else {
		cout << "Failed to add department. The branch may be full.\n";
	}
	return;
}

void addEmployeeToBranch(ChainStore*& store)
{
	RegularBranch* selectedBranch = dynamic_cast<RegularBranch*>(getBranchFromStore(store));
	if (!selectedBranch)
	{
		cout << "Cannot add employees to Online Branch!\n";
		return;
	}

	if (selectedBranch->isEmployeeArrFull())
	{
		cout << "Employees array is full - cannot hire more employees\n";
		return;
	}

	cout << "\n--------- Add new employee ---------" << endl;
	int employeeType;
	do
	{
		cout << "Enter the type of employee to add (1: Employee, 2: Manager): ";
		if (!(cin >> employeeType) || employeeType < 1 || employeeType > 2)
		{
			cout << "Invalid employee type. Please enter 1 or 2.\n";
		}
	} while (employeeType < 1 || employeeType > 3);

	char employeeName[SIZE];
	char position[SIZE];
	char manageDepartment[SIZE];
	int age;

	if (employeeType == 1 || employeeType == 2)
	{
		cout << "Enter employee name: ";
		cleanBuffer();
		cin.getline(employeeName, SIZE);

		cout << "Enter employee's age: ";
		cin >> age;

		cout << "Enter employee position: ";
		cleanBuffer();
		cin.getline(position, SIZE);
	}

	if (employeeType == 2)
	{
		cout << "Enter manager department name to manage: ";
		cin.getline(manageDepartment, SIZE);
	}

	Employee* employee = nullptr;
	switch (employeeType)
	{
	case 1:
		employee = new Employee(employeeName, age, position);
		break;
	case 2:
		employee = new Manager(employeeName, age, position, manageDepartment);
		break;
	}

	if (employee != nullptr)
	{
		if(selectedBranch->addEmployee(*employee))
			cout << "Employee added successfully\n";
		else
		{
			cout << "Employee was not added\n";
		}
	}
	return;
}

void addItemToInventory(ChainStore*& store)
{
	Branch* selectedBranch = getBranchFromStore(store);
	if (!selectedBranch)
		return;

	Department* selectedDepartment = getDepartmentFromBranch(selectedBranch);
	if (!selectedDepartment)
		return;

	if (selectedDepartment->isInventoryFull())
	{
		cout << "The inventory is full - cannot add more items\n";
		return;
	}
	
	cout << "\n--------- Add new item ---------" << endl;
	char itemName[SIZE];
	double price;

	cout << "Enter item's name: ";
	cleanBuffer();
	cin.getline(itemName, SIZE);

	cout << "Enter item's price: ";
	cin >> price;
	Item newItem(itemName, price);

	if(selectedDepartment->addItem(newItem))
		cout << "Item added successfully!\n";
	else
		cout << "Item was not added\n"; 
	return;
}

void removeItemFromInventory(ChainStore*& store)
{
	Branch * selectedBranch = getBranchFromStore(store);
	if (!selectedBranch)
		return;

	Department* selectedDepartment = getDepartmentFromBranch(selectedBranch);
	if (!selectedDepartment)
		return;

	if (selectedDepartment->getNumItems() == 0)
	{
		cout << "The inventory is empty - cannot remove items\n";
		return;
	}
	
	//cout << "Select an item to remove:\n";
	selectedDepartment->showInventory();
	cout << "\n--------- Select item number to remove: ";

	int itemIndex;
	do
	{
		//cout << "Enter item number: ";
		cin >> itemIndex;
		if (itemIndex < 1 || itemIndex > selectedDepartment->getNumItems())
			cout << "Invalid item selection. Please enter a valid item index\n";
	} while (itemIndex < 1 || itemIndex > selectedDepartment->getNumItems());

	Item* item = (*selectedDepartment)[itemIndex - 1];

	if (!selectedDepartment->removeItem(*item))
	{
		cout << "Cannot remove item\n";
			return;
	}
	cout << "Item removed successfully!\n";
	return;
}

void displayBranchDetails(ChainStore*& store)
{
	Branch* selectedBranch = getBranchFromStore(store);
	if (!selectedBranch)
		return;
	cout << *selectedBranch;
}

void displayInventoryDetails(ChainStore*& store)
{
	Branch* selectedBranch = getBranchFromStore(store);
	if (!selectedBranch)
		return;

	Department* selectedDepartment = getDepartmentFromBranch(selectedBranch);
	if (!selectedDepartment)
		return;

	selectedDepartment->showInventory();
}

Branch* getBranchFromStore(ChainStore*& store)
{
	bool validIndex = false;
	while (validIndex == false)
	{
		cout << "\n--------- Select a branch ---------" << endl;
		if (store->getNumBranches() == 0)
		{
			cout << "No branches in the store.\n";				
			return nullptr;
		}
		store->showBranchesArray();
		int branchIndex;
		cout << "Enter branch number: ";
		cin >> branchIndex;
		
		try
		{
			Branch* selectedBranch = (*store)[branchIndex - 1];
			validIndex = true;
			return selectedBranch;
		}
		catch(BranchIndexOutOfRangeException& e)
		{
			cout << e.what() << endl;
			cout << "Please enter a valid branch index\n";
		}
		catch (...)
		{
			cout << "Unknown error acuured";
		}
	
	}
		//do
		//{
		//	
		//	if (branchIndex < 1 || branchIndex > store->getNumBranches())
		//		cout << "Invalid branch selection. Please enter a valid branch index\n";
		//} while (branchIndex < 1 || branchIndex > store->getNumBranches());

		//

		//return selectedBranch;
}

Department* getDepartmentFromBranch(Branch*& branch)
{
	cout << "\n--------- Select a department ---------" << endl;
	if (branch->getNumDepartments() == 0)
	{
		cout << "No departments available in the branch.\n";
		return nullptr;
	}

	//cout << "Select a department:\n";
	branch->showDepArray();

	int departmentIndex;
	do
	{
		cout << "Enter department number: ";
		cin >> departmentIndex;
		if (departmentIndex < 1 || departmentIndex > branch->getNumDepartments())
			cout << "Invalid branch selection. Please enter a valid branch index\n";
	} while (departmentIndex < 1 || departmentIndex > branch->getNumDepartments());

	Department* selectedDepartment = (*branch)[departmentIndex - 1];
	return selectedDepartment;
}


//int main()
//{
//	Department* dep = new Department("Dep1", 10); // Constructor
//	dep->addItem(Item("item1", 100));
//	Item* it = (*dep)[0];
//	//Item* it = dep[0];
//	cout << *dep << endl;
//	cout << *it << endl;
//
//	//Item* it2 = dep->[0];
//
//	
//
//	return 0;
//}


