#ifndef _MOTIFLISTER_H_
#define _MOTIFLISTER_H_

#include <iostream>
#include <set>
#include <vector>
#include "Graph.h"
#include "Motif.h"

class MotifLister {
	public:
		MotifLister(Graph *g, unsigned motif_size, float percent);
		Motif *next();
	private:
		Graph *g;
		unsigned motif_size;
		float percent;
};

#endif
