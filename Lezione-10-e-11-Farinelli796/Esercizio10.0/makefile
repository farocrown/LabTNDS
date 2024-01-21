LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compila: main.x

esegui:
	./main.x > log.log2 > err.log

clean:
	rm -f *.x

main.x: main.cpp RandomGen.h gaussiana.h
	g++ -o main.x main.cpp ${INCS} ${LIBS}
