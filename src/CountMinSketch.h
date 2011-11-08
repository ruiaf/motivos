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
		Sketch(float epsilon,float delta);

		float countMotif(Motif &m, int weight=1);

	private:
		float epsilon;
		float delta;
		int w;
		int d;

		unsigned *counter_seeds;
		unsigned **counter;
};

#endif
