/*
 *	For the time being this is just a dictionary and not
 *	a count-min sketch implementation
 */

#ifndef _SKETCH_H_
#define _SKETCH_H_

class Sketch;

#include "Motif.h"
#include <vector>
#include <list>
#include <map>
#include <utility>

class Sketch {
	public:
		Sketch(int n_top_items);
		int countMotif(Motif &m, int weight=1);
		std::vector<Motif> getTopK();
		int getTop();

	private:
		std::list< std::pair<int,Motif> > top_k;
		int min_threshold;
		std::map<Motif,int> counters;
		unsigned k;
};

#endif
