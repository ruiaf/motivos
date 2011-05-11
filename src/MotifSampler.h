#ifndef _MOTIFSAMPLER_H_
#define _MOTIFSAMPLER_H_

class MotifSampler;

#include <iostream>
#include <set>
#include "Graph.h"

class MotifSampler {
	public:
		MotifSampler(Graph *g);
		void sample(unsigned motif_size);

	private:
		Graph *g;
};

#endif
