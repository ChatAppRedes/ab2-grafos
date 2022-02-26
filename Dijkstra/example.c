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
    while (argv[iterator] != NULL) {
        printf("ARG: %s\n", argv[iterator]);
        if (!isRecognizedArgWithValue(argv[iterator])) {
            printf("Erro! Argumento [%s] inválido!\n", argv[iterator]);
            return 1;
        }
        iterator++;
        char *value = argv[iterator];
        printf("My Value: %s\n", value);
        iterator++;
    }
    Graph *graph = readGraph();
    printGraph(graph);
    printf("\n\n");
    int selectedVertex = 2;
    int *distances = dijkstra(graph, selectedVertex);
    printf("DIJKSTRA: ");
    for (int i = 0; i < 5; i++) {
        printf("v%d -> v%d: %d\n", selectedVertex, i+1, distances[i]);
    }
    printf("\n");
    return 0;
}