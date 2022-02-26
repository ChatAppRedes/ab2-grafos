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

bool createEdge(Graph *graph, int initialVertex, int finalVertex, int weight) {
  if (!graph) return false;
  if (finalVertex < 0 || finalVertex >= graph->vertices) {
    return false;
  }
  if (initialVertex < 0 || initialVertex >= graph->vertices) {
    return false;
  }
  Adjacency *newAdjacency = createAdjacency(finalVertex, weight);
  newAdjacency->next = graph->adjacency[initialVertex].head;
  graph->adjacency[initialVertex].head = newAdjacency;
  graph->edges++;
  return true;
}

void printGraph(Graph *graph) {
  printf("Vértices %d. Arestas %d.\n", graph->vertices, graph->edges);
  for (int i = 0; i < graph->vertices; i++) {
    printf("v%d: ", i);
    Adjacency *adjacency = graph->adjacency[i].head;
    while (adjacency) {
      printf("v%d(%d) ", adjacency->vertex, adjacency->weight);
      adjacency = adjacency->next;
    }
    printf("\n");
  }
}

Graph *readGraph() {
  int vertices;
  int edges;
  scanf("%d %d", &vertices, &edges);
  getchar();
  // printf("Vertices: %d; Edges: %d\n", vertices, edges);
  Graph *graph = createGraph(vertices);
  int currentAdjacency[3] = {-1, -1, 1};
  int currentPosition = 0;
  while (1) {
    char x = getchar();
    int isInTheEndOfAdjacency = (x == '\n');
    if (isInTheEndOfAdjacency) {
      // printf("Current adjacency: (%d) --[%d]-- (%d)\n", currentAdjacency[0], currentAdjacency[1], currentAdjacency[2]);
      createEdge(graph, currentAdjacency[0], currentAdjacency[1], currentAdjacency[2]);
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
      // printf("Final adjacency: (%d) --[%d]-- (%d)\n", currentAdjacency[0], currentAdjacency[1], currentAdjacency[2]);
      createEdge(graph, currentAdjacency[0], currentAdjacency[1], currentAdjacency[2]);
      currentAdjacency[0] = -1;
      currentAdjacency[1] = -1;
      currentAdjacency[2] = 1;
      currentPosition = 0;
      break;
    }
    currentAdjacency[currentPosition] = xAsInt;
    currentPosition++;
  }
  printf("\n");
  return graph;
}