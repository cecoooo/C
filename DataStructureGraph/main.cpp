#include <iostream>
using namespace std;
#include "Graph.h"

void heap_sort(int arr[], int N);
int heapify(int arr[], int N, int i);

int main() {
//    Graph<string>* graph = new Graph<string>(5);
//    graph->addNodeToGraph(3, 4);
//    graph->addNodeToGraph(5, 1);
//    graph->addNodeToGraph(2, 4);
//    graph->addNodeToGraph(5, 3);
//    cout << graph->CountOfNodes() << "\n";
//    graph->printGraph();
    int arr[] = {4, 5, 1, 6, 9, 0, 3, 2};
    cout << "Unsorted: ";
    for (int i = 0; i < 8; ++i) {
        cout << arr[i] << " ";
    }
    heap_sort(arr, 8);
    cout << "\n" << "Sorted: ";
    for (int i = 0; i < 8; ++i) {
        cout << arr[i] << " ";
    }
}
