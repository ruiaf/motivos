#include "RandESUMotifSampler.h"

RandESUMotifSampler::RandESUMotifSampler(Graph *g, unsigned k, float p) {
	this->g = g;
	this->k = k;
	this->p = p;

	srand(clock());

	/* benchmark time */
	this->time_init = clock();
	this->time_end = clock();
	this->n_motifs_output = 0;
}

void RandESUMotifSampler::outputAllSubgraphs() {

	/* init clock */
	this->time_init = clock();

	for (unsigned i=0; i<g->vertices.size(); i++) {
		std::vector<Vertex *> v_subgraph;
		std::vector<Vertex *> v_extension;
		std::set<Vertex *> v_subgraph_neighbourhood;
		Vertex *v;

		v = g->vertices[i];
		v_subgraph.push_back(v);

		for (unsigned j=0; j<v->edges.size(); j++) {
			Vertex *u;

			u = v->edges[j]->u;
			if ( u == v ) {
				u = v->edges[j]->v;
			}

			if ( u->id > v->id) {
				v_extension.push_back(u);
			}	
		}

		v_subgraph_neighbourhood = calculateNeighbourhood(v_subgraph); 

		outputSubgraphs(v_subgraph,v_extension,v_subgraph_neighbourhood,v);
	}
}

void RandESUMotifSampler::outputSubgraphs(std::vector<Vertex *> &v_subgraph,
		std::vector<Vertex *> &v_extension,
		std::set<Vertex *> &v_subgraph_neighbourhood,
	       	Vertex *v)
{

	if (v_subgraph.size()==k) {
		
		std::cout << "size: " << v_subgraph.size() << " vertices:";
		for (unsigned i=0; i< v_subgraph.size(); i++) {
			std::cout << ' ' << v_subgraph[i]->id;
		}
		std::cout << '\n';
		

		n_motifs_output++;

		if (n_motifs_output%((int)(10000000/(k*p))) == 0) {
			time_end = clock();

			std::cerr << "stats: " << (time_end - time_init)/CLOCKS_PER_SEC << " seconds "
				<< "\t#motifs: " << n_motifs_output
				<< "  \tmotifs/sec: " << ((float)n_motifs_output/(time_end - time_init))*CLOCKS_PER_SEC << "\n";
		}
		
		return;
	}

	while (v_extension.size() > 0) {
		std::vector<Vertex *> v_subgraph_neighbourhood_undo_list;
		std::vector<Vertex *> new_v_extension;

		Vertex *w;

		w = v_extension.back();
		v_extension.pop_back();

		if (((float) rand() / (RAND_MAX/2 + 1)) > p )
			continue;

		new_v_extension = v_extension;
		v_subgraph.push_back(w);

		for (unsigned j=0; j<w->edges.size(); j++) {
			Vertex *u;

			u = w->edges[j]->u;
			if ( u == w ) {
				u = w->edges[j]->v;
			}
			
			if ( u->id > w->id &&
				v_subgraph_neighbourhood.find(u)==v_subgraph_neighbourhood.end())
		       	{
					v_subgraph_neighbourhood.insert(u);
					new_v_extension.push_back(u);

					v_subgraph_neighbourhood_undo_list.push_back(u);
			}
		}
		
		outputSubgraphs(v_subgraph,new_v_extension,v_subgraph_neighbourhood,v);

		/* undo modifications done to the structures */

		v_subgraph.pop_back();

		while (v_subgraph_neighbourhood_undo_list.size()>0) {
			Vertex *u;
			u = v_subgraph_neighbourhood_undo_list.back();
			v_subgraph_neighbourhood_undo_list.pop_back();
			v_subgraph_neighbourhood.erase(u);
		}
	}
}

std::set<Vertex *> RandESUMotifSampler::calculateNeighbourhood(std::vector<Vertex *> v_subgraph) {

		std::set<Vertex *> v_subgraph_neighbourhood;
		Vertex *v;

		for (unsigned i=0; i<v_subgraph.size(); i++) {
			v = g->vertices[i];
			v_subgraph_neighbourhood.insert(v);

			for (unsigned j=0; j<v->edges.size(); j++) {
				Vertex *u;

				u = v->edges[j]->u;
				if ( u == v ) {
					u = v->edges[j]->v;
				}

				v_subgraph_neighbourhood.insert(u);
			}
		}

		return v_subgraph_neighbourhood;
}

ConnectedVertexSetMotif* RandESUMotifSampler::next() {
	ConnectedVertexSetMotif *m = new ConnectedVertexSetMotif();

	Edge *e = g->edges[rand() % g->edges.size()];
	m->add(e);

	return m;
}
