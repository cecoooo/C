#include <iostream>
#include <memory>
using namespace std;

void print(void * data, char type) 
{
	switch (type)
	{
	case 'i': cout << *((int*)data) << endl; break;
	case 'c': cout << *((char*)data) << endl; break;
	case 'f': cout << *((float*)data) << endl; break;
	case 'd': cout << *((double*)data) << endl; break;
	case 'b': cout << *((bool*)data) << endl; break;
	default:
		cout << "Unrecognised type.";
		exit(1);
		break;
	}
}

void setValueOfThreeVariables(int* a, int * b, int *c) 
{
	cin >> *a >> *b >> *c;
}

class MyClass {
public:
	MyClass() {
		cout << "Obj created." << endl;
	}
	~MyClass() {
		cout << "Obj destructed" << endl;
	}
};

int main()
{
	/*int *a;
	int b = 7;
	a = &b;
	print(&b, 'i');

	int c = 0;
	cout << c;*/

	/*int a, b, c;

	setValueOfThreeVariables(&a, &b, &c);
	cout << a << ' ' << b << ' ' << c;*/

	/*int len;
	cout << "Length: ";
	cin >> len;
	int* arr = new int[len];*/

	/*for (size_t i = 0; i < len; i++)
	{
		cout << "Array[" << i << "]: ";
		cin >> arr[i];
	}
	cout << endl;
	for (size_t i = 0; i < len; i++)
	{
		cout << "Array[" << i << "]: " << arr[i] << endl;
	}
	delete[] arr;
	arr = NULL;*/

	/*int** matrix = new int*[5];

	for (size_t i = 0; i < 5; i++)
	{
		matrix[i] = new int[4];
		for (size_t j = 0; j < 4; j++)
		{
			matrix[i][j] = j + i;
		}
	}

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	for (size_t i = 0; i < 5; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = NULL;*/


	/*unique_ptr<int> uPtr = make_unique<int>(25);
	shared_ptr<int> sPtr1 = make_unique<int>(30);
	cout << *uPtr << endl;
	shared_ptr<int> sPtr = sPtr1;
	MyClass myClass;
	weak_ptr<MyClass> wPtr = make_shared<MyClass>(myClass);
	cout << *sPtr << endl;*/
}