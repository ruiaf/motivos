#include "Graph.h"
#include "MotifSampler.h"
#include "MotifLister.h"
#include "CountMinSketch.h"

int main(void) {
	Graph *g = new Graph();
	g->importSIF("../datasets/DM_Torque.sif");

	Sketch *sketch = new Sketch(10,0.01,0.01);
	MotifLister *s = new MotifLister(g,200,0.1);

	for (int i=0; i<100000; i++) {
		Motif * m = s->next();
		sketch->countMotif(*m);
		delete m;
		if (i%1000==0) {
			std::cout << i << ' ' << sketch->getTop() << '\n';
		}
	}

	return 0;
}
