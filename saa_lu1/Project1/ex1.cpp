#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;
    cin >> num;
    for (int i = 0; i < 3; i++)
    {
        sum += num % 10;
        num -= num % 10;
        num /= 10;
    }
    cout << sum;
    return 0;
}