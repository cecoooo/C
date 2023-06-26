#include <iostream>
#include "cmake-build-debug/Queue.h"
#include "cmake-build-debug/Stack.h"

using namespace std;

int main() {
//    Queue<int> *queue = new Queue<int>();
//    queue->push(1);
//    queue->push(2);
//    queue->push(3);
//    queue->push(4);
//    cout << "head:" << queue->peek()<<"\n";
//    queue->pop();
//    cout << "head:" << queue->peek();


    int *a, b;
    a = (int*)malloc(sizeof(int)*2);
    a[0] = 1;
    a[1] = 2;
    b = a[0];
    a[0] = 10;
    cout << a[0] <<"\n";
    cout << b <<"\n";
    free(a);

    //Stack<int> *stack = new Stack<int>();


}
