#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct lists
{
	char *list;
	int frq;
};

int counter()
{
	int counter = 0;
	char *temp = new char [70];
	ifstream file;
	file.open("hi.txt");
	while(file >> temp)
	{
		counter++;
	}
	file.close();
	delete [] temp;
	return counter;
}

int counter2(char **list, int size)
{
	int count = 0;
	for(int i = 0; i < size; i++)
	{
		if(list[i] != NULL)
		{
			count++;
		}
	}
	return count;
}

void editList(lists *&editIt, char** tempList, int &size)
{
	int *tempFrq = new int [2000] ();
	for(int i = 0; i < size; i++)
	{
		if(tempList[i] != NULL)
		{
			tempFrq[i]++;
			for(int j = i + 1; j < size; j++)
			{
				if(tempList[j] != NULL && !strcmp(tempList[i], tempList[j]))
				{
					tempList[j] = NULL;
					tempFrq[i]++;
				}
			}
		}
	}
	editIt = new lists [counter2(tempList, size)];
	for(int i = 0, j = 0; i < size; i++)
	{
		if(tempList[i] != NULL)
		{
			editIt[j].list = tempList[i];
			editIt[j].frq = tempFrq[i];
			j++;
		}
	}
	size = counter2(tempList, size);
	delete [] tempList, tempFrq;
}

void display(lists* displayed, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << displayed[i].list << " " << displayed[i].frq << endl;
	}
}

int main()
{
	lists *firstText;
	char *word, *wordTemp, **tempList;
	int size = counter();
	ifstream file;
	file.open("hi.txt");
	tempList = new char* [size];
	for(int i = 0;i < size; i++)
	{
		wordTemp = new char [70];
		file >> wordTemp;
		if(!isalnum(wordTemp[strlen(wordTemp) - 1]))
		{
			wordTemp[strlen(wordTemp) - 1] = '\0';
		}
		word = new char [strlen(wordTemp) + 1];
		strcpy(word, wordTemp);
		tempList[i] = word;
		delete [] wordTemp;
	}
	file.close();
	editList(firstText, tempList, size);
	display(firstText, size);
	for(int i = 0; i < size; i++)
	{
		delete [] firstText[i].list;
	}
	delete [] firstText;
	return 0;
}