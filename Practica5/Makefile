all: test_arbol test_map

abb.o: abb.h abb.cpp
	g++ -c abb.cpp -Wall

alumno.o: alumno.h alumno.cpp
	g++ -c alumno.cpp -Wall
	
test_arbol.o: test_arbol.cpp alumno.h abb.h
	g++ -c test_arbol.cpp -Wall

test_arbol: test_arbol.o alumno.o abb.o
	g++ test_arbol.o alumno.o abb.o -o test_arbol
	
test_map.o: test_map.cpp alumno.h
	g++ -c test_map.cpp -Wall
	
test_map: test_map.o alumno.o
	g++ test_map.o alumno.o -o test_map
	
clean:
	rm *.o
	rm test_arbol
	rm test_map
