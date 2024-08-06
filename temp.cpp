//
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
//		
//	Branch* newBranch = nullptr;
//	bool branchCreated = false;
//		
//	while (!branchCreated)
//	{
//		try
//		{
//			do
//			{
//				cout << "Enter the type of branch (1: Regular, 2: Online, 3: Both): ";
//				if (!(cin >> branchType) || branchType < 1 || branchType > 3)
//					throw invalid_argument("Invalid branch type. Please enter a number between 1 and 3.");
//			} while (branchType < 1 || branchType > 3);
//
//			cout << "Enter the name of the branch: ";
//			cleanBuffer();
//			cin.getline(branchName, SIZE);
//
//			cout << "Enter maximum number of departments: ";
//			cin >> maxNumDepartments;
//
//			if (branchType == 1 || branchType == 3)
//			{
//				cout << "Enter the address of the branch: ";
//				cleanBuffer();
//				cin.getline(address, SIZE);
//
//				cout << "Enter the number of employees: ";
//				cin >> numOfEmployees;
//				//if (numOfEmployees < 1)
//				//	throw invalid_argument("Number of employees must be at least 1.");
//			}
//			if (branchType == 2 || branchType == 3)
//			{
//				cout << "Enter the branch's URL: ";
//				cleanBuffer();
//				cin.getline(urlBranch, SIZE);
//			}
//			switch (branchType)
//			{
//			case 1:
//				newBranch = new RegularBranch(branchName, maxNumDepartments, address, numOfEmployees);
//				break;
//			case 2:
//				newBranch = new OnlineBranch(branchName, maxNumDepartments, urlBranch);
//				break;
//			case 3:
//				newBranch = new OnlineRegularBranch(branchName, urlBranch, address, maxNumDepartments, numOfEmployees);
//				break;
//			}
//
//			branchCreated = true;
//		}
//		catch (const InvalidMaxBranchesException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Please enter a valid departments array size\n";
//		}
//		catch (const InvalidNameException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Please enter a valid branch name\n";
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
//
//
//
//
//
//
/////OLD FUNCTIONS
//void addNewBranch(ChainStore*& store)
//{
//	Branch* newBranch = nullptr;
//	try
//	{
//		char branchName[SIZE];
//		int branchType, maxNumDepartments;
//
//		cout << "\n--------- Create new branch ---------" << endl;
//		cout << "Enter the name of the branch: ";
//		cleanBuffer();
//		cin.getline(branchName, SIZE);
//
//		cout << "Enter maximum number of departments: ";
//		cin >> maxNumDepartments;
//		if (maxNumDepartments < 1)
//			maxNumDepartments = 10;
//		do
//		{
//			cout << "Enter the type of branch (1: Regular, 2: Online, 3: Both): ";
//			if (!(cin >> branchType) || branchType < 1 || branchType > 3)
//				cout << "Invalid branch type. Please enter a number between 1 and 3.\n";
//		} while (branchType < 1 || branchType > 3);
//
//		char address[SIZE] = "";
//		int numOfEmployees = 0;
//		char urlBranch[SIZE] = "";
//
//		if (branchType == 1 || branchType == 3)
//		{
//			cout << "Enter the address of the branch: ";
//			cleanBuffer();
//			cin.getline(address, SIZE);
//
//			cout << "Enter the number of employees: ";
//			cin >> numOfEmployees;
//			if (numOfEmployees < 1)
//				numOfEmployees = 10;
//		}
//
//		if (branchType == 2 || branchType == 3)
//		{
//			cout << "Enter the branch's URL: ";
//			cleanBuffer();
//			cin.getline(urlBranch, SIZE);
//		}
//
//		switch (branchType)
//		{
//		case 1:
//			newBranch = new RegularBranch(branchName, maxNumDepartments, address, numOfEmployees);
//			break;
//		case 2:
//			newBranch = new OnlineBranch(branchName, maxNumDepartments, urlBranch);
//			break;
//		case 3:
//			newBranch = new OnlineRegularBranch(branchName, urlBranch, address, maxNumDepartments, numOfEmployees);
//			break;
//		}
//		if (newBranch != nullptr)
//		{
//			store->addBranch(*newBranch);
//			cout << "Branch was successfully added to store\n";
//			delete newBranch;
//		}
//	}
//	catch (BranchArrayFullException& e)
//	{
//		cout << e.what() << endl;
//		delete newBranch;
//	}
//	catch (...)
//	{
//		cout << "Unknown error occurred";
//	}
//
//}
//
//void addDepartmentToBranch(ChainStore*& store)
//{
//	Branch* selectedBranch = getBranchFromStore(store);
//	if (!selectedBranch)
//		return;
//
//	if (selectedBranch->isDepArrayFull())
//	{
//		cout << "Department array is full - cannot add any more departments\n";
//		return;
//	}
//	cout << "\n--------- Create new department ---------" << endl;
//
//	char departmentName[SIZE];
//	int inventoryMaxSize;
//
//	cout << "Enter department name: ";
//	cleanBuffer();
//	cin.getline(departmentName, SIZE);
//
//	cout << "Enter department's inventory max size: ";
//	cin >> inventoryMaxSize;
//
//	Department newDepartment(departmentName, inventoryMaxSize);
//
//	if (selectedBranch->addDepartment(newDepartment))
//	{
//		cout << "Department added successfully.\n";
//	}
//	else {
//		cout << "Failed to add department. The branch may be full.\n";
//	}
//	return;
//}
//
//void addEmployeeToBranch(ChainStore*& store)
//{
//	RegularBranch* selectedBranch = dynamic_cast<RegularBranch*>(getBranchFromStore(store));
//	if (!selectedBranch)
//	{
//		cout << "Cannot add employees to Online Branch!\n";
//		return;
//	}
//
//	if (selectedBranch->isEmployeeArrFull())
//	{
//		cout << "Employees array is full - cannot hire more employees\n";
//		return;
//	}
//
//	cout << "\n--------- Add new employee ---------" << endl;
//	int employeeType;
//	do
//	{
//		cout << "Enter the type of employee to add (1: Employee, 2: Manager): ";
//		if (!(cin >> employeeType) || employeeType < 1 || employeeType > 2)
//		{
//			cout << "Invalid employee type. Please enter 1 or 2.\n";
//		}
//	} while (employeeType < 1 || employeeType > 3);
//
//	char employeeName[SIZE];
//	char position[SIZE];
//	char manageDepartment[SIZE];
//	int age;
//
//	if (employeeType == 1 || employeeType == 2)
//	{
//		cout << "Enter employee name: ";
//		cleanBuffer();
//		cin.getline(employeeName, SIZE);
//
//		cout << "Enter employee's age: ";
//		cin >> age;
//
//		cout << "Enter employee position: ";
//		cleanBuffer();
//		cin.getline(position, SIZE);
//	}
//
//	if (employeeType == 2)
//	{
//		cout << "Enter manager department name to manage: ";
//		cin.getline(manageDepartment, SIZE);
//	}
//
//	Employee* employee = nullptr;
//	switch (employeeType)
//	{
//	case 1:
//		employee = new Employee(employeeName, age, position);
//		break;
//	case 2:
//		employee = new Manager(employeeName, age, position, manageDepartment);
//		break;
//	}
//
//	if (employee != nullptr)
//	{
//		if (selectedBranch->addEmployee(*employee))
//			cout << "Employee added successfully\n";
//		else
//		{
//			cout << "Employee was not added\n";
//		}
//	}
//	return;
//}
//
//void addItemToInventory(ChainStore*& store)
//{
//	Branch* selectedBranch = getBranchFromStore(store);
//	if (!selectedBranch)
//		return;
//
//	Department* selectedDepartment = getDepartmentFromBranch(selectedBranch);
//	if (!selectedDepartment)
//		return;
//
//	if (selectedDepartment->isInventoryFull())
//	{
//		cout << "The inventory is full - cannot add more items\n";
//		return;
//	}
//
//	cout << "\n--------- Add new item ---------" << endl;
//	char itemName[SIZE];
//	double price;
//
//	cout << "Enter item's name: ";
//	cleanBuffer();
//	cin.getline(itemName, SIZE);
//
//	cout << "Enter item's price: ";
//	cin >> price;
//	Item newItem(itemName, price);
//
//	if (selectedDepartment->addItem(newItem))
//		cout << "Item added successfully!\n";
//	else
//		cout << "Item was not added\n";
//	return;
//}
//
//void removeItemFromInventory(ChainStore*& store)
//{
//	Branch* selectedBranch = getBranchFromStore(store);
//	if (!selectedBranch)
//		return;
//
//	Department* selectedDepartment = getDepartmentFromBranch(selectedBranch);
//	if (!selectedDepartment)
//		return;
//
//	if (selectedDepartment->getNumItems() == 0)
//	{
//		cout << "The inventory is empty - cannot remove items\n";
//		return;
//	}
//
//	//cout << "Select an item to remove:\n";
//	selectedDepartment->showInventory();
//	cout << "\n--------- Select item number to remove: ";
//
//	int itemIndex;
//	do
//	{
//		//cout << "Enter item number: ";
//		cin >> itemIndex;
//		if (itemIndex < 1 || itemIndex > selectedDepartment->getNumItems())
//			cout << "Invalid item selection. Please enter a valid item index\n";
//	} while (itemIndex < 1 || itemIndex > selectedDepartment->getNumItems());
//
//	Item* item = (*selectedDepartment)[itemIndex - 1];
//
//	if (!selectedDepartment->removeItem(*item))
//	{
//		cout << "Cannot remove item\n";
//		return;
//	}
//	cout << "Item removed successfully!\n";
//	return;
//}
//
//void displayBranchDetails(ChainStore*& store)
//{
//	Branch* selectedBranch = getBranchFromStore(store);
//	if (!selectedBranch)
//		return;
//	cout << *selectedBranch;
//}
//
//void displayInventoryDetails(ChainStore*& store)
//{
//	Branch* selectedBranch = getBranchFromStore(store);
//	if (!selectedBranch)
//		return;
//
//	Department* selectedDepartment = getDepartmentFromBranch(selectedBranch);
//	if (!selectedDepartment)
//		return;
//
//	selectedDepartment->showInventory();
//}
//
//Branch* getBranchFromStore(ChainStore*& store)
//{
//	bool validIndex = false;
//
//	while (!validIndex)
//	{
//		cout << "\n--------- Select a branch ---------" << endl;
//		if (store->getNumBranches() == 0)
//		{
//			cout << "No branches in the store.\n";
//			return nullptr;
//		}
//		store->showBranchesArray();
//		int branchIndex;
//		cout << "Enter branch number: ";
//		cin >> branchIndex;
//
//		try
//		{
//			Branch* selectedBranch = (*store)[branchIndex - 1];
//			validIndex = true;
//			return selectedBranch;
//		}
//		catch (BranchIndexOutOfRangeException& e)
//		{
//			cout << e.what() << endl;
//			cout << "Please enter a valid branch index\n";
//		}
//		catch (...)
//		{
//			cout << "Unknown error acuured";
//		}
//
//	}
//	//do
//	//{
//	//	
//	//	if (branchIndex < 1 || branchIndex > store->getNumBranches())
//	//		cout << "Invalid branch selection. Please enter a valid branch index\n";
//	//} while (branchIndex < 1 || branchIndex > store->getNumBranches());
//
//	//
//
//	//return selectedBranch;
//}
//
//
//Department* getDepartmentFromBranch(Branch*& branch)
//{
//	Department* selectedDepartment = nullptr;
//	bool isValid = false;
//	int departmentIndex;
//
//	if (branch->getNumDepartments() == 0)
//	{
//		cout << "No departments available in the branch.\n";
//		return nullptr;
//	}
//
//	cout << "\n--------- Select a department ---------" << endl;
//	branch->showDepArray();
//
//	while (!isValid)
//	{
//		cout << "Enter department number: ";
//		cin >> departmentIndex;
//		try
//		{
//			Department* selectedDepartment = (*branch)[departmentIndex - 1];
//			isValid = true;
//		}
//		catch (const BranchIndexOutOfRangeException& e)
//		{
//			cout << e.what();
//			cout << "Please enter valid department index";
//		}
//		catch (...)
//		{
//			cout << "Unknown error occurred";
//		}
//	}
//	return selectedDepartment;
//}