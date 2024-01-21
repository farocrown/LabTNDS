lib1.o: lib1.cpp lib1.h
	g++ -c lib1.cpp

compila: es1-3.x

esegui:
	./es1-3.x 99 data.dat ordered.txt

clean:
	rm -f *.o



es1-3.o: es1-3.cpp lib1.h
	g++ -c es1-3.cpp

es1-3.x: es1-3.o lib1.o
	g++ -o es1-3.x es1-3.o lib1.o 
	