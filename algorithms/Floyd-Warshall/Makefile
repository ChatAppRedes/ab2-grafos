main: main.o floyd.o graph.o
	gcc -o floyd.out main.o floyd.o graph.o

graph.o: ../../data-structures/MatrixAdjacencyGraph/graph.c ../../data-structures/MatrixAdjacencyGraph/graph.h
	gcc -c ../../data-structures/MatrixAdjacencyGraph/graph.c

floyd.o: floyd.c floyd.h ../../data-structures/MatrixAdjacencyGraph/graph.h
	gcc -c floyd.c

main.o: main.c floyd.h
	gcc -c main.c

clean:
	rm *.o *.out