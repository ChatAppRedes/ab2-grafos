#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dijkstra.c"

#define PATTERNS_SIZE 4

bool isRecognizedArgWithValue(char *argument) {
    char *patterns[PATTERNS_SIZE] = {
        "-f",
        "-o",
        "-i",
        "-l"
    };
    for (int i = 0; i < PATTERNS_SIZE; i++) {
        if(strcmp(argument, patterns[i]) == 0) {
            printf("FOUND PATTERN! %s\n", patterns[i]);
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    printf("%d\n", argc);
    int iterator = 1;
    int initialVertex = 0;
    int finalVertex = 0;
    while (argv[iterator] != NULL) {
        char *currentArgument = argv[iterator];
        printf("ARG: %s\n", currentArgument);
        if (!isRecognizedArgWithValue(currentArgument)) {
            printf("Erro! Argumento [%s] inválido!\n", currentArgument);
            return 1;
        }
        iterator++;
        char *nextArgument = argv[iterator];
        if (strcmp(currentArgument, "-i") == 0) {
            initialVertex = atoi(nextArgument);
        } else if (strcmp(currentArgument, "-l") == 0) {
            finalVertex = atoi(nextArgument);
        }
        printf("My Value: %s\n", nextArgument);
        iterator++;
    }
    printf("INITIAL VERTEX: %d\n", initialVertex);
    printf("FINAL VERTEX: %d\n", finalVertex);
    Graph *graph = readGraph();
    printGraph(graph);
    printf("\n\n");
    int *distances = dijkstra(graph, initialVertex);
    printf("DIJKSTRA: ");
    for (int i = 0; i < 5; i++) {
        printf("v%d -> v%d: %d\n", initialVertex, i+1, distances[i]);
    }
    printf("%d\n", distances[finalVertex - 1]);
    printf("\n");
    return 0;
}