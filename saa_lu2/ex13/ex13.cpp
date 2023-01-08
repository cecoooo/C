#include <iostream>
using namespace std;

int main()
{
    int* arr, n, num;
    cin >> n;
    arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[i] = num;
    }
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] == arr[i+1]) {
            count++;
        }
    }
    cout << count;
}