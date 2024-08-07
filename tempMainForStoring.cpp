//#include <iostream>
//using namespace std;
//
////HELPERS OR MINI FUNCTIONS TO USE IN THE MAIN FUNCTIONS
//#include "HelperFunctions.h"
//
//void establishNetwork(ChainStore*& store);
//void addNewBranch(ChainStore*& store);
//void addDepartmentToBranch(ChainStore*& store);
//void addEmployeeToBranch(ChainStore*& store);
//void addItemToInventory(ChainStore*& store);
//void removeItemFromInventory(ChainStore*& store);
//void displayBranchDetails(ChainStore*& store);
//void displayInventoryDetails(ChainStore*& store);
//
//int main()
//{
//	ChainStore* store = nullptr;
//	establishNetwork(store);
//	bool running = true;
//
//	while (running)
//	{
//		displayMenu();
//
//		int choice = getValidIntegerInput("Enter your choice: ", 1, 9);
//
//		switch (choice)
//		{
//		case 1: addNewBranch(store); break;
//		case 2: addDepartmentToBranch(store); break;
//		case 3: addEmployeeToBranch(store); break;
//		case 4: addItemToInventory(store); break;
//		case 5:
//			try
//			{
//				removeItemFromInventory(store);
//			}
//			catch (const InventoryEmptyException& e)
//			{
//				cout << e.what() << endl;
//			}
//			break;
//		case 6: displayBranchDetails(store); break;
//		case 7: displayInventoryDetails(store); break;
//		case 8:
//			cout << *store << "\n";
//			break;
//		case 9:
//			store->showBranchesArray();
//			cout << *store << "\n";
//			delete store;
//			running = false;
//			break;
//		default:
//			cout << "Invalid choice. Please enter a number between 1 and 9.\n";
//			break;
//		}
//	}
//	return 0;
//}
//
//void establishNetwork(ChainStore*& store)
//{
//	bool validInput = false;
//	while (!validInput)
//	{
//		char storeName[SIZE];
//		int maxNumBranches = 0;
//		cout << "Enter the name of the store: ";
//		cin.getline(storeName, SIZE);
//
//		maxNumBranches = getValidIntegerInput("Enter maximum number of branches: ", 1);
//		try
//		{
//			store = new ChainStore(storeName, maxNumBranches);
//			validInput = true;
//		}
//		catch (InvalidMaxBranchesException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Enter valid input..\n";
//		}
//		catch (InvalidNameException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Enter valid input..\n";
//		}
//		catch (MemoryAllocationException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Enter valid input..\n";
//		}
//		catch (...)
//		{
//			cout << "Unknown error occurred";
//		}
//	}
//	cout << *store << endl;
//}
//
//void addNewBranch(ChainStore*& store)
//{
//	char branchName[SIZE];
//	int branchType, maxNumDepartments;
//	char address[SIZE] = "";
//	int numOfEmployees = 0;
//	char urlBranch[SIZE] = "";
//
//	cout << "\n--------- Create new branch ---------" << endl;
//	Branch* newBranch = nullptr;
//	bool branchCreated = false;
//
//	while (!branchCreated)
//	{
//		try
//		{
//			if (store->isArrayFull())
//				throw BranchArrayFullException();
//
//			branchType = getValidIntegerInput("Enter the type of branch (1: Regular, 2: Online, 3: Both): ", 1, 3);
//			cout << "Enter the name of the branch: ";
//			cin.getline(branchName, SIZE);
//			maxNumDepartments = getValidIntegerInput("Enter maximum number of departments: ", 1);
//
//			if (branchType == 1 || branchType == 3)
//			{
//				cout << "Enter the address of the branch: ";
//				cin.getline(address, SIZE);
//
//				numOfEmployees = getValidIntegerInput("Enter the number of employees: ", 0);
//			}
//			if (branchType == 2 || branchType == 3)
//			{
//				cout << "Enter the branch's URL: ";
//				cin.getline(urlBranch, SIZE);
//			}
//
//			newBranch = createBranch(branchType, branchName, maxNumDepartments, address, numOfEmployees, urlBranch);
//			branchCreated = true;
//		}
//		catch (const InvalidMaxDepartmentException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Please enter a valid number of departments." << endl;
//		}
//		catch (const InvalidMaxEmployeesException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Please enter a valid number of employees." << endl;
//		}
//		catch (const InvalidNameException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Please enter a valid branch name." << endl;
//		}
//		catch (const invalid_argument& e)
//		{
//			cout << e.what() << endl;
//			cout << "Please try again.\n";
//		}
//		catch (const bad_alloc& e)
//		{
//			cout << "Memory allocation failed: " << e.what() << endl;
//			cout << "Please try again.\n";
//		}
//		catch (const BranchArrayFullException& e)
//		{
//			cout << e.what() << endl;
//			branchCreated = true;
//		}
//		catch (...)
//		{
//			cout << "Unknown error occurred while creating employee. Please try again." << endl;
//		}
//	}
//	if (newBranch)
//	{
//		try
//		{
//			store->addBranch(*newBranch);
//			cout << "Branch was successfully added to store\n";
//		}
//		catch (const BranchArrayFullException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Branch was not added\n";
//		}
//		delete newBranch; // Clean up dynamically allocated memory
//	}
//}
//
//void addDepartmentToBranch(ChainStore*& store)
//{
//	try
//	{
//		Branch* selectedBranch = getBranchFromStore(store);
//		Department* newDepartment = nullptr;
//		while (true)
//		{
//			try
//			{
//				if (selectedBranch->isDepartmentArrayFull())
//					throw DepartmentArrayFullException();
//
//				cout << "\n--------- Create new department ---------" << endl;
//				char departmentName[SIZE];
//				int inventoryMaxSize;
//
//				cout << "Enter department name: ";
//				cin.getline(departmentName, SIZE);
//				inventoryMaxSize = getValidIntegerInput("Enter department's inventory max size: ", 1);
//				newDepartment = new Department(departmentName, inventoryMaxSize);
//				break;
//			}
//			catch (const InvalidInventorySizeException& e)
//			{
//				cout << e.what() << endl;
//				cout << "Please enter a valid inventory size\n";
//			}
//			catch (const InvalidNameException& e)
//			{
//				cout << e.what() << endl;
//				cout << "Please enter a valid department name\n";
//			}
//			catch (const DepartmentArrayFullException& e)
//			{
//				cout << e.what() << endl;
//				break;
//			}
//			catch (...)
//			{
//				cout << "Unknown error occurred while creating employee. Please try again." << endl;
//			}
//		}
//		if (newDepartment)
//		{
//			try
//			{
//				selectedBranch->addDepartment(*newDepartment);
//				cout << "Department added successfully.\n";
//			}
//			catch (const DepartmentArrayFullException& e)
//			{
//				cout << e.what() << endl;
//				cout << "Department was not added\n";
//			}
//			delete newDepartment; // Clean up dynamically allocated memory
//		}
//	}
//	catch (const BranchNotFoundException& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unknown error occurred\n";
//	}
//}
//
//void addEmployeeToBranch(ChainStore*& store)
//{
//	try
//	{
//		Branch* selectedBranch = getBranchFromStore(store);
//		RegularBranch* regularBranch = dynamic_cast<RegularBranch*>(selectedBranch);
//		if (!regularBranch)
//		{
//			throw runtime_error("Cannot add employees to Online Branch!");
//		}
//		cout << "\n--------- Add new employee ---------" << endl;
//		int employeeType = 0;
//		char employeeName[SIZE];
//		char position[SIZE];
//		char manageDepartment[SIZE];
//		int age;
//
//		employeeType = getValidIntegerInput("Enter the type of employee to add (1: Employee, 2: Manager):", 1, 2);
//
//		Employee* employee = nullptr;
//		bool employeeCreated = false;
//
//		while (!employeeCreated)
//		{
//			try
//			{
//				cout << "Enter employee name: ";
//				cin.getline(employeeName, SIZE);
//
//				cout << "Enter employee's age: ";
//				cin >> age;
//
//				cout << "Enter employee position: ";
//				cleanBuffer();
//				cin.getline(position, SIZE);
//
//				if (employeeType == 2)
//				{
//					cout << "Enter manager department name to manage: ";
//					cin.getline(manageDepartment, SIZE);
//				}
//
//				switch (employeeType)
//				{
//				case 1:
//					employee = new Employee(employeeName, age, position);
//					break;
//				case 2:
//					employee = new Manager(employeeName, age, position, manageDepartment);
//					break;
//				}
//				employeeCreated = true;
//			}
//			catch (const InvalidNameException& e)
//			{
//				cout << e.what() << endl;
//				cout << "Please try again." << endl;
//			}
//			catch (const InvalidPersonAgeException& e)
//			{
//				cout << e.what() << endl;
//				cout << "Please try again." << endl;
//			}
//			catch (...)
//			{
//				cout << "Unknown error occurred while creating employee. Please try again." << endl;
//			}
//		}
//		if (employee)
//		{
//			try
//			{
//				regularBranch->addEmployee(*employee);
//				cout << "Employee added successfully\n";
//			}
//			catch (const EmployeeArrayFullException& e)
//			{
//				cout << e.what() << endl;
//				cout << "Employee was not added\n";
//			}
//			delete employee; // Clean up dynamically allocated memory
//		}
//	}
//	catch (const BranchNotFoundException& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (const runtime_error& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (const invalid_argument& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unknown error occurred\n";
//	}
//}
//
//void addItemToInventory(ChainStore*& store)
//{
//	Branch* selectedBranch = nullptr;
//	Department* selectedDepartment = nullptr;
//	try
//	{
//		selectedBranch = getBranchFromStore(store);
//		selectedDepartment = getDepartmentFromBranch(selectedBranch);
//	}
//	catch (const BranchNotFoundException& e)
//	{
//		cout << e.what() << endl;
//		return;
//	}
//	catch (const DepartmentNotFoundException& e)
//	{
//		cout << e.what() << endl;
//		return;
//	}
//	catch (...)
//	{
//		cout << "Unknown error occurred." << endl;
//		return;
//	}
//
//	cout << "\n--------- Add new item ---------" << endl;
//	char itemName[SIZE];
//	int price;
//	Item* newItem = nullptr;
//
//	while (true)
//	{
//		cout << "Enter item's name: ";
//		cin.getline(itemName, SIZE);
//		price = getValidIntegerInput("Enter item's price:", 1);
//
//		try
//		{
//			newItem = new Item(itemName, price);
//			break;
//		}
//		catch (const InvalidNameException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Enter valid item's name..\n";
//		}
//		catch (const InvalidItemPriceException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Enter valid item's price..\n";
//		}
//		catch (...)
//		{
//			cout << "Unknown error occurred. Enter valid input..\n";
//		}
//	}
//	if (newItem)
//	{
//		try
//		{
//			selectedDepartment->addItem(*newItem);
//			cout << "Item added successfully!\n";
//		}
//		catch (const InventoryFullException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Item was not added\n";
//		}
//		catch (...)
//		{
//			cout << "Unknown error occurred";
//		}
//		delete newItem; // Clean up the dynamically allocated memory
//	}
//}
//
//void removeItemFromInventory(ChainStore*& store)
//{
//	Branch* selectedBranch = nullptr;
//	Department* selectedDepartment = nullptr;
//	try
//	{
//		selectedBranch = getBranchFromStore(store);
//		selectedDepartment = getDepartmentFromBranch(selectedBranch);
//	}
//	catch (const BranchNotFoundException& e)
//	{
//		cout << e.what() << endl;
//		return;
//	}
//	catch (const DepartmentNotFoundException& e)
//	{
//		cout << e.what() << endl;
//		return;
//	}
//	catch (...)
//	{
//		cout << "Unknown error occurred." << endl;
//		return;
//	}
//
//	if (selectedDepartment->getNumItems() == 0)
//		throw InventoryEmptyException();
//
//	selectedDepartment->showInventory();
//	int max = selectedDepartment->getNumItems();
//	int itemIndex;
//	itemIndex = getValidIntegerInput("\n--------- Select item number to remove: ", 1, max);
//
//
//	Item* item = nullptr;
//	while (true)
//	{
//		try
//		{
//			item = (*selectedDepartment)[itemIndex - 1];
//			break;
//		}
//		catch (const BranchIndexOutOfRangeException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Please enter a valid item index." << endl;
//		}
//		catch (...)
//		{
//			cout << "Unknown error occurred, please enter a valid item index." << endl;
//		}
//	}
//	try
//	{
//		selectedDepartment->removeItem(*item);
//		cout << "Item removed successfully!\n";
//	}
//	catch (const ItemNotFoundException& e)
//	{
//		cout << e.what() << endl;
//		cout << "Cannot remove item\n";
//	}
//}
//
//void displayBranchDetails(ChainStore*& store)
//{
//	try
//	{
//		Branch* selectedBranch = getBranchFromStore(store);
//		cout << *selectedBranch;
//	}
//	catch (const BranchNotFoundException& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unknown error occurred." << endl;
//	}
//}
//
//void displayInventoryDetails(ChainStore*& store)
//{
//	try
//	{
//		Branch* selectedBranch = getBranchFromStore(store);
//		Department* selectedDepartment = getDepartmentFromBranch(selectedBranch);
//		selectedDepartment->showInventory();
//	}
//	catch (const BranchNotFoundException& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (const DepartmentNotFoundException& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unknown error occurred." << endl;
//	}
//}
//
////Branch* getBranchFromStore(ChainStore*& store)
////{
////	if (store->getNumBranches() == 0)
////		throw BranchNotFoundException();
////
////	cout << "\n--------- Select a branch ---------" << endl;
////	store->showBranchesArray();
////	Branch* selectedBranch = nullptr;
////
////	bool validIndex = false;
////	
////	while (true)
////	{
////		int max = store->getNumBranches();
////		int branchIndex;
////		branchIndex = getValidIntegerInput("Enter branch number: ", 1, max);
////
////		try
////		{
////			selectedBranch = (*store)[branchIndex - 1];
////			return selectedBranch;
////		}
////		catch (BranchIndexOutOfRangeException& e)
////		{
////			cout << e.what() << endl;
////			cout << "Please enter a valid branch index\n";
////		}
////		catch (...)
////		{
////			cout << "Unknown error occurred." << endl;
////		}
////	}
////}
////
////Department* getDepartmentFromBranch(Branch*& branch)
////{
////	if (branch->getNumDepartments() == 0)
////		throw DepartmentNotFoundException();
////
////	cout << "\n--------- Select a department ---------" << endl;
////	branch->showDepArray();
////
////	Department* selectedDepartment = nullptr;
////	while (true)
////	{
////		int max = branch->getNumDepartments();
////		int departmentIndex;
////		departmentIndex = getValidIntegerInput("Enter department number: ", 1, max);
////
////		try
////		{
////			selectedDepartment = (*branch)[departmentIndex - 1];
////			return selectedDepartment;
////		}
////		catch (const BranchIndexOutOfRangeException& e)
////		{
////			cout << e.what() << endl;
////			cout << "Please enter a valid department index." << endl;
////		}
////		catch (...)
////		{
////			cout << "Unknown error occurred." << endl;
////		}
////	}
////}
//
//
////int main()
////{
////	//Department* dep = new Department("Dep1", 10); // Constructor
////	//dep->addItem(Item("item1", 100));
////	//Item* it = (*dep)[0];
////	////Item* it = dep[0];
////	//cout << *dep << endl;
////	//cout << *it << endl;
////
////	//Item* it2 = dep->[0];
////
////	RegularBranch br("First", 12, "Address Something 12", 4);
////	cout << br;
////
////	RegularBranch br2 = RegularBranch(br);
////	cout << br2;
////	ChainStore s("Store", 5);
////	cout << s;
////	s.addBranch(br);
////	cout << s;
////
////
////
////	return 0;
////}
//
//
