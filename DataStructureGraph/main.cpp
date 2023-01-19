#include <iostream>
using namespace std;
#include "Graph.h"

void quick_sort(int arr[], int start, int end);
int partition(int arr[], int start, int end);

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
    quick_sort(arr, 0, 7);
    cout << "\n" << "Sorted: ";
    for (int i = 0; i < 8; ++i) {
        cout << arr[i] << " ";
    }
}

void quick_sort(int arr[], int start, int end){
    if(start < end){
        int pivot_index = partition(arr, start, end);
        quick_sort(arr, start, pivot_index-1);
        quick_sort(arr, pivot_index+1, end);
    }
}

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int pivot_index = start;
    for (int i = start; i < end; ++i) {
        if(arr[i] < pivot) {
            int temp = arr[i];
            arr[i] = arr[pivot_index];
            arr[pivot_index] = temp;
            pivot_index++;
        }
    }
    int temp = arr[end];
    arr[end] = arr[pivot_index];
    arr[pivot_index] = temp;
    return pivot_index;
}