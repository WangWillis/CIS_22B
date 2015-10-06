#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <cstring>

using namespace std;

enum isThere
{
	out, in
};

struct lib
{
	string title, name, isbn;
	isThere status;
};

void fileInput(lib *&list, int &size)
{
	fstream file;
	file.open("lib.dat", ios::in | ios::binary);
	if(!file)
	{
		cout << "File not found." << endl;
		cout << "Starting new Library." << endl;
	}
	else
	{
		string temp;
		getline(file, temp, '\n');
		size = atoi(temp.c_str());
		list = new lib [size];
		for(int i = 0; i < size; i++)
		{
			getline(file, list[i].title, '\t');
			getline(file, list[i].name, '\t');
			getline(file, list[i].isbn, '\t');
			getline(file, temp, '\n');
			if(atoi(temp.c_str()))
			{
				list[i].status = in;
			}
			else
			{
				list[i].status = out;
			}
		}
	}
	file.close();
}

void display(lib list)
{
	cout << '\t' << "Title: " << list.title << endl;
	cout << '\t' << "Author: " << list.name << endl;
	cout << '\t' << "ISBN: " << list.isbn << endl;
	cout << '\t' << "Status: ";				
	if(list.status)
	{
		cout << "In" << endl << endl;	
	}
	else
	{
		cout << "Out" << endl << endl;
	}
}

void displaylist(lib *list, int size)
{
	if(size == 0)
	{
		cout << "NO ENTRIES D:<!!!!!!!!!!" << endl;
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			display(list[i]);
		}
	}
}

bool isDup(lib* list, string isbn, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(isbn == list[i].isbn)
		{
			return true;
		}
	}
	return false;
}

void inputBook(lib *&list, int size)
{
	string choice, tempS;
	do
	{
		do
		{
			do
			{
				cout << "What is the title of your book?" << endl;
				getline(cin, list[size].title);
				if(list[size].title.length() > 50)
				{
					cout << "Please do not enter more than 50 Characters" << endl;
				}
			}while(list[size].title.length() > 50);
			do
			{
				cout << "What is the author's name?" << endl;
				getline(cin, list[size].name);
				if(list[size].name.length() > 25)
				{
					cout << "Please do not enter more than 25 Characters" << endl;
				}
			}while(list[size].name.length() > 25);
			do
			{
				cout << "What is the ISBN of this book?" << endl;
				getline(cin, list[size].isbn);
				if(list[size].isbn.length() > 13)
				{
					cout << "Please do not enter more than 13 Characters" << endl;
				}
			}while(list[size].isbn.length() > 13);
			if(isDup(list, list[size].isbn, size))
			{
				cout << "Sorry that book has already been entered." << endl;
				cout << "Please re-enter." << endl;
			}
		}while(isDup(list, list[size].isbn, size));
		do
		{
			cout << "What is the status of this book? (I/O)" << endl;
			getline(cin, tempS, '\n');
			if(tempS == "I" || tempS == "i")
			{
				list[size].status = in;
			}
			else if(tempS == "o" || tempS == "O")
			{
				list[size].status = out;
			}
			else
			{
				cout << "That is not a valid inupt. ";
			}
		}while(tempS != "I" && tempS != "i" && tempS != "o" && tempS != "O");
		do
		{
			display(list[size]);
			cout << "Is this the correct input?(Y/N)" << endl;
			getline(cin, choice, '\n');
			if(choice != "y" && choice != "Y" && choice != "n" && choice != "Y")
			{
				cout << "Sorry invalid input. Please try again" << endl;
			}
		}while(choice != "y" && choice != "Y" && choice != "n" && choice != "Y");
	}while(choice != "y" && choice != "Y");
}

lib *newBook(lib *temp, int &size)
{
	lib *list = new lib [size + 1];
	if(size > 0)
	{
		for(int i = 0; i < size; i++)
		{
			list[i].title = temp[i].title;
			list[i].name = temp[i].name;
			list[i].isbn = temp[i].isbn;
			if(temp[i].status)
			{
				list[i].status = in;
			}
			else
			{
				list[i].status = out;
			}
		}
		delete [] temp;
	}
	inputBook(list, size);
	size++;
	return list;
}

