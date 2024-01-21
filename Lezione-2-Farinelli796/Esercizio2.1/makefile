main.x: main.o lib1.o vector.o
	g++ -o main.x main.o lib1.o vector.o

lib1.o: lib1.cpp lib1.h
	g++ -c lib1.cpp

vector.o: vector.cpp vector.h
	g++ -c vector.cpp

compila: main.x

esegui:
	./main.x 100000 data.dat ordered.txt

clean:
	rm -f *.o *.x

main.o: main.cpp lib1.h
	g++ -c main.cpp

