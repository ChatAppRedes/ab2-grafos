#include "../../data-structures/Graph/graph.h"

bool detectNegativeCycle(Graph *graph, int distances[]);
void relax(Graph *graph, int *distances, int *predecessor, int u, int v);
int *bellmanFord(Graph *graph, int initialVertex);
