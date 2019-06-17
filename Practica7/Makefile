all: test_dijkstra costes bomberos

grafo.o: grafo.h grafo.cpp
	g++ -c grafo.cpp -Wall -O2
	
test_dijkstra.o: test_dijkstra.cpp grafo.h
	g++ -c test_dijkstra.cpp -Wall -O2

test_dijkstra: test_dijkstra.o grafo.o
	g++ test_dijkstra.o grafo.o -o test_dijkstra -O2
	
costes.o: costes.cpp grafo.h
	g++ -c costes.cpp -Wall -O2
	
costes: costes.o grafo.o
	g++ costes.o grafo.o -o costes -O2
	
bomberos.o: bomberos.cpp grafo.h
	g++ -c bomberos.cpp -Wall -O2
	
bomberos: bomberos.o grafo.o
	g++ bomberos.o grafo.o -o bomberos -O2
	

clean:
	rm *.o
	rm test_dijkstra
	rm costes
	rm bomberos
