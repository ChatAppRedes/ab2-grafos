#include <stdio.h>
#include "graph.h"

int main() {
  int *matrix[5];
  Graph graph = createGraph(matrix, 5);
  printf("Create EDGE 1\n");
  createEdge(graph, 0, 1, 2);
  printf("Create EDGE 2\n");
  createEdge(graph, 1, 2, 4);
  printf("Create EDGE 3\n");
  createEdge(graph, 2, 0, 12);
  printf("Create EDGE 4\n");
  createEdge(graph, 2, 4, 4);
  printf("Create EDGE 5\n");
  createEdge(graph, 3, 1, 3);
  printf("Create EDGE 6\n");
  createEdge(graph, 4, 3, 8);

  printf("Print graph\n");
  printGraph(graph, 5);

  return 0;
}