#include "Graph.h"
#include "Motif.h"
#include "MotifSampler.h"
#include "RandESUMotifSampler.h"
#include "CountMinSketch.h"

int main(void) {
	Graph *g = new Graph();
	g->importSIF("../datasets/SC_Torque.sif");

	//Sketch *sketch = new Sketch(0.01,0.01);

	int k = 100;
	float p=0.05;

	RandESUMotifSampler *s;

    s = new RandESUMotifSampler(g,k,p);
	s->outputAllSubgraphs();

	return 0;
}
