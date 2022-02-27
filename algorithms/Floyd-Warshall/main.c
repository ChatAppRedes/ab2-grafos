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
    printf("🦉 PRINT GRAPH %d \n", vertices);
    printf("🍷 READ GRAPH\n");
    readGraph(inputFile, graph, vertices, edges);
    printf("%d\n", graph[1][4]);
    printf("%d\n", graph[3][5]);
    printf("%d\n", graph[5][3]);
    // printf("%d\n", graph[3][5]);
    printf("🍷 END READ GRAPH\n");
    // printGraph(graph, vertices);
    for (int i = 0; i < vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < vertices; j++) {
        printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("🦉 END PRINT GRAPH\n");
    return 0;
}