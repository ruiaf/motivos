#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "defines.h"
#include <vector>
#include <iostream>

class Vertex;
class Edge;
class Graph;

class Edge {
	public:
		Edge();

	private:
		int id;
		Vertex *u;
		Vertex *v;

		friend class Graph;
};

class Vertex {
	public:
		Vertex();

	private:
		int id;
		std::vector<Edge *> edges;

		friend class Graph;
};

class Graph {
	public:
		Graph();
		void generateRandom(int n, int m);

	private:
		std::vector<Vertex *> vertices;
		std::vector<Edge *> edges;

		friend std::ostream &operator<<( std::ostream &out, const Graph &g );
};
#endif
