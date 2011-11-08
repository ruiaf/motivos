#ifndef _MOTIF_H_
#define _MOTIF_H_

#include "Graph.h"

class Motif {
	public:
		virtual Motif * clone() = 0;
		virtual void add(Edge *e) = 0;
		virtual unsigned hash(int seed, int maxval) = 0;


		friend std::ostream &operator<<( std::ostream &out, const Motif &m ) {
			m.print(out);
			return out;
		}
	private:
		
		virtual void print( std::ostream &out ) const = 0;
};

#endif
