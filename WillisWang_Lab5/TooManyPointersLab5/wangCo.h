#ifndef WANGCO_H
#define WANGCO_h

class comp;
class emp;
class sal;
class hour;
class com;

#include <string>

class comp
{
	private:
		sal *salHead, *salTail;
		hour *hourHead, *hourTail;
		com *comHead, *comTail;
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
	public:
		std::string name;
};

class sal: private emp
{
	private:
		bool bonus;
		std::string choice;
		double totPaySal();
	public:
		sal();
		sal *next;
		void salDisplay();
};

class hour: private emp
{
	private:
		int hours;
		double totPayHour();
	public:
		hour();
		hour *next;
		void hourDisplay();
};

class com: private emp
{
	private:
		double sales;
		double totPayCom();
	public:
		com();
		com *next;
		void comDisplay();
};

#endif