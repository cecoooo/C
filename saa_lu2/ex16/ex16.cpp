#include <iostream>
using namespace std;

int main()
{
    int* arr, ** matrix, r, c, num, *res, sumMainDiagonal = 0, sumUnderMainDiagonal = 0;
    cin >> c >> r;
    matrix = (int**)malloc(sizeof(int) * r * c);
    res = (int*)malloc(sizeof(int) * (2 + r));
    for (int i = 0; i < r; i++) {
        arr = (int*)malloc(sizeof(int) * c);
        for (int j = 0; j < c; j++) {
            cin >> num;
            arr[j] = num;
        }
        matrix[i] = arr;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j == i) {
                sumMainDiagonal += matrix[i][j];
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j == i) {
                sumMainDiagonal += matrix[i][j];
            }
        }
    }
    res[0] = sumMainDiagonal;
    int co = 1;
    for (int i = 0; i < r; i++) {
        int sumRow = 0;
        for (int j = 0; j < c; j++) {
            sumRow += matrix[i][j];
        }
        res[co] = sumRow;
        co++;
    }
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j < i && matrix[i][j] < i + j) {
                sumUnderMainDiagonal += matrix[i][j];
            }
        }
    }
    res[co] = sumUnderMainDiagonal;
    for (int i = 0; i < r+2; i++) {
        cout << res[i] << " ";
    }
    free(res);
    free(matrix);
}