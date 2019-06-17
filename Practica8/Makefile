all: voraz costes backtracking

grafo.o: grafo.h grafo.cpp
	g++ -c grafo.cpp -Wall -O2
	
voraz.o: voraz.cpp grafo.h
	g++ -c voraz.cpp -Wall -O2

voraz: voraz.o grafo.o
	g++ voraz.o grafo.o -o voraz -O2
	
costes.o: costes.cpp grafo.h
	g++ -c costes.cpp -Wall -O2

costes: costes.o grafo.o
	g++ costes.o grafo.o -o costes -O2
	
backtracking.o: backtracking.cpp grafo.h
	g++ -c backtracking.cpp -Wall -O2

backtracking: backtracking.o grafo.o
	g++ backtracking.o grafo.o -o backtracking -O2
	
clean:
	rm *.o
	rm voraz
	rm costes
	rm backtracking
