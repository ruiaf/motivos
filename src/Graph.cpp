#include "Graph.h"

void Graph::importSIF(const char *filepath) {
    
    std::cerr << "Opening \"" << filepath << "\"...";

    std::ifstream sif_file(filepath);

    if (sif_file.is_open()) {
        std::cout << "\tDone\n";

        std::cout << "Reading File...";

        std::string line;
        while ( sif_file.good() ) {
            getline (sif_file,line);

            std::istringstream iss(line, std::istringstream::in);
            std::string node_A, edge_type, node_B;
            int node_A_id, node_B_id;

            iss >> node_A;
            iss >> edge_type;
            iss >> node_B;

            if (this->vertex_name_dict.count(iss)==0) {
                vertex_name_dict[node_A] = vertex_name_dict.size();
            }

            node_A_id = vertex_name_dict[node_A];

            if (this->vertex_name_dict.count(iss)==0) {
                vertex_name_dict[node_B] = vertex_name_dict.size();
            }

            node_B_id = vertex_name_dict[node_B];

            std::cout << node_A << node_B << "\n";
            
        }
        sif_file.close();

        std::cout << "\tDone\n";
    } else {
        std::cout << "\tUnable to open file\n";
    }

	std::cerr << *this;
}


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
