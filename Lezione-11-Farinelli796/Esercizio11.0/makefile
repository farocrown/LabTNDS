LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compila: main.x

eseguimain:
	./main.x > log.log2 > err.log

clean:
	rm -f *.x *.dat

main.x: main.cpp RandomGen.h prisma.h RandomGen.h
	g++ -o main.x main.cpp ${INCS} ${LIBS}
	
