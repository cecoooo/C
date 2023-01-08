#include <iostream>
using namespace std;

int main()
{
    int* arr, n, num;
    cin >> n;
    arr = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[i] = num;
    }
    int sum = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] + arr[j] < 120) {
                sum *= arr[i];
                break;
            }
        }
    }
    cout << sum;
    free(arr);
}