#include <stdio.h>
#include "../../handleArgs.c"
#include "floyd.h"

int main(int argc, char *argv[])
{
    handleArgs(argv);
    FILE *inputFile = fopen(inputFileName, "r");
    int vertices;
    int edges;
    fscanf(inputFile, "%d %d", &vertices, &edges);
    int *matrix[vertices];
    Graph graph = createGraph(matrix, vertices);
    readGraph(inputFile, graph, vertices, edges);
    floydWarshall(graph, vertices);
    return 0;
}