#include <iostream>
#include <iomanip>
#include "wangCo.h"

using namespace std;

comp::comp()
{
	salHead = NULL;
	hourHead = NULL;
	comHead = NULL;
	salTail = NULL;
	hourTail = NULL;
	comTail = NULL;
}

comp::~comp()
{
	while(salHead)
	{
		sal *temp = salHead;
		salHead = salHead->next;
		delete temp;
	}
	while(hourHead)
	{
		hour *temp = hourHead;
		hourHead = hourHead->next;
		delete temp;
	}
	while(comHead)
	{
		com *temp = comHead;
		comHead = comHead->next;
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
			if(comHead == NULL)
			{
				comHead = temp;
				comTail = temp;
			}
			else
			{
				comTail->next = temp;
				comTail = comTail->next;
			}
		}
		else if(empChoice == 2)
		{
			cin.ignore();
			hour *temp = new hour();
			if(hourHead == NULL)
			{
				hourHead = temp;
				hourTail = temp;
			}
			else
			{
				hourTail->next = temp;
				hourTail = hourTail->next;
			}
		}
		else if(empChoice == 3)
		{
			cin.ignore();
			sal *temp = new sal();
			if(salHead == NULL)
			{
				salHead = temp;
				salTail = temp;
			}
			else
			{
				salTail->next = temp;
				salTail = salTail->next;
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
	if(comHead == NULL && hourHead == NULL && salHead == NULL)
	{
		cout << "No Entries!!! D:<" << endl;
	}
	else
	{
		com *comTemp = comHead;
		hour *hourTemp = hourHead;
		sal *salTemp = salHead;
		cout << "Name\tStatus\t        Hours \tSales\tWages\tPay" << endl;
		while(comTemp)
		{
			comTemp->comDisplay();
			comTemp = comTemp->next;
		}
		while(hourTemp)
		{
			hourTemp->hourDisplay();
			hourTemp = hourTemp->next;
		}
		while(salTemp)
		{
			salTemp->salDisplay();
			salTemp = salTemp->next;
		}
		cout << "*A 10% bonus is awarded" << endl << endl;
	}
}