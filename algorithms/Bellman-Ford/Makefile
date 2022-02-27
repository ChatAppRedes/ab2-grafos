main: main.o ford.o graph.o
	gcc -o ford.out main.o ford.o graph.o

graph.o: ../../data-structures/Graph/graph.c ../../data-structures/Graph/graph.h
	gcc -c ../../data-structures/Graph/graph.c

ford.o: ford.c ford.h ../../data-structures/Graph/graph.h
	gcc -c ford.c

main.o: main.c ford.h
	gcc -c main.c

clean:
	rm *.o *.out