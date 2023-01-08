#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0, c = 1;
    for (int i = 0; i < n-2; i++) {
        count += c;
        if (i % 2 == 1)
            c++;
    }
    count *= 2;
    count += n / 2;
    cout << count;
}

// (n - 2) * 2 + 1 = 
// n - 2 => (1+1+2+2+...)*2 + n/2;