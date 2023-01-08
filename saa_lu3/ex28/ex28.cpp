#include <iostream>
using namespace std;

int checkForNum(int num, int n) {
    if (num <= 0) 
        return 0;
    int m = num % 10;
    if (m == n) 
        return 1;
    return checkForNum((num-m)/10, n);
}

int main()
{
    int n, num;
    cin >> n >> num;
    if (checkForNum(num, n))
        cout << "yes";
    else
        cout << "no";
}