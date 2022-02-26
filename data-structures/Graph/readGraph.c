void readGraph() {
    int vertices;
    int edges;
    scanf("%d %d", &vertices, &edges);
    getchar();
    printf("Vertices: %d; Edges: %d\n", vertices, edges);
    int currentAdjacency[3] = {-1, -1, 1};
    int currentPosition = 0;
    while (1) {
        char x = getchar();
        int isInTheEndOfAdjacency = (x == '\n');
        if (isInTheEndOfAdjacency) {
            printf("Current adjacency: (%d) --[%d]-- (%d)\n", currentAdjacency[0], currentAdjacency[1], currentAdjacency[2]);
            currentAdjacency[0] = -1;
            currentAdjacency[1] = -1;
            currentAdjacency[2] = 1;
            currentPosition = 0;
            continue;
        }
        if (x == ' ') continue;
        int xAsInt = atoi(&x);
        int isEOF = (x != '0' && xAsInt == 0);
        if (isEOF) {
            printf("Final adjacency: (%d) --[%d]-- (%d)\n", currentAdjacency[0], currentAdjacency[1], currentAdjacency[2]);
            currentAdjacency[0] = -1;
            currentAdjacency[1] = -1;
            currentAdjacency[2] = 1;
            currentPosition = 0;
            break;
        }
        currentAdjacency[currentPosition] = xAsInt;
        currentPosition++;
    }
    printf("\n");
}