#include <iostream>
using namespace std;

int SumOfElements(int arr[], int i) {
    if (i <= 0)
        return 0;
    return SumOfElements(arr, i-1) + arr[i - 1];
}

int main()
{
    int *arr, num, len=0;
    cin >> len;
    arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        cin >> num;
        arr[i] = num;
    }
    cout << SumOfElements(arr, len);
    free(arr);
}