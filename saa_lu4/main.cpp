#include <iostream>
using namespace std;

int main() {
    char arr[] = "asdffdsa";
    bool isTrue = true;
    for (int i = 0; i < 8/2; ++i) {
        if (arr[i] != arr[8-1-i])
            isTrue = false;
    }
    cout << isTrue;
}
