#include "graph.h"

Edge::Edge() {
}

Vertex::Vertex() {
}

/***
 * Graph Methods
 */

Graph::Graph() {
}

void Graph::generateRandom(int n, int m) {

	for (int i=0; i<n; i++) {
		Vertex *v = new Vertex();
		v->id = this->edges.size();
		this->vertices.push_back(v);
	}

	for (unsigned i=1; i< this->vertices.size(); i++) {
		for (unsigned j=1; j< this->vertices.size(); j++) {
			if ((rand()%n) < (m/n)) {
				Edge * e = new Edge();
				e->id = this->edges.size();
				e->u = this->vertices[i];
				e->v = this->vertices[j];

				this->vertices[i]->edges.push_back(e);
				this->vertices[j]->edges.push_back(e);
				this->edges.push_back(e);
			}
		}
	}
}

std::ostream &operator<<( std::ostream &out, const Graph &g ) {
	out << "|V| = " << g.vertices.size() << '\n';
	out << "|E| = " << g.edges.size() << '\n';

	return out;
}
