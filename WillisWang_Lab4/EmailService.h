#ifndef EMAILSERVICE_H
#define EMAILSERVICE_H

class Email;
class mailBox;

#include <string>

class Email
{
	private:
		std::string from, to, subject, body, fullMessage;
		std::string toString(std::string, std::string, std::string, std::string);
	public:
		Email *next;
		Email();
		std::string getSubject();
		void display();
		void append();
};

class mailBox
{
	private:
		void displaySub(Email*);
		int size;
		Email *head, *tail, *letter;
	public:
		mailBox();
		~mailBox();
		void addMessage();
		Email *getMessage();
		void removeEmail();
};
#endif