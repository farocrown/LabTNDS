LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compila: main.x graph.x

eseguimain:
	./main.x > log.log2 > err.log
	
eseguigraph:
	./graph.x > log.log2 > err.log

clean:
	rm -f *.x *.dat

main.x: main.cpp RandomGen.h funzionebase.h integrale.h
	g++ -o main.x main.cpp ${INCS} ${LIBS}
	
graph.x: main2.cpp RandomGen.h funzionebase.h integrale.h
	g++ -o graph.x main2.cpp ${INCS} ${LIBS}
