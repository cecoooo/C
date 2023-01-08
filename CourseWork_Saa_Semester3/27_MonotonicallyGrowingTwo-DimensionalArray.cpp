#include <iostream>
using namespace std;

void printResult(bool isMonotonicallyGrowing);
void invalidData();

int main()
{
    // declare pointers and some important variables
    int* arr, ** matrix, r, c, num;
    //input data for matrix size
    cin >> r >> c;

    // Check if input is valid
    if(r <= 1 || c <= 1)
        invalidData();

    // memory allocation
    arr = (int*)malloc(sizeof(int) * c);
    if (arr == NULL) {
        printf("Memory not allocated for arr.\n");
        exit(0);
    }
    matrix = (int**)malloc(sizeof(int) * c * r);
    if (matrix == NULL) {
        printf("Memory not allocated matrix.\n");
        exit(0);
    }

    // fill matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> num;
            arr[j] = num;
        }
        matrix[i] = arr;
        arr = (int*)malloc(sizeof(int) * c);
        if (arr == NULL) {
            printf("Memory not allocated for arr.\n");
            exit(0);
        }
    }

    bool isMonotonicallyGrowing = true;

    // check if all rows contains monotonically-growing elements
    for (int i = 0; i < r; i++) {
        int d = matrix[i][0] - matrix[i][1];
        for (int j = 0; j < c - 1; j++) {
            if (matrix[i][j] - matrix[i][j + 1] != d || d >= 0)
                isMonotonicallyGrowing = false;
        }
    }

    // check if all columns contains monotonically-growing elements
    for (int i = 0; i < c; i++) {
        int d = matrix[0][i] - matrix[1][i];
        for (int j = 0; j < r-1; j++) {
            if (matrix[j][i] - matrix[j+1][i] != d || d >= 0) {
                isMonotonicallyGrowing = false;
            }
        }
    }

    // check if all diagonals (parallel to main one) contains monotonically-growing elements
    int end = r+c-2;
    for (int k = 1; k < end; ++k) {
        int currArrCount = 0;
        int *currentArr = (int*)malloc(sizeof(int)*1);
        if (currentArr == NULL) {
            printf("Memory not allocated for arr.\n");
            exit(0);
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (i + j == k)
                {
                    currentArr = (int*) realloc(currentArr, sizeof (int)*(currArrCount+1));
                    if (currentArr == NULL) {
                        printf("Memory not allocated for arr.\n");
                        exit(0);
                    }
                    currentArr[currArrCount] = matrix[i][j];
                    currArrCount++;
                }
            }
        }
        int d = currentArr[1]-currentArr[0];
        for (int i = 0; i < currArrCount-1; ++i) {
            if(currentArr[i+1] - currentArr[i] != d || d <= 0)
                isMonotonicallyGrowing = false;
        }
    }

    // free allocated memory
    free(arr);
    free(matrix);

    // print result
    printResult(isMonotonicallyGrowing);
    exit(0);
}

void printResult(bool isMonotonicallyGrowing)
{
    if (isMonotonicallyGrowing)
        cout << "Array is monotonically growing.";
    else
        cout << "Array is not monotonically growing.";
}

void invalidData()
{
    cout << "Invalid size of matrix dimensions." ;
    exit(0);
}