#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;

typedef struct adj {
  int vertex;
  int weight;
  struct adj *next;
} Adjacency;

typedef struct vertex {
  Adjacency *head; 
} Vertex;

typedef struct sGraph {
  int vertices;
  int edges;
  Vertex *adjacency;
} Graph;

Graph *createGraph(int amountOfVertices) {
  Graph *newGraph = (Graph *) malloc(sizeof(Graph));
  newGraph->vertices = amountOfVertices;
  newGraph->edges = 0;
  newGraph->adjacency = (Vertex *) malloc(amountOfVertices * sizeof(Vertex));
  for (int iterator = 0; iterator < amountOfVertices; iterator++) {
    newGraph->adjacency[iterator].head = NULL;
  }
  return newGraph;
}