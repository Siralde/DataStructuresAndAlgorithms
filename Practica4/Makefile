all: merge

VElement.o: VElement.h VElement.cpp
	g++ -c VElement.cpp -Wall
	
merge.o: merge.cpp VElement.h
	g++ -c merge.cpp -Wall

merge: merge.o VElement.o
	g++ merge.o VElement.o -o merge
	
clean:
	rm *.o
	rm merge