void search(lib *list, int size)
{
	if(size == 0)
	{
		cout << "NO ENTRIES D:<<<<" << endl;
	}
	else
	{
		string search;
		lib *temp = new lib [size];
		unsigned int count = 0;
		cout << "Enter a title, author, or ISBN." << endl;
		getline(cin, search);
		for(int i = 0; i < size; i++)
		{
			if(list[i].title == search || list[i].name == search || list[i].isbn == search)
			{
				temp[count] = list[i];
				count++;
			}
		}
		if(count > 0)
		{
			cout << count << " results were found" << endl;
			displaylist(temp, count);
		}
		else
		{
			cout << "0 results were found :(" << endl;
		}
		delete [] temp;
	}
}
//add '\t' after each element but for the last one add '\n'
void quit(lib *list, int size)
{
	fstream file;
	stringstream out;
	string temp;
	file.open("lib.dat", ios::out | ios::binary);
	out << size;
	temp = out.str();
	file.write(temp.c_str(), temp.size());
	file.write("\n", sizeof(char));
	for(int i = 0; i < size; i++)
	{
		file.write(list[i].title.c_str(), list[i].title.size());
		file.write("\t", sizeof(char));
		file.write(list[i].name.c_str(), list[i].name.size());
		file.write("\t", sizeof(char));
		file.write(list[i].isbn.c_str(), list[i].isbn.size());
		file.write("\t", sizeof(char));
		if(list[i].status)
		{
			file.write("1", sizeof(char));
		}
		else
		{
			file.write("0", sizeof(char));
		}
		file.write("\n", sizeof(char));
	}
	file.close();
}

lib *del(lib *temp, int &size)
{
	int *places = new int [size], numChoice, count = 0;
	string choice;
	lib *list = new lib [size];
	if(size == 0)
	{
		cout << "NO ENTRIES D:<<<<" << endl;
		return temp;
	}
	else
	{
		cout << "What book would you like to delete?" << endl;
		getline(cin, choice);
		for(int i = 0; i < size; i++)
		{
			if(temp[i].title == choice || temp[i].name == choice || temp[i].isbn == choice)
			{
				list[count] = temp[i];
				places[count] = i;
				count++;
			}
		}
		if(count != 0)
		{
			do 
			{
				cout << count << " relevent results found." << endl;
				cout << "Which one would you like to delete" << endl;
				for(int i = 0; i < count; i++)
				{
					cout << i + 1 << ".";
					display(list[i]);
				}
				cout << count + 1 << ". Exit" << endl;
				cin >> numChoice;
				cin.ignore();
				if(numChoice > count + 1 || numChoice < 1 || cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "INVALID INPUT" << endl;
					cout << "Please retry" << endl;
				}	
			}while(numChoice > count + 1 || numChoice < 1 || cin.fail());
			delete [] list;
			if(numChoice != count + 1)
			{
				temp[places[numChoice - 1]].title = "\0";
				cout << "Deleted" << endl;
				list = new lib [size - 1];
				for(int i = 0, j = 0; i < size; i++)
				{
					if(temp[i].title != "\0")
					{
						list[j].title = temp[i].title;
						list[j].name = temp[i].name;
						list[j].isbn = temp[i].isbn;
						list[j].status = temp[i].status;
						j++;
					}
				}
			}
			else
			{
				cout << "Returning to menu" << endl;
				return temp;
			}
		}
		else
		{
			cout << "0 results found." << endl;
			cout << "Returning to menu." << endl;
			return temp;
		}
		delete [] temp;	
		delete [] places;
		if(numChoice != count + 1)
		{
			size--;
		}
		return list;
	}
}

