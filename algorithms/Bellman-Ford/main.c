#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../handleArgs.c"
#include "ford.h"

int main(int argc, char *argv[])
{
    handleArgs(argv);
    FILE *inputFile = fopen(inputFileName, "r");
    Graph *graph = readGraph(inputFile);
    printGraph(graph);
    printf("FORD: \n");
    bellmanFord(graph, initialVertex);
    // for (int i = 0; i < graph->vertices; i++) {
    //     printf("v%d -> v%d: %d\n", initialVertex, i+1, distances[i]);
    // }
    // FILE *outFile = fopen(outputFileName, "w");
    // fprintf(outFile, "%d\n", distances[finalVertex - 1]);
    // printf("%d\n", distances[finalVertex - 1]);
    // printf("\n");
    return 0;
}