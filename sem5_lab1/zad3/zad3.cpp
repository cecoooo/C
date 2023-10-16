#include <iostream>
using namespace std;
#include "Line.h"

int main()
{
    Line line(100);
    cout << "Should I delete the line?: y/n\n";
    char answ;
    cin >> answ;
    if (answ == 'n') {
        exit(0);
    }
}