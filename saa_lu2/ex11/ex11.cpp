// ex11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void fillArray(int* arr, int n) {
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[i] = num;
    }
}


int main()
{
    int *arr, n;
    cin >> n;
    arr = (int*)malloc(sizeof(int) * n);
    fillArray(arr, n);
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        if ((arr[i] < 0 && arr[i+1] > 0) || (arr[i] > 0 && arr[i+1] < 0)) {
            count++;
        }
    }
    free(arr);
    cout << count;
}

