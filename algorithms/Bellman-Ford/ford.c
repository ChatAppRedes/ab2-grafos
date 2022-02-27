#include <stdio.h>
#include <limits.h>
#include "../../data-structures/Graph/graph.c"

const int INFINITY = INT_MAX / 2;

bool detectNegativeCycle(Graph *graph, int distances[]) {
    for (int i = 0; i < graph->edges; i++) {
        int currentVertex = graph->adjacency[i].head->vertex;
        int weight = graph->adjacency[i].head->weight;
        int nextVertex = graph->adjacency[i].head->next->vertex;
        if (
            distances[currentVertex] != INFINITY 
            && distances[nextVertex] > distances[currentVertex] + weight
        ) {
            return true;
        }
    }
    return false;
}

void relax(Graph *graph, int *distances, int *predecessor, int u, int v)
{
    Adjacency *adjacency = graph->adjacency[u].head;
    while(adjacency && adjacency->vertex != v)
        adjacency = adjacency->next;
    if (adjacency) 
    {
        if(distances[v] > distances[u] + adjacency->weight)
        {
            distances[v] = distances[u] + adjacency->weight;
            predecessor[v] = u;
        }    
    }
}

int *bellmanFord(Graph *graph, int initialVertex)
{
    initialVertex--;
    printf("SETUP DISTANCES\n");
    int *distances = (int *) malloc(graph->vertices * sizeof(int));
    printf("SETUP PREDECESSORS\n");
    int predecessors[graph->vertices];
    printf("SETUP\n");
    for (int i = 0; i < graph->vertices; i++) {
        distances[i] = INFINITY;
        predecessors[i] = 0;
    }
    printf("END SETUP\n");
    distances[initialVertex] = 0;
    printf("FOR I\n");
    for (int i = 0; i <= graph->vertices - 1; i++) {
        printf("FOR I %d times\n", i);
        Adjacency *adjacency = graph->adjacency[i].head;
        while(adjacency) {
            relax(graph, distances, predecessors, i, adjacency->vertex);
            adjacency = adjacency->next;
        }
    }
    printf("END FOR I\n");
    printf("HAS - CYCLE\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("DISTANCES: \n");
        printf("%d: %d\n", i+1, distances[i]);
        printf("END DISTANCES: \n");
    }
    return distances;
}