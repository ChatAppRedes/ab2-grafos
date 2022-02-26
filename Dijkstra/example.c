#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.c"

int main()
{
    Graph *graph = readGraph();
    printGraph(graph);
    printf("\n\n");
    int selectedVertex = 1;
    int *distances = dijkstra(graph, selectedVertex);
    printf("DIJKSTRA: ");
    for (int i = 0; i < 5; i++) {
        printf("v%d -> v%d: %d\n", selectedVertex, i+1, distances[i]);
    }
    printf("\n");
    return 0;
}