#include <iostream>
#include <string>
#include <stdlib.h>
#include "EmailService.h"

using namespace std;

int main()
{
	int choice = 0;
	mailBox *myBox = new mailBox();
	Email *entry = NULL;
	do
	{
		cout << endl;
		cout << "01. New Email" << endl;
		cout << "02. Select an Entry" << endl;
		cout << "03. Delete an Entry" << endl;
		cout << "04. Append Current Entry" << endl;
		cout << "05. Display Current Entry" << endl;
		cout << "06. Exit" << endl;
		cin >> choice;
		if(choice == 1)
		{
			cin.ignore();
			myBox->addMessage();
		}
		else if(choice == 2)
		{
			cin.ignore();
			entry = myBox->getMessage();
		}
		else if(choice == 3)
		{
			cin.ignore();
			myBox->removeEmail();
			entry = NULL;
			cout << "Entry choice has also been reset." << endl;
		}
		else if(choice == 4)
		{
			cin.ignore();
			if(entry == NULL)
			{
				cout << "Entry has not been selected." << endl;
				cout << "Please select an entry using option 2." << endl;
			}
			else
			{
				entry->append();
			}
		}
		else if(choice == 5)
		{
			cin.ignore();
			if(entry == NULL)
			{
				cout << "Entry has not been selected." << endl;
				cout << "Please select an entry using option 2" << endl;
			}
			else
			{
				entry->display();
			}
		}
		else if(choice == 6)
		{
			delete myBox;
			cout << "Exiting" << endl;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input please re-enter" << endl;
		}
	}while(choice != 6);
	return 0;
}