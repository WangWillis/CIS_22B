#include "EmailService.h"
#include <iostream>
#include <string>

using namespace std;

Email::Email()
{
	next = NULL;
	cout << "What is your name?" << endl;
	getline(cin, from);
	cout << "Who do you want to send this message to?" << endl;
	getline(cin, to);
	cout << "What is the Subject of this message?" << endl;
	getline(cin, subject);
	cout << "Please write your message. (Press enter when done)" << endl;
	getline(cin, body);
	fullMessage = toString(from, to, subject, body);
}

string Email::toString(string from, string to, string subject, string body)
{
	string fullMessage;
	fullMessage.append("From: ");
	fullMessage.append(from);
	fullMessage.append("\nTo: ");
	fullMessage.append(to);
	fullMessage.append("\nSubject: ");
	fullMessage.append(subject);
	fullMessage.append("\nBody:\n\n");
	fullMessage.append(body);
	return fullMessage;
}

void Email::append()
{
	string add;
	cout << fullMessage << endl << endl;
	cout << "What do you want to add to the end of this message? (Press enter when done)" << endl;
	getline(cin, add);
	fullMessage.append(" ");
	fullMessage.append(add);
}

void Email::display()
{
	cout << fullMessage << endl;
}

string Email::getSubject()
{
	return subject;
}