#include "floyd.h"

void floydWarshall(Graph graph, int verticesAmount) {
  int *matrix[verticesAmount];
  Graph newGraph = createGraph(matrix, verticesAmount);
  for (int i = 0; i < verticesAmount; i++)  {
    for (int j = 0; j < verticesAmount; j++)  {
      newGraph[i][j] = graph[i][j];
    }
  }

  for (int k = 0; k < verticesAmount; k++) {
    for (int i = 0; i < verticesAmount; i++) {
      for (int j = 0; j < verticesAmount; j++) {
        if (newGraph[i][k] + newGraph[k][j] < newGraph[i][j]) {
          newGraph[i][j] = newGraph[i][k] + newGraph[k][j];
        }
      }
    }
  }

  printGraph(newGraph, verticesAmount);
}