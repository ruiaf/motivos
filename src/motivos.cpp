#include "Graph.h"
#include "MotifSampler.h"

int main(void) {
	Graph *g = new Graph();
	g->generateRandom(10000, 200000, 5);
	std::cout << *g;

	MotifSampler *s = new MotifSampler(g);
	for (int i=0; i<100; i++) {
		s->sample(10);
	}


	return 0;
}
