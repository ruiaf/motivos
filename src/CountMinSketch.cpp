#include "CountMinSketch.h"

Sketch::Sketch(int n_top_items, float epsilon, float delta) {
	k = n_top_items;
	exact_min_threshold = 0;

	// init sketch 
	this->epsilon = epsilon;
	this->delta = delta;

	d= ceil(log(1.0/delta))*10;
	w= ceil(M_E/epsilon)*10;

	std::cerr << "Creating Sketch (height=" << w << ", width=" << d << ")... ";
	counter_seeds = (int *) malloc(d*sizeof(int));
	for (int i=0; i<d; i++) {
		counter_seeds[i] = random();
	}

	counter = (int **) malloc(d*sizeof(int*));
	for (int i=0; i<d; i++) {
		counter[i] = (int *) malloc(w*sizeof(int));
		memset(counter[i],0,w*sizeof(int));
	}
	std::cerr << "Done\n";
}

void Sketch::countMotif(Motif &m, int weight) {
	countMotifApproximate(m,weight);
	countMotifExact(m,weight);
}

float Sketch::countMotifApproximate(Motif &m, int weight) {
	unsigned min = (unsigned)-1;
	unsigned hash;
	for (int i=0; i<d; i++) {
		hash = m.hash(counter_seeds[i],w);
		counter[i][hash]+=weight;
		if (min> counter[i][hash]) {
			min = counter[i][hash];
		}
	}

	return min;
}

int Sketch::countMotifExact(Motif &m, int weight) {
	if (exact_counter.find(m) == exact_counter.end()) {
		exact_counter[m]=0;
	}
	exact_counter[m]+=weight;

	if (exact_counter[m] > exact_min_threshold) {
		exact_top_k.push_back(std::pair<int,Motif>(int(exact_counter[m]),Motif(m)));
		exact_top_k.sort();
		if (exact_top_k.size()>k) {
			exact_top_k.pop_front();
		}
		exact_min_threshold = exact_top_k.front().first;
	}

	return exact_counter[m];
}

int Sketch::getTop() {
	std::cerr << "TOP (exact=" << exact_top_k.back().first << ", ";
	std::cerr << "approximate=" << countMotifApproximate(exact_top_k.back().second,0) << ")";
	return exact_top_k.back().first;
}

/*
std::vector<Motif> getTopK() {
	return top_k;
}
*/
