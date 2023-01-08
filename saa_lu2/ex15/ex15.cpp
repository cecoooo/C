#include <iostream>
using namespace std;

int main()
{
    int* arr, c, r, **matrix, num;
    cin >> c >> r;
    matrix = (int**)malloc(sizeof(int) * c * r);
    for (int i = 0; i < r; i++) {
        arr = (int*)malloc(sizeof(int) * c);
        for (int j = 0; j < c; j++) {
            cin >> num;
            arr[j] = num;
        }
        matrix[i] = arr;
    }
    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || i == r-1 || j == 0 || j == c-1) {
                sum += matrix[i][j];
            }
        }
    }
    free(matrix);
    cout << sum;
}