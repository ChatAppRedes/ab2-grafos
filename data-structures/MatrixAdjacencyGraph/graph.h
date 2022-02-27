#include <stdio.h>
#define true 1
#define false 0

typedef int bool;
typedef int** Graph;

Graph createGraph(int *matrix[], int verticesAmount);
void createEdge(Graph graph, int initialVertex, int finalVertex, int weight);
void printGraph(Graph graph, int verticesAmount);
void readGraph(FILE *file, Graph graph, int vertices, int edges);