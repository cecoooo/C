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
void bubble_sort(int *arr);

int main() {
    int *arr = input_arr();
    print_arr(arr);

//    // Selection Sort
//    selection_sort(arr);
//    print_arr(arr);
//    selection_sort_stable(arr);
//    print_arr(arr);

    // Bubble Sort
    bubble_sort(arr);
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
 * Auxiliary Space: O(1), because there is just one (temp) extra-variable to swap the elements
 *
 * Does sorting happen in place in Selection Sort? - Yes  // https://www.geeksforgeeks.org/in-place-algorithm/
 * Is Selection Sort Algorithm stable? - No               // https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/
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

// stable version of Selection Sort
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


/*
 * Major idea of Bubble Sort:
 * To place the largest element in its position and keep doing it for every other element
 *
 * Steps for Bubble sort:
 *
 * you need nested for loop(with counters i & j), 0 <= i < length, 0 <= j < length-i-1
 * 1. catch the elements two by two
 * 2. compare them
 * 3. swap them if needed
 * 4. repeat it till the array is sorted, use a boolean variable to reduce time complexity if possible
 *
 *
 * Complexity analysis of Bubble Sort:
 *
 * Time complexity: O(N^2) - in worst and average case
 *                  O(N) - in best case (if a boolean variable is used)
 * Auxiliary space: O(1) - used only for 'temp' value, while swapping (just one extra-variable)
 *
 * Does sorting happen in place in Bubble Sort? - Yes  // https://www.geeksforgeeks.org/in-place-algorithm/
 * Is Bubble sort Algorithm stable? - Yes              // https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/
 */
void bubble_sort(int *arr){
    int length = len(arr);
    for (int i = 0; i < length; ++i) {
        // adding a boolean variable to lower algorithm's complexity
        bool isSorted = true;
        for (int j = 0; j < length-i-1; ++j) {
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = false;
            }
        }
        if(isSorted) break;
    }
}