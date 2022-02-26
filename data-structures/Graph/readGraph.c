void readGraph() {
    int vertices;
    int edges;
    scanf("%d %d", &vertices, &edges);
    getchar();
    printf("Vertices: %d; Edges: %d\n", vertices, edges);
    while (1) {
        char x = getchar();
        if (x == '\n') {
            printf("\n");
            continue;
        }
        if (x == ' ') continue;
        int xAsInt = atoi(&x);
        int isEOF = (x != '0' && xAsInt == 0);
        if (isEOF) break;
        printf("%d ", xAsInt);
    }
    printf("\n");
}