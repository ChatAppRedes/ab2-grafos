#include <stdio.h>
#include "graph.h"

int main() {
  Graph *graph = createGraph(5);
  createEdge(graph, 0, 1, 2);
  createEdge(graph, 1, 2, 4);
  createEdge(graph, 2, 0, 12);
  createEdge(graph, 2, 4, 40);
  createEdge(graph, 3, 1, 3);
  createEdge(graph, 4, 3, 8);

  printGraph(graph);

  return 0;
}