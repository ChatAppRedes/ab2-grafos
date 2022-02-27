#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../handleArgs.c"
#include "dijkstra.h"

int main(int argc, char *argv[])
{
    handleArgs(argv);
    FILE *inputFile = fopen(inputFileName, "r");
    Graph *graph = readGraph(inputFile);
    int *distances = dijkstra(graph, initialVertex);
    FILE *outFile = fopen(outputFileName, "w");
    if (finalVertex == 0 || showCompleteSolution) {
        for (int i = 0; i < graph->vertices; i++) {
            printf("%d:%d ", i+1, distances[i]);
            fprintf(outFile, "%d:%d ", i+1, distances[i]);
        }
        printf("\n");
    } else {
        printf("%d\n", distances[finalVertex - 1]);
        printf("\n");
        fprintf(outFile, "%d\n", distances[finalVertex - 1]);
    }
    clean(graph);
    return 0;
}