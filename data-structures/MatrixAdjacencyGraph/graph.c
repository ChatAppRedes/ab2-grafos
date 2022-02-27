#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph createGraph(int *matrix[], int verticesAmount) {
  for (int i = 0; i < verticesAmount; i++) {
    matrix[i] = (int *) malloc(verticesAmount * sizeof(int));
  }
  for (int i = 0; i < verticesAmount; i++) {
    for (int j = 0; j < verticesAmount; j++) {
      matrix[i][j] = 0;
    }
  }
  printf("🙈 CREATE GRAPH: %d\n", matrix[5][3]);
  return matrix;
}

void createEdge(
  Graph graph, 
  int initialVertex, 
  int finalVertex, 
  int weight
) {
  printf("INITIAL -> FINAL\n");
  graph[initialVertex][finalVertex] = weight;
  printf("FINAL -> INITIAL\n");
  graph[finalVertex][initialVertex] = weight;
  printf("END EDGE\n");
}

void printGraph(Graph graph, int verticesAmount) {
  for (int i = 0; i < verticesAmount; i++) {
    printf("%d: ", i);
    for (int j = 0; j < verticesAmount; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
}

void readGraph(FILE *file, Graph graph, int vertices, int edges) {

  fgetc(file);
  // printf("Vertices: %d; Edges: %d\n", vertices, edges);

  int currentAdjacency[3] = {-1, -1, 1};
  int currentPosition = 0;
  while (1) {
    char x = fgetc(file);
    int isInTheEndOfAdjacency = (x == '\n');
    if (isInTheEndOfAdjacency) {
      // printf("Current adjacency: (%d) --[%d]-- (%d)\n", currentAdjacency[0], currentAdjacency[2], currentAdjacency[1]);
      createEdge(graph, currentAdjacency[0] - 1, currentAdjacency[1] - 1, currentAdjacency[2]);
      // printf("RESULT: %d \n", result);
      currentAdjacency[0] = -1;
      currentAdjacency[1] = -1;
      currentAdjacency[2] = 1;
      currentPosition = 0;
      continue;
    }
    if (x == ' ') continue;
    int xAsInt = atoi(&x);
    int isEOF = (x != '0' && xAsInt == 0);
    if (isEOF) {
      // printf("Final adjacency: (%d) --[%d]-- (%d)\n", currentAdjacency[0], currentAdjacency[2], currentAdjacency[1]);
      createEdge(graph, currentAdjacency[0] - 1, currentAdjacency[1] - 1, currentAdjacency[2]);
      // printf("RESULT: %d \n", result);
      currentAdjacency[0] = -1;
      currentAdjacency[1] = -1;
      currentAdjacency[2] = 1;
      currentPosition = 0;
      break;
    }
    currentAdjacency[currentPosition] = xAsInt;
    currentPosition++;
  }
  printf("🙈 READ GRAPH: %d\n", graph[5][3]);
  // return graph;
}