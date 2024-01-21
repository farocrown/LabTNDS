LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compila: main.x

esegui:
	./main.x 100

clean:
	rm main

main.x: main.cpp integrale.h funzionebase.h
	g++ -o main.x main.cpp -std=C++11 ${INCS} ${LIBS}

