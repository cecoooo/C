#include <iostream>
using namespace std;

class pr2;

class pr1
{
	int printing;
public:
	pr1()
	{
		printing = 0;
	}
	void set_print_status(int);
	friend bool inuse(pr1, pr2);
};

void pr1::set_print_status(int status)
{
	printing = status;
}

#pragma once
class pr2
{
	int printing;
public:
	pr2()
	{
		printing = 0;
	}
	void set_print_status(int);
	friend bool inuse(pr1, pr2);
};

void pr2::set_print_status(int status)
{
	printing = status;
}

bool inuse(pr1 p1, pr2 p2) 
{
	if (p1.printing == 0 && p2.printing == 0)
		return false;
	return true;
}

int main()
{
	pr1 p1;
	pr2 p2;

	p1.set_print_status(0);
	p2.set_print_status(0);
	cout << inuse(p1, p2) << '\n';
	p1.set_print_status(0);
	p2.set_print_status(1);
	cout << inuse(p1, p2) << '\n';
	p1.set_print_status(1);
	p2.set_print_status(0);
	cout << inuse(p1, p2) << '\n';
	p1.set_print_status(1);
	p2.set_print_status(1);
	cout << inuse(p1, p2) << '\n';
}