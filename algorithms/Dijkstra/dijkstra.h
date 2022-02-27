#include "../../data-structures/Graph/graph.h"

void initializeDijkstra(Graph *graph, int *distances, int *predecessor, int s);
int lessDistance(Graph *graph, bool *opened, int *distances);
bool existOpen(Graph *graph, int *open);
void relax(Graph *graph, int *distances, int *predecessor, int u, int v);
int *dijkstra(Graph *graph, int startingVertex);
