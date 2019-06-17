all: test_tabla costes

abb.o: abb.h abb.cpp
	g++ -c abb.cpp -Wall -O2
	
tabal.o: tabal.h tabla.cpp
	g++ -c tabal.cpp -Wall -O2

alumno.o: alumno.h alumno.cpp
	g++ -c alumno.cpp -Wall -O2
	
test_tabla.o: test_tabla.cpp alumno.h abb.h tabla.h
	g++ -c test_tabla.cpp -Wall -O2

test_tabla: test_tabla.o alumno.o abb.o tabla.o
	g++ test_tabla.o alumno.o abb.o tabla.o -o test_tabla -O2
	
costes.o: costes.cpp alumno.h abb.h tabla.h
	g++ -c costes.cpp -Wall -O2
	
costes: costes.o alumno.o abb.o tabla.o
	g++ costes.o alumno.o abb.o tabla.o -o costes -O2
	
clean:
	rm *.o
	rm test_tabla
	rm costes
