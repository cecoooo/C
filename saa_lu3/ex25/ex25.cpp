#include <iostream>
using namespace std;

double PowerNumber(double x, int n) {
    if (n == 0)
        return 1;
    if (n > 0) {
        n--;
        return x * PowerNumber(x, n);
    }
    else {
        n++;
        return 1/x * PowerNumber(x, n);
    }
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << PowerNumber(x, n);
}