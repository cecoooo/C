#include <iostream>
#include "cmake-build-debug/Queue.h"

using namespace std;

int main() {
    Queue<int> *queue = new Queue<int>();
    queue->push(1);
    queue->push(2);
    queue->push(3);
    queue->push(4);
    cout << queue->peek();

//    int* arr;
//    free(arr);
//    arr = new int[5];
//    arr[0] = 1;
//    arr[1] = 2;
//    arr[2] = 3;
//    int *newarr;
//    newarr = (int*)realloc(arr, sizeof(int)*5);
//    newarr = (int*)realloc(arr, sizeof(int)*8);
//    arr = newarr;
//    free(newarr);

}
