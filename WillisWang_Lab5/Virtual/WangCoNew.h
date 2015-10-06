#ifndef WANGCONEW_H
#define WANGCONEW_H

class comp;
class emp;
class sal;
class hour;
class com;

#include <string>

class comp
{
	private:
		emp *head, *tail;
		int empChoice;
	public:
		comp();
		~comp();
		void newEmp();
		void display();
};

class emp
{
	protected:
		double pay;
		emp *next;
	public:
		std::string name;
		virtual double totPay() = 0;
		virtual void display() = 0;
		friend class comp;
};

class sal: public emp
{
	private:
		bool bonus;
		std::string choice;
		double totPay();
	public:
		sal();
		void display();
};

class hour: public emp
{
	private:
		int hours;
		double totPay();
	public:
		hour();
		void display();
};

class com: public emp
{
	private:
		double sales;
		double totPay();
	public:
		com();
		void display();
};

#endif