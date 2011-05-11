#ifndef _GRAPH_H_
#define _GRAPH_H_

class Vertex;
class Edge;
class Graph;

#include <vector>
#include <iostream>
#include "MotifSampler.h"

class Edge {
	public:

	private:
		int id;
		Vertex *u;
		Vertex *v;

		friend std::ostream &operator<<( std::ostream &out, const Edge &e );
		friend class Graph;
		friend class MotifSampler;
};

class Vertex {
	public:

	private:
		int id;
		int label;
		std::vector<Edge *> edges;

		friend std::ostream &operator<<( std::ostream &out, const Vertex &u );
		friend std::ostream &operator<<( std::ostream &out, const Edge &e );
		friend class Graph;
		friend class MotifSampler;
};

class Graph {
	public:
		void generateRandom(int n, int m, int n_labels);

	private:
		std::vector<Vertex *> vertices;
		std::vector<Edge *> edges;

		friend std::ostream &operator<<( std::ostream &out, const Graph &g );
		friend class MotifSampler;
};
#endif
