#include <stdio.h>
#include <stdlib.h>
#include "../data-structures/Graph/graph.c"

int main()
{
    Graph *graph = readGraph();
    printGraph(graph);
    return 0;
}