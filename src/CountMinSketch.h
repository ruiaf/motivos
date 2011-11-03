/*
 *	For the time being this is just a dictionary and not
 *	a count-min sketch implementation
 */

#ifndef _SKETCH_H_
#define _SKETCH_H_

class Sketch;

#include "Motif.h"
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include <map>
#include <utility>
#include <climits>

class Sketch {
	public:
		Sketch(int n_top_items,float epsilon,float delta);
		std::vector<Motif> getTopK();
		int getTop();

		void countMotif(Motif &m, int weight=1);
		float countMotifApproximate(Motif &m, int weight=1);
		int countMotifExact(Motif &m, int weight=1);

	private:
		unsigned k;

		// exact counting, just for debug
		std::list< std::pair<int,Motif> > exact_top_k;
		std::map<Motif,int> exact_counter;
		int exact_min_threshold;

		// approximate_counting
		float epsilon;
		float delta;
		int w;
		int d;

		unsigned *counter_seeds;
		unsigned **counter;
};

#endif
