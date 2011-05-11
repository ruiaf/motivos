#include "graph.h"

int main(void) {

	Graph *g = new Graph();
	g->generateRandom(10000, 200000);
	std::cout << *g;

	return 0;
}
