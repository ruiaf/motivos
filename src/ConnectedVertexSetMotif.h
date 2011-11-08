#ifndef _CVS_MOTIF_H_
#define _CVS_MOTIF_H_

class ConnectedVertexSetMotif;

#include <set>
#include <vector>
#include <map>
#include <iostream>
#include "Graph.h"
#include "Motif.h"

class ConnectedVertexSetMotif: public Motif {
	public:
		ConnectedVertexSetMotif();
		ConnectedVertexSetMotif * clone();
		void add(Edge *e);
		unsigned hash(int seed, int maxval);
		bool operator<(const ConnectedVertexSetMotif &other) const;


		std::map<int,int> label_count;
		std::set<int> node_ids;
		std::vector<Vertex *> nodes;
		std::vector<Edge *> edges;
		int n_incident_edges;

	private:
		void print( std::ostream &out ) const;
};

#endif
