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

void bellmanFord(Graph *graph, int initialVertex)
{
    initialVertex--;
    printf("SETUP DISTANCES\n");
    int distances[graph->vertices];
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
    // bool hasNegativeCycle = detectNegativeCycle(graph, distances);
    // printf("END HAS - CYCLE\n");
    // if (hasNegativeCycle) {
    //     printf("Ciclo negativo detectado!\n");
    // }
    // return distances;
}

        // for (int j = 0; j < graph->edges; j++) {
        //     // printf("FOR J %d times\n", j);
        //     // printf("CURRENT VERTEX\n");
        //     int currentVertex = graph->adjacency[j].head->vertex;
        //     // printf("WEIGHT\n");
        //     // int weight = graph->adjacency[j].head->weight;
        //     // printf("NEXT\n");
        //     // int nextVertex = graph->adjacency[j].head->next->vertex;
        //     // printf("COMPARISON\n");
        //     Adjacency *adjacency = graph->adjacency[currentVertex].head;
        //     int v = adjacency->vertex;
        //     while(adjacency && adjacency->vertex != v)
        //         adjacency = adjacency->next;
        //     if (adjacency) 
        //     {
        //         if(
        //             distances[currentVertex] != INFINITY
        //             && distances[v] > distances[currentVertex] + adjacency->weight
        //         )
        //         {
        //             distances[v] = distances[currentVertex] + adjacency->weight;
        //             predecessors[v] = currentVertex;
        //         }    
        //     }
        //     // if (
        //     //     distances[currentVertex] != INFINITY 
        //     //     && distances[nextVertex] > distances[currentVertex] + weight
        //     // ) {
        //     //     distances[nextVertex] = distances[currentVertex] + weight;
        //     //     predecessors[nextVertex] = currentVertex;
        //     // }
        //     // printf("END COMPARISON\n");
        // }
        // printf("END FOR J %d times\n", i);