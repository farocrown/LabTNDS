LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compila: main.x

esegui:
	./main.x 1 1 1

clean:
	rm -f *.x 

main.x: main.cpp particella.h posizione.h campovettoriale.h puntomateriale.h
	g++ -o main.x main.cpp ${INCS} ${LIBS}
