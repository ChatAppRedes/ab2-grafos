#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATTERNS_SIZE 4
#define NON_VALUE_PATTERNS_SIZE 2

int iterator = 1;
int initialVertex = 0;
int finalVertex = 0;
char *outputFileName = "output.alg";
char *inputFileName = "input.data";
int showCompleteSolution = 0;

int isRecognizedArgWithValue(char *argument) {
    char *patterns[PATTERNS_SIZE] = {
        "-f",
        "-o",
        "-i",
        "-l"
    };
    for (int i = 0; i < PATTERNS_SIZE; i++) {
        if(strcmp(argument, patterns[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isRecognizedArgWithoutValue(char *argument) {
    char *patterns[NON_VALUE_PATTERNS_SIZE] = {
        "-h",
        "-s"
    };
    for (int i = 0; i < NON_VALUE_PATTERNS_SIZE; i++) {
        if(strcmp(argument, patterns[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void showHelp() {
    printf("\n\n======= AJUDA =======\n");
    printf("-h : Mostra a ajuda\n");
    printf("-o <arquivo> : redireciona a saida para o ‘‘arquivo’’\n");
    printf("-f <arquivo> : indica o ‘‘arquivo’’ que contém o grafo de entrada\n");
    printf("-s :  mostra a solução (em ordem crescente)\n");
    printf("-i : vértice inicial (dependendo do algoritmo)\n");
    printf("-l : vértice final (dependendo do algoritmo)\n");
    printf("=====================\n\n");
}

void handleArgs(char *argv[]) {
    char *lastRecognizedArgumentWithValue = "";
    while (argv[iterator] != NULL) {
        char *currentArgument = argv[iterator];
        if (isRecognizedArgWithValue(currentArgument)) {
            lastRecognizedArgumentWithValue = currentArgument;
            iterator++;
            continue;
        }
        if (isRecognizedArgWithoutValue(currentArgument)) {
            if (strcmp(currentArgument, "-s") == 0) {
                showCompleteSolution = 1;
            } else if (strcmp(currentArgument, "-h") == 0) {
                showHelp();
            }
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
    // printf("INITIAL VERTEX: %d\n", initialVertex);
    // printf("FINAL VERTEX: %d\n", finalVertex);
    // printf("OUTPUT FILE NAME: %s\n", outputFileName);
    // printf("INPUT FILE NAME: %s\n", inputFileName);
    // printf("ASCENDING ORDER: %d\n", showCompleteSolution);
}