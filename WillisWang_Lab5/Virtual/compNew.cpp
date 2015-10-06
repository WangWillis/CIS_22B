#include <iostream>
#include <iomanip>
#include "WangCoNew.h"

using namespace std;

comp::comp()
{
	head = NULL;
	tail = NULL;
}

comp::~comp()
{
	while(head)
	{
		emp *temp = head;
		head = head->next;
		delete temp;
	}
}

void comp::newEmp()
{
	do 
	{
		cout << "What Type is this Employee?" << endl;
		cout << "01. Commissioned" << endl;
		cout << "02. Hourly" << endl;
		cout << "03. Salaried" << endl;
		cin >> empChoice;
		if(empChoice == 1)
		{
			cin.ignore();
			com *temp = new com();
			if(head == NULL)
			{
				head = temp;
				tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = tail->next;
			}
		}
		else if(empChoice == 2)
		{
			cin.ignore();
			hour *temp = new hour();
			if(head == NULL)
			{
				head = temp;
				tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = tail->next;
			}
		}
		else if(empChoice == 3)
		{
			cin.ignore();
			sal *temp = new sal();
			if(head == NULL)
			{
				head = temp;
				tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = tail->next;
			}
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid Choice" << endl;
		}
	}while(empChoice != 1 && empChoice != 2 && empChoice != 3);
}

void comp::display()
{
	if(head == NULL)
	{
		cout << "No Entries D:<!!" << endl;
	}
	else
	{
		cout << "Name\tStatus\t\tHours\tSales\tWages\tPay" << endl << endl;
		emp *temp = head;
		while(temp)
		{
			temp->display();
			temp = temp->next;
		}
		cout << "* 10% Bonus" << endl << endl;
	}
}