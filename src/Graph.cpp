#include "Graph.h"

void Graph::importSIF(const char *filepath) {

	std::cerr << "Opening SIF FILE: \"" << filepath << "\"...";

	std::ifstream sif_file(filepath);

	if (sif_file.is_open()) {
		std::cerr << "\tDone\n";

		std::cerr << "Reading File...";

		std::string line;
		while ( sif_file.good() ) {
			getline (sif_file,line);

			std::istringstream iss(line, std::istringstream::in);
			std::string node_A, edge_type, node_B;

			iss >> node_A;
			iss >> edge_type; // ignored for the moment
			iss >> node_B;

			/* Set node names and ids. Add vertices if they do not
			 * exist */

			Vertex *v_a,*v_b;

			// v_a

			if (this->vertex_name_dict.count(node_A)==0) {

				// create and set new vertex
				v_a = new Vertex();
				v_a->label = 0; // no label used for the moment
				v_a->id = this->vertices.size();
				this->vertices.push_back(v_a);

				// set the name
				this->vertex_name_dict[node_A] = v_a->id;
			} else {

				// load existing vertex
				v_a = this->vertices[this->vertex_name_dict[node_A]];
			}

			// v_b

			if (this->vertex_name_dict.count(node_B)==0) {

				// create and set new vertex
				v_b = new Vertex();
				v_b->label = 0; // no label used for the moment
				v_b->id = this->vertices.size();
				this->vertices.push_back(v_b);

				// set the name
				this->vertex_name_dict[node_B] = v_b->id;
			} else {

				// load existing vertex
				v_b = this->vertices[this->vertex_name_dict[node_B]];
			}

			/* Add the edge between a and b */

			Edge * e = new Edge();
			e->id = this->edges.size();
			e->u = v_a;
			e->v = v_b;

			v_a->edges.push_back(e);
			v_b->edges.push_back(e);
			this->edges.push_back(e);
		}

		sif_file.close();

		std::cerr << "\tDone\n";
	} else {
		std::cerr << "\tUnable to open file\n";
	}

	std::cerr << *this;
}


/* Generate a erdos-renyi graph */
void Graph::generateRandom(int n, int m, int n_labels) {

	for (int i=0; i<n; i++) {
		Vertex *v = new Vertex();
		v->label = rand()%n_labels;
		v->id = this->vertices.size();
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

std::ostream &operator<<( std::ostream &out, const Edge &e ) {
	out << "(id:" << e.id << ' ' << e.u->id << ' ' << e.v->id << ")\n";
	return out;
}

std::ostream &operator<<( std::ostream &out, const Vertex &u ) {
	out << "(id: " << u.id << " ";
	out << "label: " << u.label << " ";
	out << "|E|: " << u.edges.size() << ")\n";
	return out;
}

std::ostream &operator<<( std::ostream &out, const Graph &g ) {
	out << "Graph (|V|=" << g.vertices.size() << ", ";
	out << "|E|=" << g.edges.size() << ")\n";

	return out;
}
