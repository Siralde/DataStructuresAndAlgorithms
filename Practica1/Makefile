all: complejoMain

complejo.o: complejo.h complejo.cpp
	g++ -c complejo.cpp -Wall

complejoMain.o: complejoMain.cpp complejo.h
	g++ -c complejoMain.cpp -Wall

complejoMain: complejoMain.o complejo.o
	g++ complejoMain.o complejo.o -o complejoMain

clean:
	rm *.o
	rm complejoMain
