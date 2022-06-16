#include <iostream>
#include "Graph.h"
#include "Prim.h"

int main() {
    Graph graph(5);
    graph.add_edge(Edge{0, 1 , 1});
    return 0;
}
