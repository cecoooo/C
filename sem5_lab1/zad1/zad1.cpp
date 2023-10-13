#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time time(1, 2, 3);
    time.print_time_british_format();
    cout << "\n";
    time.print_time_american_format();
}

