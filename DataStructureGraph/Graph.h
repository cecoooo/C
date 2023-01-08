#include "iostream";
using namespace std;
template <typename T>

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


class Graph {
    T** arr;
    int countOfNodes;

public:
    Graph(int v){
        this->countOfNodes = v;
        this->arr = (T**)malloc(sizeof(T)*v*v);
    }
    void addNodeToGraph(int v, int u){
        this->arr[v-1][u-1] = "Connected";
        this->arr[u-1][v-1] = "Connected";
    }
    int CountOfNodes(){
        return this->countOfNodes;
    }
    void printGraph(){
        for (int i = 0; i < this->countOfNodes; ++i) {
            for (int j = 0; j < this->countOfNodes; ++j) {
                cout << this->arr[i][j] << "\n";
            }
        }
    }
};


#endif //GRAPH_GRAPH_H