lib *changeBook(lib *list, int size)
{
	if(size == 0)
	{
		cout << "NO ENTRIES D:<<<<" << endl;
		return list;
	}
	else
	{
		string choice;
		int *places = new int [size], count = 0, numChoice;
		lib *temp = new lib [size];
		cout << "What book would you like to change?" << endl;
		getline(cin, choice);
		for(int i = 0; i < size; i++)
		{
			if(list[i].title == choice || list[i].name == choice || list[i].isbn == choice)
			{
				temp[count] = list[i];
				places[count] = i;
				count++;
			}
		}
		if(count != 0)
		{
			do 
			{
				cout << count << " relevent results found." << endl;
				cout << "Which one would you like to change" << endl;
				for(int i = 0; i < count; i++)
				{
					cout << i + 1 << ".";
					display(list[i]);
				}
				cout << count + 1 << ". Exit" << endl;
				cin >> numChoice;
				if(numChoice > count + 1 || numChoice < 1 || cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "INVALID INPUT" << endl;
					cout << "Please retry" << endl;
				}
			}while(numChoice > count + 1 || numChoice < 1 || cin.fail());
			cin.ignore();
			if(numChoice == count + 1)
			{
				delete [] temp;
				delete [] places;
				return list;
			}
			inputBook(list, places[numChoice - 1]);
			cout << "Edit Complete." << endl;
		}
		else
		{
			cout << "0 results found." << endl;
			cout << "Returning to menu." << endl;
			return list;
		}
		delete [] temp;
		delete [] places;
		return list;
	}
}

void sort(lib *&list, int size)
{
	lib temp;
	string choice;
	if(size == 0)
	{
		cout << "NO ENTRIES D:<<<<<!!!!!!!" << endl;
	}
	else
	{
		do
		{
			cout << "Do you want to display the list sorted by Title or Author?(T/A)" << endl;
			getline(cin, choice);
			if(choice == "T" || choice == "t")
			{
				for(int i = 0; i < size; i++)
				{
					for(int j = i + 1; j < size; j++)
					{
						if(list[i].title.compare(list[j].title) >= 0)
						{
							temp = list[j];
							list[j] = list[i];
							list[i] = temp;
						}
					}
				}
			}
			else if(choice == "A" || choice == "a")
			{
				for(int i = 0; i < size; i++)
				{
					for(int j = i + 1; j < size; j++)
					{
						if(list[i].name.compare(list[j].name) >= 0)
						{	
							temp = list[j];
							list[j] = list[i];
							list[i] = temp;
						}
					}
				}
			}
			else
			{
				choice.clear();
				cout << "Invalid input." << endl;
				cout << "Please retry" << endl;
			}
		}while(choice != "A" && choice != "a" && choice != "T" && choice != "t");
		displaylist(list, size);
	}
}

int main()
{
	int size = 0, choice = 0;
	string newLib;
	lib *list;
	do
	{
		cout << "Do you want to create a new libary?(Y/N)" << endl;
		getline(cin, newLib);
		if(newLib == "n" || newLib == "N")
		{
			cout << "Loading libary." << endl;
			fileInput(list, size);
		}
		else if(newLib == "y" || newLib == "Y")
		{
			cout << "Starting new libary." << endl;
		}
		else
		{
			cout << "INVALID INPUT :'(. Please re-enter." << endl;
		}
	}while(newLib != "y" && newLib != "Y" && newLib != "n" && newLib != "N");

	do
	{
		cout << "1. New Book" << endl;
		cout << "2. Search For Book" << endl;
		cout << "3. Delete Book" << endl;
		cout << "4. Change Book" << endl;
		cout << "5. Sort and Display Libary" << endl;
		cout << "6. Exit" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				cin.ignore();
				list = newBook(list, size);
				break;
			case 2:
				cin.ignore();
				search(list, size);
				break;
			case 3:
				cin.ignore();
				list = del(list, size);
				break;
			case 4:
				cin.ignore();
				changeBook(list, size);
				break;
			case 5:
				cin.ignore();
				sort(list, size);
				break;
			case 6:
				quit(list, size);
				cout << "Exiting" << endl;
				break;
			default:
				cin.clear();
				cin.ignore();
				cout << "Invalid input. Please re-enter" << endl;
				break;
		}
	}while(choice != 6);
	if(newLib == "n" || newLib == "N" || size > 0)
	{
		delete [] list;
	}
	return 0;
}