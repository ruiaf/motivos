#ifndef _MOTIF_H_
#define _MOTIF_H_

class Motif;

#include <set>
#include <vector>
#include <map>
#include "Graph.h"

class Motif {
	public:
		Motif();
		void add(Edge *e);
		unsigned hash(int seed, int maxval);
		bool operator<(const Motif &other) const;

		std::map<int,int> label_count;
		std::set<int> node_ids;
		std::vector<Vertex *> nodes;
		std::vector<Edge *> edges;
		int n_incident_edges;
};

#endif
