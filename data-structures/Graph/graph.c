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

Adjacency *createAdjacency(int vertex, int weight) {
  Adjacency *newAdjacency = (Adjacency *) malloc(sizeof(Adjacency));
  newAdjacency->vertex = vertex;
  newAdjacency->weight = weight;
  newAdjacency->next = NULL;
  return newAdjacency;
}

// bool createEdge(Graph *graph, int initialVertex, int finalVertex, int weight) {
//   if (!graph) return false;
//   if (finalVertex < 0 || finalVertex >= graph->vertices) {
//     return false;
//   }
//   if (initialVertex < 0 || initialVertex >= graph->vertices) {
//     return false;
//   }
//   Adjacency *newAdjacency = createAdjacency(finalVertex, weight);

// }