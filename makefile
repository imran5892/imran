HEADERS = header.h

default: graph

main.o: main.cpp $(HEADERS)
	g++ -c main.cpp -o main.o

graph.o: graph.cpp $(HEADERS)
	g++ -c graph.cpp -o graph.o

graph: graph.o main.o
	g++ graph.o main.o -o graph

clean:
	-rm -f graph.o
	-rm -f main.o
	-rm -f graph
