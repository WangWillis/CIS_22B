#include "EmailService.h"
#include <iostream>

using namespace std;

mailBox::mailBox()
{
	head = NULL;
	letter = NULL;
	tail = NULL;
	size = 0;
}

mailBox::~mailBox()
{
	while(head)
	{
		Email *temp = head;
		head = head->next;
		delete temp;
	}
}

void mailBox::addMessage()
{
	Email *temp;
	temp = new Email();
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	size++;
}

void mailBox::removeEmail()
{
	if(size == 0)
	{
		cout << "NO ENTRIES!!!!" << endl;
	}
	else
	{
		int choice;
		Email *before;
		letter = head;
		do
		{
			displaySub(letter);
			cout << "Which entry would you like to remove?" << endl;
			cin >> choice;
			if(choice > size || choice <= 0 || cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid input please re-enter" << endl;
			}
		}while(choice > size || choice <= 0 || cin.fail());
		cin.ignore();
		for(int i = 1; i < choice; i++)
		{
			before = letter;
			letter = letter->next;
		}
		if(size == 1)
		{
			head = NULL;
			tail = head;
		}
		else if(choice == 1)
		{
			head = letter->next;
		}
		else if(choice == size)
		{
			before->next = NULL;
			tail = before;
		}
		else
		{
			before->next = letter->next;
		}
		delete letter;
		cout << "DELETED!!!" << endl;
		size--;
	}
}

void mailBox::displaySub(Email *letter)
{
	int i = 1;
	while(letter != NULL)
	{
		cout << i << ". Subject: " << letter->getSubject() << endl;
		letter = letter->next;
		i++;
	}
	letter = head;
}

Email *mailBox::getMessage()
{
	if(size == 0)
	{
		cout << "No Messages!" << endl;
		return NULL;
	}
	else
	{
		int choice;
		letter = head;
		do
		{
			displaySub(letter);
			cout << "Which entry would you like to select?" << endl;
			cin >> choice;
			if(choice > size || choice <= 0 || cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid input please re-enter" << endl;
			}
		}while(choice > size || choice <= 0 || cin.fail());
		cin.ignore();
		letter = head;
		for(int i = 1; i < choice; i++)
		{
			letter = letter->next;
		}
	}
	return letter;
}