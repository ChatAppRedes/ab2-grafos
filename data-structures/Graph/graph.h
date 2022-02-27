#define true 1
#define false 0

typedef int bool;
typedef struct adj Adjacency;
typedef struct vertex Vertex;
typedef struct sGraph Graph;

struct adj {
  int vertex;
  int weight;
  struct adj *next;
};

struct vertex {
  struct adj *head; 
};

struct sGraph {
  int vertices;
  int edges;
  struct vertex *adjacency;
};

Graph *createGraph(int amountOfVertices);
Adjacency *createAdjacency(int vertex, int weight);
bool createEdge(Graph *graph, int initialVertex, int finalVertex, int weight);
void printGraph(Graph *graph);
Graph *readGraph(FILE *file);
void clean (Graph *graph);