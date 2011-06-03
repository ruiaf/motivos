CFLAGS= -O4 -ansi -Wall -g

all:
	g++ $(CFLAGS) -c Graph.cpp
	g++ $(CFLAGS) -c Motif.cpp
	g++ $(CFLAGS) -c MotifSampler.cpp
	g++ $(CFLAGS) -c CountMinSketch.cpp
	g++ $(CFLAGS) -c motivos.cpp
	g++ $(CFLAGS) -o motivos Graph.o Motif.o MotifSampler.o CountMinSketch.o motivos.o
clean:
	rm *.o
