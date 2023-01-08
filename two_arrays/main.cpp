#include <iostream>
using namespace std;
#include <float.h>

void swap(double *arr, int m, int n){
    double x = arr[m];
    double y = arr[n];
    arr[n] = x;
    arr[m] = y;
}

void printArr(double *arr, int n){
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}

void print2DArr(double **arr, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void input2DArray(double **array, int n){
    double* arr = (double*)malloc(sizeof(double)*n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double num;
            cout << "Enter number: ";
            cin >> num;
            arr[j] = num;
        }
        array[i] = arr;
        arr = (double*)malloc(sizeof(double)*n);
    }
    free(arr);
}

int main() {
    cout << "Create a program which works with two arrays A[N,N] and B[N,N] where data are double numbers [-1000,1000].\n"
               "Program must be able yo do:\n"
               "- Print the requirements for you task;\n"
               "- Print full name of the author;\n"
               "- accept the input's data;\n"
               "- print the input's data\n"
               "a) create one-dimensional array C, which elements are the average number of the row's numbers in array A;\n"
               "b) Array C must be ordered by ascending.\n"
               "- print the results after a) and b)\n";
    cout << "\nFull name of the author\n";

    double n, **A, **B, *C;
    cout << "Enter dimension's size: ";
    cin >> n;
    A = (double**) malloc(sizeof(double)*n*n);
    B = (double**) malloc(sizeof(double)*n*n);

    cout << "Input data for array A.\n";
    input2DArray(A, n);
    cout << "Input data for array B.\n";
    input2DArray(B, n);
    cout << "Output data for array A.\n";
    print2DArr(A, n);
    cout << "Output data for array B.\n";
    print2DArr(B, n);

    C = (double*)malloc(sizeof(double)*n);
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += A[i][j];
        }
        C[i] = sum/n;
    }

    cout << "Output data for array C before sorting.\n";
    printArr(C, n);

    for (int i = 0; i < n; ++i) {
        double min = DBL_MAX;
        int index;
        for (int j = i; j < n; ++j) {
            if(C[j] < min){
                min = C[j];
                index = j;
            }
        }
        swap(C, i, index);
    }

    cout << "\nOutput data for array C after sorting.\n";
    printArr(C, n);

    free(A);
    free(B);
    free(C);
}