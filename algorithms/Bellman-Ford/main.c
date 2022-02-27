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
    clean(graph);
    return 0;
}