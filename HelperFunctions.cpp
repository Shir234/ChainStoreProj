#include "HelperFunctions.h"

// Utility functions
void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

bool isValidInteger(const char* str)
{
	if (str == nullptr || *str == '\0')
		return false;

	// Check for optional sign
	if (*str == '+' || *str == '-')
		str++;

	// Check for at least one digit
	if (*str == '\0')
		return false;

	// Check remaining characters
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return false;
		str++;
	}
	return true;
}

int getValidIntegerInput(const char* prompt, int minValue, int maxValue)
{
	while (true)
	{
		cout << prompt;
		char input[SIZE];
		cin.getline(input, SIZE);

		if (!isValidInteger(input))
		{
			cout << "Invalid input. Please enter a number." << endl;
			continue;
		}
		int value = atoi(input);
		if (value < minValue || value > maxValue)
		{
			cout << "Input out of range. Please enter a number between " << minValue << " and " << maxValue << "." << endl;
			continue;
		}
		return value;
	}
}

// UI functions
void displayMenu()
{
	cout << "\nMenu:\n"
		<< "1. Add a new branch\n"
		<< "2. Add a department to a branch\n"
		<< "3. Add an employee to a branch\n"
		<< "4. Add an item to inventory\n"
		<< "5. Remove an item from inventory\n"
		<< "6. Display branch details\n"
		<< "7. Display inventory details\n"
		<< "8. Display Chain Store Details\n"
		<< "9. Exit\n";
}

void displayWelcomeMsg()
{
	cout << "=============================================================================" << endl;
	cout << "                       Welcome to Chain Store Manager!" << endl;
	cout << "=============================================================================" << endl;
	cout << "Dear user," << endl;
	cout << "You are about to become a chain store manager." << endl;
	cout << "You need to choose a name for your chain store and decide the maximum branches it can grow to." << endl;
	cout << endl;
	cout << "Once you've made these initial choices, you'll have access to a menu where you can:" << endl;
	cout << "1. Create new branches (both regular and online)" << endl;
	cout << "2. Establish departments within your branches" << endl;
	cout << "3. Hire employees for your regular branches" << endl;
	cout << "4. Add items to department's inventory" << endl;
	cout << endl;
	cout << "You'll also be able to view the status of your stores, departments, and inventory at any time." << endl;
	cout << endl;
	cout << "* IMPORTANT NOTE: Employees can only be added to regular branches, not online branches.*" << endl;
	cout << endl;
	cout << "As you navigate through the system, please follow the on-screen instructions carefully." << endl;
	cout << endl;
	cout << "Good luck, and enjoy managing your new chain store!" << endl;
	cout << "=============================================================================" << endl;
	cout << endl;
}

