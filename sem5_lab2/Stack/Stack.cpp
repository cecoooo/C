#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack s;
    s = s.loadstack(1);
	for (int i = 0; i < 26; i++)
	{
		cout << s.peek();
		s.pop();
	}
}