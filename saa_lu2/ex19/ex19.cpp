#include <iostream>
using namespace std;

int main()
{
    int* arr, ** matrix, r, c, num, sum = 0;
    cin >> r >> c;
    matrix = (int**)malloc(sizeof(int) * r * c);
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
            if (j+i+1 == c) {
                sum += matrix[i][j];
            }
        }
    }
    cout << sum;
    free(matrix);
}
