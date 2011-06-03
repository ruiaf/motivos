#include "Motif.h"

Motif::Motif() {
	n_incident_edges=0;
}

void Motif::add(Edge *e) {
	bool is_new_e = false;
	
	if (this->node_ids.find(e->u->id) == this->node_ids.end()){
		this->node_ids.insert(e->u->id);
		this->nodes.push_back(e->u);
		n_incident_edges += e->u->edges.size();
		if (label_count.find(e->u->label) == label_count.end()) {
			label_count[e->u->label]=0;
		}
		label_count[e->u->label]+=1;
		is_new_e = true;
	} 

	if (this->node_ids.find(e->v->id) == this->node_ids.end()){
		this->node_ids.insert(e->v->id);
		this->nodes.push_back(e->v);
		n_incident_edges += e->v->edges.size();
		if (label_count.find(e->v->label) == label_count.end()) {
			label_count[e->v->label]=0;
		}
		label_count[e->v->label]+=1;
		is_new_e = true;
	} 

	if (is_new_e) {
		this->edges.push_back(e);
	}
}

bool Motif::operator<(const Motif &other) const {
	return label_count < other.label_count;
}
