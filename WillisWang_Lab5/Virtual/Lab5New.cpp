#include <iostream>
#include "WangCoNew.h"

using namespace std;

int main()
{
	int choice = 0;
	comp *startUp = new comp();
	do 
	{
		cout << "01. New Employee" << endl;
		cout << "02. Display Employees" << endl;
		cout << "03. Exit" << endl;
		cin >> choice;
		if(choice == 1)
		{
			cin.ignore();
			startUp->newEmp();
		}
		else if(choice == 2)
		{
			cin.ignore();
			startUp->display();
		}
		else if(choice == 3)
		{
			delete startUp;
			cout << "Bye!" << endl;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid Input" << endl;
		}
	}while(choice != 3);
	return 0;
}