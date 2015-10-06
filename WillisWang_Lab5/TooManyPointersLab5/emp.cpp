#include <iostream>
#include <cmath>
#include "wangCo.h"

using namespace std;

sal::sal()
{
	next = NULL;
	cout << "What is the employee's name?" << endl;
	getline(cin, name);
		cout << "What is their Weekly Salary?" << endl;
		while(!(cin >> pay))
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please re-enter" << endl;
		}
	cin.ignore();
	do
	{
		cout << "Does this employee get a bonus?(Y/N)" << endl;
		getline(cin, choice);
		if(choice == "y" || choice == "Y")
		{
			bonus = true;
		}
		else if(choice == "N" || choice == "n")
		{
			bonus = false;
		}
		else
		{
			choice.clear();
			cout << "Invalid Input please try again" << endl;
		}
	}while(choice != "y" && choice != "Y" && choice != "N" && choice != "n");
}

double sal::totPaySal()
{
	if(bonus)
	{
		return pay*(1.1);
	}
	else
	{
		return pay;
	}
}

void sal::salDisplay()
{
	cout << name << "\tSalaried\t-\t-\t$" << floor((pay/40)*100)/100 << "\t$" << floor(totPaySal()*100)/100;
	if(bonus)
	{
		cout << '*' << endl;
	}
	else
	{
		cout << endl;
	}
}

hour::hour()
{
	next = NULL;
	cout << "What is the employee's name?" << endl;
	getline(cin, name);
	cout << "What is their hourly pay?" << endl;
	while(!(cin >> pay))
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please re-enter" << endl;
		}
	cout << "How many hours do they work per week?" << endl;
	while(!(cin >> hours))
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please re-enter" << endl;
		}
	cin.ignore();
}

double hour::totPayHour()
{
	if(hours > 40)
	{
		return 2*pay*(hours - 20);
	}
	else
	{
		return pay*hours;
	}
}

void hour::hourDisplay()
{
	cout << name << "\tHourly\t\t" << hours << "\t-\t$" << floor(pay*100)/100 << "\t$" << floor(totPayHour()*100)/100 << endl;		
}

com::com()
{
	next = NULL;
	cout << "What is the employee's name?" << endl;
	getline(cin, name);
	cout << "What is their pay?" << endl;
	while(!(cin >> pay))
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please re-enter" << endl;
		}
	cout << "What is the value of their sales this week?" << endl;
	while(!(cin >> sales))
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please re-enter" << endl;
		}
	cin.ignore();
}

double com::totPayCom()
{
	return pay + (sales*0.1);
}

void com::comDisplay()
{
	cout << name << "\tCommissioned\t-" << "\t$" << floor(sales*100)/100 << "\t$" << floor(pay*100)/100 << "\t$" << floor(totPayCom()*100)/100 << endl;
}