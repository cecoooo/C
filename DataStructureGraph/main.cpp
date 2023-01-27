#include <iostream>
using namespace std;
#include "Graph.h"

int main() {
    Graph<string>* graph = new Graph<string>(5);
    graph->addNodeToGraph(3, 4);
    graph->addNodeToGraph(5, 1);
    graph->addNodeToGraph(2, 4);
    graph->addNodeToGraph(5, 3);
    cout << graph->CountOfNodes() << "\n";
    graph->printGraph();
}
