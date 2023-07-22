#include <iostream>

using namespace std;

void sort(int *arr, int length){
    for (int i = 0; i < length-1; ++i) {
        int min_index = i;
        for (int j = i+1; j < length; ++j) {
            if(arr[j] < arr[min_index])
                min_index = j;
        }

        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void aggregate(int *arr, int len){
    sort(arr, len);
    int mul = 1;
    int sumSquare = 0;
    for(int i = 0; i < len; i++){
        mul*=arr[i];
    }
    for(int i = 0; i < len; i++){
        sumSquare += arr[i]*arr[i];
    }
    cout << "min element: " << arr[0] << "\n";
    cout << "element multiplication: " << mul << "\n";
    cout << "Sum of elements' squares: " << sumSquare;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    aggregate(arr, n);
    cout << arr[n-2];
}
