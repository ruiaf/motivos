#ifndef _MOTIFSAMPLER_H_
#define _MOTIFSAMPLER_H_

class MotifSampler;

#include "Graph.h"
#include "Motif.h"

class MotifSampler {
	public:
		virtual Motif* next() = 0;
};

#endif
