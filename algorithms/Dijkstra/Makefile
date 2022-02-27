main: main.o dijkstra.o graph.o
	gcc -o dijkstra.out main.o dijkstra.o graph.o

graph.o: ../../data-structures/Graph/graph.c ../../data-structures/Graph/graph.h
	gcc -c ../../data-structures/Graph/graph.c

dijkstra.o: dijkstra.c dijkstra.h ../../data-structures/Graph/graph.h
	gcc -c dijkstra.c

main.o: main.c dijkstra.h
	gcc -c main.c

clean:
	rm *.o *.out