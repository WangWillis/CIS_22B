#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

enum isThere
{
	out, in
};

struct lib
{
	string name, title, isbn;
	isThere status;
	lib *next = NULL;
};

lib *fileInput(lib *list, int &size)
{
	fstream file;
	string strTemp;
	lib *temp = list;
	file.open("lib.dat", ios::in | ios::binary);
	getline(file, strTemp, '\n');
	size = atoi(strTemp.c_str());
	if(size != 0)
	{
		for(int i = 0; i < size; i++)
		{
			list = new lib();
			getline(file, list->title, '\t');
			getline(file, list->name, '\t');
			getline(file, list->isbn, '\t');
			getline(file, strTemp, '\n');
			if(atoi(strTemp.c_str()))
			{
				list->status = in;
			}
			else
			{
				list->status = out;
			}
			list = list->next;
		}
	}
	file.close();
	return temp;
}

void display(lib *list)
{
	cout << "Title: " << '\t' << list->title << endl;
	cout << "Author: " << '\t' << list->name << endl;
	cout << "ISBN: " << '\t' << list->isbn << endl;
	cout << "Status: " << '\t';
	if(list->status)
	{
		cout << "In" << endl;
	}
	else
	{
		cout << "Out" << endl;
	}
}


void displayList(lib *list)
{
	while(list)
	{
		display(list);
		list = list->next;
	}
}

bool isDup(lib *list, string isbn, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(isbn == list->isbn)
		{
			return true;
		}
		list = list->next;
	}
	return false;
}

void inputBook(lib *&list, lib *temp, int size)
{
	string choice, tempS;
	do
	{
		do
		{
			do
			{
				cout << "What is the title of your book?" << endl;
				getline(cin, list->title);
				if(list->title.length() > 50)
				{
					cout << "Please do not enter more than 50 Characters" << endl;
				}
			}while(list->title.length() > 50);
			do
			{
				cout << "What is the author's name?" << endl;
				getline(cin, list->name);
				if(list->name.length() > 25)
				{
					cout << "Please do not enter more than 25 Characters" << endl;
				}
			}while(list->name.length() > 25);
			do
			{
				cout << "What is the ISBN of this book?" << endl;
				getline(cin, list[size].isbn);
				if(list->isbn.length() > 13)
				{
					cout << "Please do not enter more than 13 Characters" << endl;
				}
			}while(list->isbn.length() > 13);
			if(isDup(temp, list->isbn, size))
			{
				cout << "Sorry that book has already been entered." << endl;
				cout << "Please re-enter." << endl;
			}
		}while(isDup(temp, list->isbn, size));
		do
		{
			cout << "What is the status of this book? (I/O)" << endl;
			getline(cin, tempS, '\n');
			if(tempS == "I" || tempS == "i")
			{
				list->status = in;
			}
			else if(tempS == "o" || tempS == "O")
			{
				list->status = out;
			}
			else
			{
				cout << "That is not a valid inupt. ";
			}
		}while(tempS != "I" && tempS != "i" && tempS != "o" && tempS != "O");
		do
		{
			cout << "Is this the correct information? (y/n)" << endl;
			cout << "Title: " << list[size].title << endl;
			cout << "Author: " << list[size].name << endl;
			cout << "ISBN: " << list[size].isbn << endl;
			cout << "Status: ";
			if(list->status)
			{
				cout << "In" << endl;
			}
			else
			{
				cout << "Out" << endl;
			}
			getline(cin, choice, '\n');
			if(choice != "y" && choice != "Y" && choice != "n" && choice != "Y")
			{
				cout << "Sorry invalid input. Please try again" << endl;
			}
		}while(choice != "y" && choice != "Y" && choice != "n" && choice != "Y");
	}while(choice != "y" && choice != "Y");
}

lib *newBook(lib *list, int &size)
{
	lib *temp = list;
	while(list)
	{
		list = list->next;
	}
	list = new lib();
	inputBook(list, temp, size);
	size++;
	return temp;
}

void search(lib *list, int size)
{
	string choice;
	if(size == 0)
	{
		cout << "NO ENTRIES D:<<<" << endl;
	}
	else
	{
		size = 0;
		cout << "What do you want to search for?" << endl;
		getline(cin, choice);
		while(list)
		{
			if(list->title == choice || list->name == choice || list->isbn == choice)
			{
				display(list);
				size++;
			}
			list = list->next;
		}
		cout << size << "Results found." << endl;
	}
}

lib *del(lib *list, int &size)
{
	lib *temp = list, *bef, *aft;
	int choice;
	cout << "Which entry would you like to delete?" << endl;
	for(int i = 0; i < size; i++)
	{
		cout << i << endl;
		display(list);
		list = list->next;
	}
	cin >> choice;
	cin.ignore();
	list = temp;
	for(int i = 0; i < choice; i++)
	{
		bef = list;
		list = list->next;
		aft = list->next;
	}
	delete list;
	bef->next = aft;
	size--;
	return temp;
}

int main()
{
	int size = 0;
	lib *list = NULL;
	while(list)
	{
		lib *temp = list;
		list = temp->next;
		delete temp;
	}
	return 0;
}