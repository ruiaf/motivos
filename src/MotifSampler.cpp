#include "MotifSampler.h"

MotifSampler::MotifSampler(Graph *g) {
	this->g = g;
}


void MotifSampler::sample(unsigned motif_size) {
	std::set<int> motif_nodes;

	Edge *e = g->edges[rand() % g->edges.size()];
	motif_nodes.insert(e->u->id);
	motif_nodes.insert(e->v->id);

	while (motif_nodes.size()<=motif_size) {
		e = g->edges[rand() % g->edges.size()];
		motif_nodes.insert(e->u->id);
		motif_nodes.insert(e->v->id);
	}

	for(std::set<int>::iterator i= motif_nodes.begin(); i != motif_nodes.end(); i++) {
		std::cout<< *g->vertices[*i] <<"\t";
	}
	std::cout<<"\n";
}
