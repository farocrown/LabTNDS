LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compila: compito

eseguimain:
	./main.x > log.log2 > err.log

clean:
	rm -f *.x *.dat

compito: main.cpp RandomGen.h integrale.h funzionebase.h bisezione.h solutore.h
	g++ -o compito main.cpp ${INCS} ${LIBS}
	
	
