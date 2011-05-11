#ifndef _MOTIFSAMPLER_H_
#define _MOTIFSAMPLER_H_

class MotifSampler;

#include <iostream>
#include <set>
#include <vector>
#include "Graph.h"
#include "Motif.h"

class MotifSampler {
	public:
		MotifSampler(Graph *g);
		Motif* sample(unsigned motif_size);

	private:
		Graph *g;
};

#endif
