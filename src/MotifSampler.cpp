#include "MotifSampler.h"

MotifSampler::MotifSampler(Graph *g) {
	this->g = g;
}


Motif * MotifSampler::sample(unsigned motif_size) {
	Motif *m = new Motif();

	Edge *e = g->edges[rand() % g->edges.size()];
	m->add(e);

	while (m->nodes.size()<=motif_size) {
		unsigned counter = 0;
		unsigned index_i = rand()%(m->n_incident_edges);
		for (std::vector<Vertex *>::iterator i= m->nodes.begin();
				i != m->nodes.end(); i++) {
			if ((*i)->edges.size() > (index_i-counter)) {
				e = (*i)->edges[index_i-counter];
			}
			counter+=(*i)->edges.size();
		}
		
		m->add(e);
	}

	return m;
}
