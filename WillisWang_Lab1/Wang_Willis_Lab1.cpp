#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const string dow[4] = {"Mon", "Tue", "Wed","Thu"}, t[4] = {"11-12", "12-1", "1-2", "2-3"};

void displayList(bool sch[][4])
{
	cout << endl;
	for(int i = 0; i < 4; i++)
	{
		cout << "\t" << dow[i] << "\t";
	}
	cout << endl;
	for(int j = 0; j < 4; j++)
	{
		cout << t[j] << "\t";
		for(int k = 0; k < 4; k++)
		{
			if(sch[k][j])
			{
				cout << setw(3) << "X" << "\t" << "\t";
			}
			else
			{
				cout << "\t" << "\t";
			}
		}
		cout << endl;
	}
}

void makeList(bool sch[][4])
{
	char correct;
	cout << "Please enter your schedule for the following days/times." << endl;
	cout << "(1 for busy 0 for Free)" << endl;
	for(int i = 0; i < 4; i++)
	{
		cout << dow[i] << endl;
		for(int j = 0; j < 4; j++)
		{
			do
			{
				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "\t" << "I do not understand your input." << endl;
					cout << "\t" << "Please re-enter for time. (1 for busy 0 for Free)" << endl << endl;
				}
				cout << "\t" << t[j] << ": ";
				cin >> sch[i][j];
				cout << endl;
			}while(cin.fail());
		}
	}
	cout << "Is this the correct Schedule? (Y/N)" << endl;
	displayList(sch);
	cin >> correct;
	while(correct != 'y' && correct != 'Y')
	{
		if(correct == 'n' || correct == 'N')
		{
			cout << "Restarting" << endl;
			return makeList(sch);
		}
		else
		{
			cout << "Sorry that is not a valid input." << endl;
			cout << "Is this the correct Schedule? (Y/N)" << endl;
			displayList(sch);
			cin >> correct;
		}	
	}
}

void indLessons(bool anna[][4], bool jeff[][4])
{
	cout << "Times at least one instructor is free: " << endl << endl;
	for(int i = 0; i < 4; i++)
	{
		cout << "\t" << dow[i] << "\t";
	}
	cout << endl;
	for(int j = 0; j < 4; j++)
	{
		cout << t[j] << "\t";
		for(int k = 0; k < 4; k++)
		{
			if(!anna[k][j] && !jeff[k][j])
			{
				cout << setw(4) << "Both" << "\t" << "\t";
			}
			else if(!anna[k][j])
			{
				cout << setw(4) << "Anna" << "\t" << "\t";
			}
			else if(!jeff[k][j])
			{
				cout << setw(4) << "Jeff" << "\t" << "\t";
			}
			else
			{
				cout << "\t" << "\t";
			}
		}
		cout << endl;
	}
}

void groLessons(bool anna[][4], bool jeff[][4])
{
	cout << "The times our instructors are free for group lessons: " << endl;
	for(int i = 0; i < 4; i++)
	{
		cout << "\t" << dow[i] << "\t";
	}
	cout << endl;
	for(int j = 0; j < 4; j++)
	{
		cout << t[j] << "\t";
		for(int k = 0; k < 4; k++)
		{
			if(!anna[k][j] && !jeff[k][j])
			{
				cout << setw(3) << "X" << "\t" << "\t";
			}
			else
			{
				cout << "\t" << "\t";
			}
		}
		cout << endl;
	}
}

void makeListFile(bool sch[][4])
{
	char correct;
	string filename;
	ifstream start;
	do
	{
		start.clear();
		cout << "Input a file name. (Put a .txt at the end)" << endl;
		cout << "use 1 for busy 0 for free." << endl;
		cin >> filename;
		start.open(filename.data());
		if(!start)
		{
			cout << "Sorry invalid file." << endl;
			cout << "Please re-enter" << endl;
		}
	}while(!start);

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			start >> sch[j][i];
		}
	}
	start.close();
	cout << "Is this the correct file? (Y/N)" << endl;
	displayList(sch);
	cin >> correct;
	while(correct != 'y' && correct != 'Y')
	{
		if(correct == 'n' || correct == 'N')
		{
			cout << "Restarting" << endl;
			return makeListFile(sch);
		}
		else
		{
			cout << "Sorry that is not a valid input." << endl;
			cout << "Is this the correct Schedule? (Y/N)" << endl;
			displayList(sch);
			cin >> correct;
		}	
	}
}

void displayListFile(bool sch[][4])
{
	ofstream write;
	string filename;
	cout << "What is the name of the file you want to write to? (Put a .txt at the end)" << endl;
	cin >> filename;
	write.open(filename.data());
	for(int j = 0; j < 4; j++)
	{
		for(int k = 0; k < 4; k++)
		{
			write << sch[k][j] << " ";
		}
		write << endl;
	}
	write.close();
	cout << "Write complete." << endl;
	cout << "File is in your directory." << endl;
}

int main()
{
	bool Anna[4][4] = {0}, Jeff[4][4] = {0};
	int choice;
	do
	{
		cout << endl;
		cout << "01. Edit Schedules" << endl;
		cout << "02. Display Schedules" << endl;
		cout << "03. Display times for Individual lessons" << endl;
		cout << "04. Display times for group lessons" << endl;
		cout << "05. Input schedules from a file" << endl;
		cout << "06. Save schedules to a file" << endl;
		cout << "07. Quit" << endl;
		cin >> choice;
		if(choice == 1)
		{
			do
			{
				cout << endl << "01. Jeff?" << endl << "02. Anna?" << endl;
				cin >> choice;
				if(choice == 1)
					makeList(Jeff);
				else if(choice == 2)
					makeList(Anna);
				else
				{
					cin.clear();
					cin.ignore();
					cout << "I do not recognize that input. Please try again." << endl;
				}
			}while(choice != 1 && choice != 2);
		}
		else if(choice == 2)
		{
			do
			{
				cout << endl << "01. Jeff?" << endl << "02. Anna?" << endl;
				cin >> choice;
				if(choice == 1)
					displayList(Jeff);
				else if(choice == 2)
					displayList(Anna);
				else
				{
					cin.clear();
					cin.ignore();
					cout << "I do not recognize that input. Please try again." << endl;
				}
			}while(choice != 1 && choice != 2);
		}
		else if(choice == 3)
		{
			indLessons(Anna, Jeff);
		}
		else if(choice == 4)
		{
			groLessons(Anna, Jeff);
		}
		else if(choice == 5)
		{
			do
			{
				cout << endl << "01. Jeff?" << endl << "02. Anna?" << endl;
				cin >> choice;
				if(choice == 1)
					makeListFile(Jeff);
				else if(choice == 2)
					makeListFile(Anna);
				else
				{
					cin.clear();
					cin.ignore();
					cout << "I do not recognize that input. Please try again." << endl;
				}
			}while(choice != 1 && choice != 2);
		}
		else if(choice == 6)
		{
			do
			{
				cout << endl << "01. Jeff?" << endl << "02. Anna?" << endl;
				cin >> choice;
				if(choice == 1)
					displayListFile(Jeff);
				else if(choice == 2)
					displayListFile(Anna);
				else
				{
					cin.clear();
					cin.ignore();
					cout << "I do not recognize that input. Please try again." << endl;
				}
			}while(choice != 1 && choice != 2);
		}
		else if(choice != 7)
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please re-enter" << endl;
		}
	}while(choice != 7);
	return 0;
}