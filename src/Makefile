CFLAGS= -O4 -ansi -Wall -g -std=c++0x

all:
	g++ $(CFLAGS) -c Graph.cpp
	g++ $(CFLAGS) -c Motif.cpp
	g++ $(CFLAGS) -c ConnectedVertexSetMotif.cpp
	g++ $(CFLAGS) -c RandESUMotifSampler.cpp
	g++ $(CFLAGS) -c CountMinSketch.cpp
	g++ $(CFLAGS) -c motivos.cpp
	g++ $(CFLAGS) -o motivos Graph.o Motif.o ConnectedVertexSetMotif.o RandESUMotifSampler.o CountMinSketch.o motivos.o
clean:
	rm *.o
