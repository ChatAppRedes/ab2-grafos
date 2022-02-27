#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dijkstra.h"

// void x(tStack *graph, int startingVertex) {
//     graph->
// }

void initializeDijkstra(Graph *graph, int *distances, int *predecessor, int s)
{
    int vertex;

    for (vertex = 0; vertex < graph->vertices ; vertex++)
    {
        distances[vertex] = INT_MAX/2;
        predecessor[vertex] = -1;
    }
    distances[s] = 0;
}

int lessDistance(Graph *graph, bool *opened, int *distances) {
    int i;
    for(i=0; i <graph->vertices; i++)
    {
        if(opened[i]){
            break;
        }
    }
    if(i == graph->vertices)
    {
        return (-1);
    }
    int less = i;

    for(i = less + 1; i<graph->vertices; i++)
    {
        if(opened[i] && (distances[less]>distances[i]))
        {
            less = i;
        }
    }
    return(less);
}


bool existOpen(Graph *graph, int *open)
{
    int i;

    for(int i = 0; i<graph->vertices; i++)
    {
        if (open[i])
        {
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

int *dijkstra(Graph *graph, int startingVertex)
{
    startingVertex--;
    int *distances = (int *) malloc(graph->vertices * sizeof(int));
    int predecessors[graph->vertices];
    bool opened[graph->vertices];
    initializeDijkstra(graph, distances, predecessors, startingVertex);
    
    for (int i = 0; i < graph->vertices; i++) {
        opened[i] = true;
    }

    while (existOpen(graph, opened)) {
        int u = lessDistance(graph, opened, distances);
        opened[u] = false;
        Adjacency *adjacency = graph->adjacency[u].head;
        while (adjacency) {
            relax(graph, distances, predecessors, u, adjacency->vertex);
            adjacency = adjacency->next;
        }
    }
    return distances;
}