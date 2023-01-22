/*
 * The code works correctly.
 *
 * However...
 * By unknown for me reason, it appends '0' at the end of every array, entered by the console.
 * If you find the bug, you are free to fix it, otherwise do not wonder why your array contains one, two or more extra '0' elements.
 * The reason may be somewhere between functions' communication, the compiler, or it's just "The Magic" of c/c++.
 * ;)
 * */


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
    return i-1;
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
void insertion_sort(int *arr);
void merge_sort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);
void quick_sort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void heap_sort(int arr[], int N);
void heapify(int arr[], int N, int i);

int main() {
    int *arr = input_arr();
    print_arr(arr);

//    // Selection Sort
//    selection_sort(arr);
//    print_arr(arr);
//    selection_sort_stable(arr);

//    // Bubble Sort
//    bubble_sort(arr);

//    // Insertion Sort
//    insertion_sort(arr);

//    // Merge Sort
//    merge_sort(arr, 0, len(arr)-1);

//    // Quick Sort
//    quick_sort(arr, 0, len(arr)-1);

    // Heap sort
    heap_sort(arr, len(arr));

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
 * Steps for Bubble Sort:
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
 * Is Bubble Sort Algorithm stable? - Yes              // https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/
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


/*
 * About Insertion Sort:
 *
 * The algorithm looks like Selection Sort, but it's a bit different.
 * It divides the array int two parts - sorted and unsorted.
 * Insertion Sort puts elements in the unsorted subarray in the sorted one on their correct position.
 * The algorithm is useful for small data values and almost sorted collections
 *
 * Steps for Insertion Sort:
 *
 * you need a for loop and a nested while loop
 * 1. iterate through the array
 * 2. compare the current element with its previous one (for(i) starts int this way i = 1)
 * 3. if the current element is higher the next one, then swap both and go on till you reach arr[i] >= arr[i-1].
 * in this way you paste another element in the sorted subarray
 *
 *
 * Complexity analysis of Insertion Sort:
 *
 * Complexity time
 * Worst and average case: O(N^2) or near, there are two nested loops
 * Best case: O(N)
 *
 * Auxiliary space: O(1) = only one extra-variable for swapping elements
 *
 *
 * Does sorting happen in place in Insertion Sort? - Yes  // https://www.geeksforgeeks.org/in-place-algorithm/
 * Is Insertion Sort algorithm stable? - Yes  // https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/
 * */
void insertion_sort(int *arr){
    int length = len(arr);
    for (int i = 1; i < length; ++i) {
        int j = i;
        while(arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j-=1;
            if(j == 0) break;
        }
    }
}

/*
 * Merge Sort:
 * - The algorithm divides the array by smaller subarrays, sorting each of the and merge them back together.
 * - Useful for large amount of data, because its low time complexity.
 * - it's a mainly recursive algorithm which makes some difficulties for newbies to understand its logic.
 *
 *
 * Steps for Merge Sort:
 *
 * you need two functions (merge_sort() & merge()) which will be invoked recursively
 * 1. Find the middle point of the array by its most left and most right index (firstly they are going to be 0 & arr.len - 1)
 * 2. Call merge_sort function for first half
 * 3. Call merge_sort function for second half
 * 4. After that, call merge function to unite array's parts alternately
 *
 *
 * Complexity analysis of Merge Sort
 *
 * Time complexity: O(N*log(N))
 * Auxiliary space: O(N)
 *
 * Does sorting happen in place in Merge Sort? - No  // https://www.geeksforgeeks.org/in-place-algorithm/
 * Is Merge Sort algorithm stable? - Yes  // https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/
 * */

void merge_sort(int *arr, int l, int r){
    if(l < r){
        int m = l + (r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m ,r);
    }
}

void merge(int *arr, int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];

    for (i = 0; i < n1; ++i)
        L[i] = arr[l+i];
    for (j = 0; j < n2; ++j)
        R[j] = arr[m+1+j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*
 * Quick Sort:
 * - It picks an element as a pivot and partitions all other elements around the pivot element.
 * - Useful for large amount of data structures.
 * - Like Merge Sort, Quick Sort uses 'divide and conquer' technic via recurse
 *
 *
 * Steps for Quick Sort:
 *
 * you need two functions (quick_sort() and partition())
 * 1. quick_sort() function is invoked recursively, it needs as arguments an array, its start and end index
 * 2. key function is partition(). It unites the elements around the pivot and take responsibility for start & end indexes
 * How to choose the pivot? - You move here. In most cases, pivot is the last element in the current subarray.
 * 3. continue while (start < end)
 *
 *
 * Complexity analysis of Quick Sort:
 *
 * Time complexity
 * Worst case: O(N*N)
 * Average case: O(N*log(N)), most common
 * Best case: O(N)
 * Best case: O(N);
 *
 * Auxiliary space: O(1), constant complexity here, only temp variables for swapping
 *
 *
 * Does sorting happen in place in Quick Sort? - Yes  // https://www.geeksforgeeks.org/in-place-algorithm/
 * Is Quick Sort algorithm stable? - No  // https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/
 * */

void quick_sort(int arr[], int start, int end){
    if(start < end){
        int pivot_index = partition(arr, start, end);
        quick_sort(arr, start, pivot_index-1);
        quick_sort(arr, pivot_index+1, end);
    }
}

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int pivot_index = start;
    for (int i = start; i < end; ++i) {
        if(arr[i] < pivot) {
            int temp = arr[i];
            arr[i] = arr[pivot_index];
            arr[pivot_index] = temp;
            pivot_index++;
        }
    }
    int temp = arr[end];
    arr[end] = arr[pivot_index];
    arr[pivot_index] = temp;
    return pivot_index;
}

/*
 * Heap Sort
 * - Based on Binary Heap data structure
 * - Nevertheless algorithm is using recursion, it's not strongly recursive
 * - Heap Sort is easier to implement than other equally efficient sorting algorithms
 * - It's not very useful for complex data
 * - 2 to 3 times slower than Merge Sort, not an example of 'Divide & Conquer' algorithm
 * To understand this algorithm, you must be aware of Binary Heap  // https://www.geeksforgeeks.org/binary-heap/
 *
 *
 * Steps for Heap Sort:
 *
 * you need two functions - heap_sort() & heapify()
 * 1. First step is to form a Max Binary Heap from the given array
 * You have to do that with heapify() function, invoking it n/2-1 times in heap_sort() function, use for loop.
 * 2. When you heapify you array get the root and put it in the end of the array
 * 3. Heapify again, but this time heapify elements till the previous index
 * After every heapify operation, one element is sorted in the end of the array.
 * That's the reason we heapify with one element less than the previous operation.
 * 4. Repeat this process until the size of heap is greater than 1.
 *
 *
 * Complexity analysis of Heap Sort:
 *
 * Time complexity: O(N*log(N))
 * Auxiliary space: O(1), nothing more than 'temp' variable for swapping
 *
 *
 * Does sorting happen in place in Heap Sort? - Yes  // https://www.geeksforgeeks.org/in-place-algorithm/
 * Is Heap Sort algorithm stable? - No  // https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/
 * */

void heap_sort(int arr[], int N){
    for (int i = N/2-1; i >= 0; i--)
        heapify(arr, N, i);


    for (int i = N-1; i > 0; i--) {

        // swap elements
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int N, int i){
    int largest = i;

    int left = i*2+1;
    int right = i*2+2;

    if(left < N && arr[left] > arr[largest])
        largest = left;
    if(right < N && arr[right] > arr[largest])
        largest = right;

    if(largest != i){

        // swap elements
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(arr, N, largest);
    }
}