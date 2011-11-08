#include "CountMinSketch.h"

Sketch::Sketch(float epsilon, float delta) {
	// init sketch 
	epsilon = epsilon;
	delta = delta;

	d= ceil(log(1.0/delta));
	w= ceil(M_E/epsilon);

	std::cerr << "Creating Sketch (height=" << w << ", width=" << d << ")... ";
	counter_seeds = (unsigned *) malloc(d*sizeof(unsigned));
	for (int i=0; i<d; i++) {
		counter_seeds[i] = random();
	}

	counter = (unsigned **) malloc(d*sizeof(unsigned*));
	for (int i=0; i<d; i++) {
		counter[i] = (unsigned *) malloc(w*sizeof(unsigned));
		memset(counter[i],0,w*sizeof(unsigned));
	}
	std::cerr << "Done\n";
}

float Sketch::countMotif(Motif &m, int weight) {
	unsigned min = UINT_MAX;
	unsigned hash;
	for (int i=0; i<d; i++) {
		hash = m.hash(counter_seeds[i],w);
		counter[i][hash]+=weight;
		if (min > counter[i][hash]) {
			min = counter[i][hash];
		}
	}

	return min;
}
