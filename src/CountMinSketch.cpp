#include "CountMinSketch.h"

Sketch::Sketch(int n_top_items) {
	k = n_top_items;
	min_threshold = 0;
}

int Sketch::countMotif(Motif &m, int weight) {
	if (counters.find(m) == counters.end()) {
		counters[m]=0;
	}
	counters[m]+=weight;

	if (counters[m] > min_threshold) {
		top_k.push_back(std::pair<int,Motif>(int(counters[m]),Motif(m)));
		top_k.sort();
		if (top_k.size()>k) {
			top_k.pop_front();
		}
		min_threshold = top_k.front().first;
	}

	return counters[m];
}

int Sketch::getTop() {
	return top_k.back().first;
}

/*
std::vector<Motif> getTopK() {
	return top_k;
}
*/
