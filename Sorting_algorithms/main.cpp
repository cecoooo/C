#include <iostream>
using namespace std;

int* input_arr(){
    int num, n, *arr;
    cout << "Enter Array Length:";
    cin >> n;
    arr = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter element:";
        cin >> num;
        arr[i] = num;
    }
    return arr;
}

int len(int *arr){
    int i = 0;
    while (arr[i] > -10000 && arr[i] < 10000)
        i++;
    return i;
}

void print_arr(int *arr){
    int length = len(arr);
    cout << "output: ";
    for (int i = 0; i < length; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void selection_sort(int *arr);
void selection_sort_stable(int *arr);

int main() {
    int *arr = input_arr();
    print_arr(arr);
    selection_sort(arr);
    print_arr(arr);
    selection_sort_stable(arr);
    print_arr(arr);
    free(arr);
}


/*
 * Steps for Selection Sort:
 *
 * (you need 2 for loops (indexes i & j))
 * 1. create a variable named 'min_index' which starting value will be i
 * 2. in the inner loops go through the array and find the index of the smallest value, then set it to 'min_index'
 * 3. all you have to do after that is to swap the lowest value element and that one on position i
 * 4. repeat it as many times as needed (one less time than the length of the array)
 *
 *
 * Complexity analysis of Selection Sort:
 *
 * Time complexity: O(N^2), because there are two nested loops (each of them with complexity O(N))
 * Auxiliary Space: O(1), because there is just one (temp) extra variable to swap the elements
 * */
void selection_sort(int *arr){
    int length = len(arr);
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

void selection_sort_stable(int *arr){
    int length = len(arr);
    for (int i = 0; i < length-1; ++i) {
        int min_index = i;
        for (int j = i+1; j < length; ++j) {
            if(arr[j] < arr[min_index])
                min_index = j;
        }

        int min = arr[min_index];
        while(i < min_index){
            arr[min_index] = arr[min_index-1];
            min_index--;
        }
        arr[i] = min;
    }
}