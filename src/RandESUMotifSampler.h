#ifndef _RESU_MOTIFSAMPLER_H_
#define _RESU_MOTIFSAMPLER_H_

class RandESUMotifSampler;

#include "Graph.h"
#include "ConnectedVertexSetMotif.h"
#include "MotifSampler.h"
#include <vector>
#include <unordered_set>

class RandESUMotifSampler: public MotifSampler {
	public:
		RandESUMotifSampler(Graph *g, unsigned k, float p);
		ConnectedVertexSetMotif* next();
		void outputAllSubgraphs(); 
		void outputSubgraphs(std::vector<Vertex *> &v_subgraph,
			std::vector<Vertex *> &v_extension,
			std::unordered_set<Vertex *> &v_subgraph_neighbourhood,
	       		Vertex *v);
		std::unordered_set<Vertex *> calculateNeighbourhood(std::vector<Vertex *> v_subgraph);

	private:
		Graph *g;
		unsigned k;
		float p;

		/* benchmark */
		clock_t time_init;
		clock_t time_end;
		int n_motifs_output;

};

#endif