// Chain store operations
void establishNetwork(ChainStore*& store)
{
	bool validInput = false;
	while (!validInput)
	{
		char storeName[SIZE];
		int maxNumBranches = 0;
		cout << "Enter the name of the store: ";
		cin.getline(storeName, SIZE);

		maxNumBranches = getValidIntegerInput("Enter maximum number of branches: ", 1);
		try
		{
			store = new ChainStore(storeName, maxNumBranches);
			validInput = true;
		}
		catch (InvalidMaxBranchesException& e)
		{
			cout << e.what() << endl;
			cout << "Enter valid number of branches..\n";
		}
		catch (InvalidNameException& e)
		{
			cout << e.what() << endl;
			cout << "Enter valid name for the chain store..\n";
		}
		catch (MemoryAllocationException& e)
		{
			cout << e.what() << endl;
			cout << "Error, try again..\n";
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
	char branchName[SIZE];
	int branchType, maxNumDepartments;
	char address[SIZE] = "";
	int numOfEmployees = 0;
	char urlBranch[SIZE] = "";

	cout << "\n--------- Create new branch ---------" << endl;
	Branch* newBranch = nullptr;
	bool branchCreated = false;

	while (!branchCreated)
	{
		try
		{
			if (store->isArrayFull())
				throw BranchArrayFullException();

			branchType = getValidIntegerInput("Enter the type of branch (1: Regular, 2: Online, 3: Both): ", 1, 3);
			cout << "Enter the name of the branch: ";
			cin.getline(branchName, SIZE);
			maxNumDepartments = getValidIntegerInput("Enter maximum number of departments: ", 1);

			if (branchType == 1 || branchType == 3)
			{
				cout << "Enter the address of the branch: ";
				cin.getline(address, SIZE);

				numOfEmployees = getValidIntegerInput("Enter the number of employees: ", 0);
			}
			if (branchType == 2 || branchType == 3)
			{
				cout << "Enter the branch's URL: ";
				cin.getline(urlBranch, SIZE);
			}

			newBranch = createBranch(branchType, branchName, maxNumDepartments, address, numOfEmployees, urlBranch);
			branchCreated = true;
		}
		catch (const InvalidMaxDepartmentException& e)
		{
			cout << e.what() << endl;
			cout << "Please enter a valid number of departments." << endl;
		}
		catch (const InvalidMaxEmployeesException& e)
		{
			cout << e.what() << endl;
			cout << "Please enter a valid number of employees." << endl;
		}
		catch (const InvalidNameException& e)
		{
			cout << e.what() << endl;
			cout << "Please enter a valid branch name." << endl;
		}
		catch (const invalid_argument& e)
		{
			cout << e.what() << endl;
			cout << "Please try again.\n";
		}
		catch (const bad_alloc& e)
		{
			cout << "Memory allocation failed: " << e.what() << endl;
			cout << "Please try again.\n";
		}
		catch (const BranchArrayFullException& e)
		{
			cout << e.what() << endl;
			branchCreated = true;
		}
		catch (...)
		{
			cout << "Unknown error occurred while creating employee. Please try again." << endl;
		}
	}
	if (newBranch)
	{
		try
		{
			store->addBranch(*newBranch);
			cout << "Branch was successfully added to store\n";
		}
		catch (const BranchArrayFullException& e)
		{
			cout << e.what() << endl;
			cout << "Branch was not added\n";
		}
		delete newBranch;
	}
}

void addDepartmentToBranch(ChainStore*& store)
{
	try
	{
		Branch* selectedBranch = getBranchFromStore(store);
		Department* newDepartment = nullptr;
		while (true)
		{
			try
			{
				if (selectedBranch->isDepartmentArrayFull())
					throw DepartmentArrayFullException();

				cout << "\n--------- Create new department ---------" << endl;
				char departmentName[SIZE];
				int inventoryMaxSize;

				cout << "Enter department name: ";
				cin.getline(departmentName, SIZE);
				inventoryMaxSize = getValidIntegerInput("Enter department's inventory max size: ", 1);
				newDepartment = new Department(departmentName, inventoryMaxSize);
				break;
			}
			catch (const InvalidInventorySizeException& e)
			{
				cout << e.what() << endl;
				cout << "Please enter a valid inventory size\n";
			}
			catch (const InvalidNameException& e)
			{
				cout << e.what() << endl;
				cout << "Please enter a valid department name\n";
			}
			catch (const DepartmentArrayFullException& e)
			{
				cout << e.what() << endl;
				break;
			}
			catch (...)
			{
				cout << "Unknown error occurred while creating employee. Please try again." << endl;
			}
		}
		if (newDepartment)
		{
			try
			{
				selectedBranch->addDepartment(*newDepartment);
				cout << "Department added successfully.\n";
			}
			catch (const DepartmentArrayFullException& e)
			{
				cout << e.what() << endl;
				cout << "Department was not added\n";
			}
			delete newDepartment;
		}
	}
	catch (const BranchNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const runtime_error& e)
	{
		cout << e.what() << endl;
		cout << "Cannot add department." << endl;
	}
	catch (...)
	{
		cout << "Unknown error occurred\n";
	}
}

void addEmployeeToBranch(ChainStore*& store)
{
	try
	{
		Branch* selectedBranch = getBranchFromStore(store);
		RegularBranch* regularBranch = dynamic_cast<RegularBranch*>(selectedBranch);
		if (!regularBranch)
		{
			throw AddEmployeeToNonRegularBranchException();
		}
		cout << "\n--------- Add new employee ---------" << endl;
		int employeeType = 0;
		char employeeName[SIZE];
		char position[SIZE];
		char manageDepartment[SIZE];
		int age;

		employeeType = getValidIntegerInput("Enter the type of employee to add (1: Employee, 2: Manager):", 1, 2);

		Employee* employee = nullptr;
		bool employeeCreated = false;

		while (!employeeCreated)
		{
			try
			{
				cout << "Enter employee name: ";
				cin.getline(employeeName, SIZE);

				cout << "Enter employee's age: ";
				cin >> age;

				cout << "Enter employee position: ";
				cleanBuffer();
				cin.getline(position, SIZE);

				if (employeeType == 2)
				{
					cout << "Enter manager department name to manage: ";
					cin.getline(manageDepartment, SIZE);
				}

				switch (employeeType)
				{
				case 1:
					employee = new Employee(employeeName, age, position);
					break;
				case 2:
					employee = new Manager(employeeName, age, position, manageDepartment);
					break;
				}
				employeeCreated = true;
			}
			catch (const InvalidNameException& e)
			{
				cout << e.what() << endl;
				cout << "Please try again." << endl;
			}
			catch (const InvalidPersonAgeException& e)
			{
				cout << e.what() << endl;
				cout << "Please try again." << endl;
			}
			catch (...)
			{
				cout << "Unknown error occurred while creating employee. Please try again." << endl;
			}
		}
		if (employee)
		{
			try
			{
				regularBranch->addEmployee(*employee);
				cout << "Employee added successfully\n";
			}
			catch (const EmployeeArrayFullException& e)
			{
				cout << e.what() << endl;
				cout << "Employee was not added\n";
			}
			delete employee;
		}
	}
	catch (const BranchNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const AddEmployeeToNonRegularBranchException& e)
	{
		cout << e.what() << endl;
	}
	catch (const runtime_error& e)
	{
		cout << e.what() << endl;
		cout << "Cannot add employee." << endl;
	}
	catch (const invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error occurred\n";
	}
}

void addItemToInventory(ChainStore*& store)
{
	Branch* selectedBranch = nullptr;
	Department* selectedDepartment = nullptr;
	if (!getBranchAndDepartment(store, selectedBranch, selectedDepartment))
		return;

	cout << "\n--------- Add new item ---------" << endl;
	char itemName[SIZE];
	int price;
	Item* newItem = nullptr;

	while (true)
	{
		cout << "Enter item's name: ";
		cin.getline(itemName, SIZE);
		price = getValidIntegerInput("Enter item's price:", 1);

		try
		{
			newItem = new Item(itemName, price);
			break;
		}
		catch (const InvalidNameException& e)
		{
			cout << e.what() << endl;
			cout << "Enter valid item's name..\n";
		}
		catch (const InvalidItemPriceException& e)
		{
			cout << e.what() << endl;
			cout << "Enter valid item's price..\n";
		}
		catch (...)
		{
			cout << "Unknown error occurred. Enter valid input..\n";
		}
	}
	if (newItem)
	{
		try
		{
			*selectedDepartment + *newItem;
			cout << "Item added successfully!\n";
		}
		catch (const InventoryFullException& e)
		{
			cout << e.what() << endl;
			cout << "Item was not added\n";
		}
		catch (...)
		{
			cout << "Unknown error occurred";
		}
		delete newItem;
	}
}

void removeItemFromInventory(ChainStore*& store)
{
	Branch* selectedBranch = nullptr;
	Department* selectedDepartment = nullptr;
	if (!getBranchAndDepartment(store, selectedBranch, selectedDepartment))
		return;

	try
	{
		selectedDepartment->showInventory();
	}
	catch (const InventoryEmptyException& e)
	{
		cout << e.what() << endl;
		cout << "Cannot remove item, back to menu" << endl;
		return;
	}

	int max = selectedDepartment->getNumItems();
	int itemIndex;
	itemIndex = getValidIntegerInput("\n--------- Select item number to remove: ", 1, max);

	Item* item = nullptr;
	while (true)
	{
		try
		{
			item = (*selectedDepartment)[itemIndex - 1];
			break;
		}
		catch (const BranchIndexOutOfRangeException& e)
		{
			cout << e.what() << endl;
			cout << "Please enter a valid item index." << endl;
		}
		catch (...)
		{
			cout << "Unknown error occurred, please enter a valid item index." << endl;
		}
	}
	try
	{
		*selectedDepartment - *item;
		cout << "Item removed successfully!\n";
	}
	catch (const ItemNotFoundException& e)
	{
		cout << e.what() << endl;
		cout << "Cannot remove item\n";
	}
}

void displayBranchDetails(ChainStore*& store)
{
	try
	{
		Branch* selectedBranch = getBranchFromStore(store);
		cout << *selectedBranch;
	}
	catch (const BranchNotFoundException& e)
	{
		cout << e.what() << endl;
	}

	catch (...)
	{
		cout << "Unknown error occurred." << endl;
	}
}

void displayInventoryDetails(ChainStore*& store)
{
	try
	{
		Branch* selectedBranch = getBranchFromStore(store);
		Department* selectedDepartment = getDepartmentFromBranch(selectedBranch);
		selectedDepartment->showInventory();
	}
	catch (const BranchNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const DepartmentNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const InventoryEmptyException& e)
	{
		cout << e.what() << endl;
	}
	catch (const runtime_error& e)
	{
		cout << e.what() << endl;
		cout << "Cannot show department inventory." << endl;
	}
	catch (...)
	{
		cout << "Unknown error occurred." << endl;
	}
}

void displayChainStoreDetails(ChainStore*& store)
{
	cout << *store << "\n";
}

void cleanupAndExit(ChainStore*& store)
{
	cout << *store << "\n";
	delete store;
	cout << "Exiting program. Goodbye!" << endl;
}

// Helper functions for operations
bool getBranchAndDepartment(ChainStore*& store, Branch*& selectedBranch, Department*& selectedDepartment)
{
	try
	{
		selectedBranch = getBranchFromStore(store);
		selectedDepartment = getDepartmentFromBranch(selectedBranch);
		return true;
	}
	catch (const BranchNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const DepartmentNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const runtime_error& e)
	{
		cout << e.what() << endl;
		cout << "Cannot add / remove item." << endl;
	}
	catch (...)
	{
		cout << "Unknown error occurred." << endl;
	}
	return false;
}

Branch* getBranchFromStore(ChainStore*& store)
{
	if (store->getNumBranches() == 0)
		throw BranchNotFoundException();

	cout << "\n--------- Select a branch ---------" << endl;
	store->showBranchesArray();

	Branch* selectedBranch = nullptr;
	int attempts = 0;

	while (attempts < MAX_ITERATIONS_LOOPS)
	{
		int max = store->getNumBranches();
		int branchIndex = getValidIntegerInput("Enter branch number: ", 1, max);

		try
		{
			selectedBranch = (*store)[branchIndex - 1];
			return selectedBranch;
		}
		catch (BranchIndexOutOfRangeException& e)
		{
			cout << e.what() << endl;
			cout << "Please enter a valid branch index\n";
			attempts++;
		}
		catch (...)
		{
			cout << "Unknown error occurred, try again." << endl;
			attempts++;
		}
	}
	throw runtime_error("Maximum number of attempts to select branch reached. Unable to select a branch.");
}

Department* getDepartmentFromBranch(Branch*& branch)
{
	if (branch->getNumDepartments() == 0)
		throw DepartmentNotFoundException();

	cout << "\n--------- Select a department ---------" << endl;
	branch->showDepartmentArray();

	Department* selectedDepartment = nullptr;
	int attempts = 0;
	while (attempts < MAX_ITERATIONS_LOOPS)
	{
		int max = branch->getNumDepartments();
		int departmentIndex = getValidIntegerInput("Enter department number: ", 1, max);

		try
		{
			selectedDepartment = (*branch)[departmentIndex - 1];
			return selectedDepartment;
		}
		catch (const BranchIndexOutOfRangeException& e)
		{
			cout << e.what() << endl;
			cout << "Please enter a valid department index." << endl;
			attempts++;
		}
		catch (...)
		{
			cout << "Unknown error occurred, try again." << endl;
			attempts++;
		}
	}
	throw runtime_error("Maximum number of attempts to select department reached. Unable to select a department.");
}

Branch* createBranch(int branchType, const char* name, int maxDepartments, const char* address, int numEmployees, const char* url)
{
	switch (branchType)
	{
	case 1:
		return new RegularBranch(name, maxDepartments, address, numEmployees);
	case 2:
		return new OnlineBranch(name, maxDepartments, url);
	case 3:
		return new OnlineRegularBranch(name, url, address, maxDepartments, numEmployees);
	default:
		throw invalid_argument("Invalid branch type");
	}
}

// Main system function
void runChainStoreSystem()
{
	try
	{
		displayWelcomeMsg();
		ChainStore* store = nullptr;
		establishNetwork(store);
		if (!store)
			throw runtime_error("Failed to establish network, Store is null, Exiting..");

		while (true)
		{
			displayMenu();
			int choice = getValidIntegerInput("Enter your choice: ", 1, 9);

			switch (choice)
			{
			case 1: addNewBranch(store); break;
			case 2: addDepartmentToBranch(store); break;
			case 3: addEmployeeToBranch(store); break;
			case 4: addItemToInventory(store); break;
			case 5: removeItemFromInventory(store); break;
			case 6: displayBranchDetails(store); break;
			case 7: displayInventoryDetails(store); break;
			case 8: displayChainStoreDetails(store); break;
			case 9: cleanupAndExit(store); return;
			default:
				cout << "Invalid choice. Please enter a number between 1 and 9.\n";
				break;
			}
		}
	}
	catch (const runtime_error& e)
	{
		cout << "Error: " << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
		return;
	}
}