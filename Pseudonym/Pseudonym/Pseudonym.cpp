#include <iostream>
#include <memory>
#include <vector>
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

bool compareAcs(int a, int b) 
{
	return a > b;
}

bool compareDesc(int a, int b) 
{
	return a < b;
}

void swap(int* a, int* b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void OrderCollection(vector<int>* collection, bool(*sortingFunc)(int, int))
{
	for (size_t i = 0; i < collection->size(); i++)
	{
		bool isAlredySorted = true;
		for (size_t j = 0; j < collection->size()-i-1; j++)
		{
			if (sortingFunc(collection->at(j), collection->at(j+1)))
			{
				swap(&collection->at(j), &collection->at(j + 1));
				isAlredySorted = false;
			}
		}
		if (isAlredySorted)
			break;
	}
}

void printVector(vector<int> collection) 
{
	for (size_t i = 0; i < collection.size(); i++)
	{
		cout << collection[i] << " ";
	}
}



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

	vector<int> arr = { 6,3,7,5,1,9,0,6,-1,3,-8 };
	bool(*sortFunc)(int, int) = compareAcs;
	OrderCollection(&arr, sortFunc);
	printVector(arr);


}