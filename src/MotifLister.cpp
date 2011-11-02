#include "MotifLister.h"

MotifLister::MotifLister(Graph *g, unsigned motif_size, float percent) {
	this->g = g;
	this->motif_size = motif_size;
	this->percent = percent;
}


Motif * MotifLister::next() {
	Motif *m = new Motif();



	return m;
}
