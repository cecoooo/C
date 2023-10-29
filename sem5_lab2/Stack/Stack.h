#pragma once
class Stack
{
	char* stack;
	int count;
	int len;
public:
	Stack() 
	{
		this->len = 2;
		this->stack = (char*)malloc(len * sizeof(char));
		this->count = 0;
	}
	~Stack() 
	{

	}
	int Count();
	void push(char);
	char peek();
	void pop();
	Stack loadstack(int);
};

int Stack::Count() {
	return count;
}

void Stack::push(char el) 
{
	if (len == count) 
	{
		char* new_data = (char*)realloc(stack, len * 2 * sizeof(char));
		stack = (char*)realloc(new_data, len * 2 * sizeof(char));
		len *= 2;
	}
	stack[count] = el;
	count++;
}

char Stack::peek() 
{
	return stack[count - 1];
}

void Stack::pop() 
{
	stack[count - 1] = NULL;
	count--;
}

Stack Stack::loadstack(int param) 
{
	char el;
	Stack res;
	if (param != 1) {
		for (int i = 97; i <= 122; i++)
		{
			el = i;
			res.push(el);
		}
	}
	else {
		for (int i = 65; i <= 90; i++)
		{
			el = i;
			res.push(el);
		}
	}
	return res;
}