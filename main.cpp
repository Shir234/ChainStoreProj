#include <iostream>
using namespace std;

//ALL FUNCTIONS TO RUN THE MAIN 
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
