LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compila: main.x

esegui:
	./main.x 1 2 0.0001

clean:
	rm -f *.x

main.x: main.cpp bisezione.h funzionebase.h solutore.h
	g++ -o main.x main.cpp -std=c++11 ${INCS} ${LIBS}
