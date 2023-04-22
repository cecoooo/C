#include <iostream>
#include <math.h>
using namespace std;

typedef struct Point{
    double x;
    double y;
} point;

double distance(point p1, point p2);

int main() {

    double x, y;
    cout << "Enter coordinates for first point\n";
    cout << "X:";
    cin >> x;
    cout << "Y:";
    cin >> y;
    point point1;
    point1.x = x;
    point1.y = y;
    cout << "Enter coordinates for second point\n";
    cout << "X:";
    cin >> x;
    cout << "Y:";
    cin >> y;
    point point2;
    point2.x = x;
    point2.y = y;
    cout << "distance: " << distance(point1, point2);
    return 0;
}

double distance(point p1, point p2)
{
    double dist = sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2));
    return dist;
}