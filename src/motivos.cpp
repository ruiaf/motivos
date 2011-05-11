#include "Graph.h"
#include "MotifSampler.h"

int main(void) {
	Graph *g = new Graph();
	g->generateRandom(10000, 200000, 5);
	std::cout << *g;

	MotifSampler *s = new MotifSampler(g);
	for (int i=0; i<100000; i++) {
		Motif * m = s->sample(200);
		delete m;
		if (i%1000==0)
			std::cout << i << '\n';
	}

	return 0;
}
