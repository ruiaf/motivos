#include "ConnectedVertexSetMotif.h"

ConnectedVertexSetMotif::ConnectedVertexSetMotif() {
	n_incident_edges=0;
}

ConnectedVertexSetMotif * ConnectedVertexSetMotif::clone() {
	return new ConnectedVertexSetMotif(*this);
}

void ConnectedVertexSetMotif::add(Edge *e) {
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
		//std::cout << "added_edge" << *e;
	}
}

bool ConnectedVertexSetMotif::operator<(const ConnectedVertexSetMotif &other) const {
	return label_count < other.label_count;
}

void ConnectedVertexSetMotif::print( std::ostream &out ) const {
	out << nodes.size() << " " << edges.size();
}

unsigned ConnectedVertexSetMotif::hash(int seed, int maxval) {
	unsigned key = seed;
	//TODO: extend this for an unlimited number of labels

	for (int i=0; i< 10; i++) {
		key ^= ((i+101)*1000+label_count[i]);
		key = (~key) + (key << 21); // key = (key << 21) - key - 1;
		key = key ^ (key >> 24);
		key = (key + (key << 3)) + (key << 8); // key * 265
		key = key ^ (key >> 14);
		key = (key + (key << 2)) + (key << 4); // key * 21
		key = key ^ (key >> 28);
		key = key + (key << 31);
	}

	return key%maxval;
}
