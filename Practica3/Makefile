all: prueba rec

pila.o: pila.h pila.cpp
	g++ -c pila.cpp -Wall
	
prueba.o: prueba.cpp pila.h error.h
	g++ -c prueba.cpp -Wall

prueba: prueba.o pila.o
	g++ prueba.o pila.o -o prueba
	
rec.o: rec.cpp pila.h error.h
	g++ -c rec.cpp -Wall
	
rec: rec.o pila.o
	g++ rec.o pila.o -o rec
	
clean:
	rm *.o
	rm prueba
	rm rec
