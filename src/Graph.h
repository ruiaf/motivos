#ifndef _GRAPH_H_
#define _GRAPH_H_

class Vertex;
class Edge;
class Graph;

#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include "MotifSampler.h"

class Edge {
	public:
		int id;
		Vertex *u;
		Vertex *v;
};

std::ostream &operator<<( std::ostream &out, const Edge &e );

class Vertex {
	public:
		int id;
		int label;
		std::vector<Edge *> edges;
};

std::ostream &operator<<( std::ostream &out, const Edge &e );

class Graph {
	public:
		void generateRandom(int n, int m, int n_labels);
        void importSIF(const char *filepath);

		std::vector<Vertex *> vertices;
		std::vector<Edge *> edges;

        std::map<std::string,int> vertex_name_dict;
};

std::ostream &operator<<( std::ostream &out, const Graph &g );
#endif
