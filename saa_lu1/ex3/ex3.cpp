#include <iostream>
using namespace std;

int main()
{
	int x = 2;
	do
	{
		x = x*2 + 10;
	} while (x < 100);
	cout << x;
}