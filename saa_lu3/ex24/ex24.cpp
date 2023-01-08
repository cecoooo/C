#include <iostream>
using namespace std;

string toBinary(int n) {
    string text="";
    if (n == 0) {
        return "";
    }
    if (n % 2 == 1) {
        n /= 2;
        return toBinary(n) + "1";
    }
    else {
        n /= 2;
        return toBinary(n) + "0";
    }
}

int main()
{
    int n;
    cin >> n;
    string text = toBinary(n);
    cout << text;
}