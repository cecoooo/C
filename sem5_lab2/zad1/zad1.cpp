#include <iostream>
#include "Rectangular.h"
using namespace std;

int main()
{
    Rectangular rect(2,3);
    cout << "Face: " << rect.face() << '\n';
    int p;
    cout << "Face: " << rect.face(&p) << '\n';
    cout << "Perimeter: " << p;
}
