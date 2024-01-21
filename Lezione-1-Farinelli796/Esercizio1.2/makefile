lib1.o: lib1.cpp lib1.h
	g++ -c lib1.cpp

compila: es1-2.x 

esegui:
	./es1-2.x 100000 data.dat ordered.txt

clean:
	rm -f *.o



es1-2.o: es1-2.cpp lib1.h
	g++ -c es1-2.cpp

es1-2.x: es1-2.o lib1.o
	g++ -o es1-2.x es1-2.o lib1.o 
	