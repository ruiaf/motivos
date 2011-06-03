#include "Graph.h"
#include "MotifSampler.h"
#include "CountMinSketch.h"

int main(void) {
	Graph *g = new Graph();
	g->generateRandom(10000, 200000, 4);
	std::cerr << *g;

	Sketch *sketch = new Sketch(10,0.01,0.01);
	MotifSampler *s = new MotifSampler(g);

	for (int i=0; i<100000; i++) {
		Motif * m = s->sample(200);
		sketch->countMotif(*m);
		delete m;
		if (i%1000==0) {
			std::cout << i << ' ' << sketch->getTop() << '\n';
		}
	}

	return 0;
}
