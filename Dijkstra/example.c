#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dijkstra.c"

#define PATTERNS_SIZE 4
#define NON_VALUE_PATTERNS_SIZE 2

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

bool isRecognizedArgWithoutValue(char *argument) {
    char *patterns[NON_VALUE_PATTERNS_SIZE] = {
        "-h",
        "-s"
    };
    for (int i = 0; i < NON_VALUE_PATTERNS_SIZE; i++) {
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
    char *outputFileName = "dijkstra.out";
    char *inputFileName = "graph1.data";
    char *lastRecognizedArgumentWithValue = "";
    while (argv[iterator] != NULL) {
        char *currentArgument = argv[iterator];
        printf("ARG: %s\n", currentArgument);
        if (isRecognizedArgWithValue(currentArgument)) {
            lastRecognizedArgumentWithValue = currentArgument;
            iterator++;
            continue;
        }
        if (isRecognizedArgWithoutValue(currentArgument)) {
            iterator++;
            continue;
        }
        if (strcmp(lastRecognizedArgumentWithValue, "-i") == 0) {
            initialVertex = atoi(currentArgument);
        } else if (strcmp(lastRecognizedArgumentWithValue, "-l") == 0) {
            finalVertex = atoi(currentArgument);
        } else if (strcmp(lastRecognizedArgumentWithValue, "-o") == 0) {
            outputFileName = currentArgument;
        } else if (strcmp(lastRecognizedArgumentWithValue, "-f") == 0) {
            inputFileName = currentArgument;
        }
        iterator++;
    }
    printf("INITIAL VERTEX: %d\n", initialVertex);
    printf("FINAL VERTEX: %d\n", finalVertex);
    printf("OUTPUT FILE NAME: %s\n", outputFileName);
    printf("INPUT FILE NAME: %s\n", inputFileName);
    FILE *inputFile = fopen(inputFileName, "r");
    Graph *graph = readGraph(inputFile);
    printGraph(graph);
    printf("\n\n");
    int *distances = dijkstra(graph, initialVertex);
    printf("DIJKSTRA: ");
    for (int i = 0; i < 5; i++) {
        printf("v%d -> v%d: %d\n", initialVertex, i+1, distances[i]);
    }
    FILE *outFile = fopen(outputFileName, "w");
    fprintf(outFile, "%d\n", distances[finalVertex - 1]);
    printf("%d\n", distances[finalVertex - 1]);
    printf("\n");
    return 0;
}