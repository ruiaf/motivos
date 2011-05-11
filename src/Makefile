CFLAGS= -O4 -ansi -Wall

all:
	g++ $(CFLAGS) -c graph.cpp
	g++ $(CFLAGS) -c motivos.cpp
	g++ $(CFLAGS) -o motivos graph.o motivos.o
clean:
	rm *.o
