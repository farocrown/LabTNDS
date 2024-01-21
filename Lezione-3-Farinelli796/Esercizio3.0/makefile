compila: main.x

esegui:
	./main.x 100000 data.dat ordered.txt

clean:
	rm -f *.o *.x *.txt

main.x: main.cpp lib1.h vector.h
	g++ -o main.x main.cpp
