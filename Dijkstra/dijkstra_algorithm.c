#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void initializeD(GRAFO *g, int *d, int *p, int*s)
{
    int v;

    for (v=0;<g->vertices;v++)
    {
        d[v] = INT_MAX/2;
        p[v] = -1;
    }
    d[s] = 0;
}

void relaxa(GRAFO *g, int *d, int *p, int u, int v)
{
    ADJACENCIA *ad = g->adj[u].cab;
    while(ad && ad->vertice != v)
        ad = ad->prox;
    if(d[v] > d[u] + ad->peso)
    {
        d[v] = d[u] + ad->peso;
        p[v] = u;
    }    
}