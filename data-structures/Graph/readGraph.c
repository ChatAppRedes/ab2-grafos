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
        if (x == 'e') break;
        printf("%d ", atoi(&x));
    }
    printf("\n");
}