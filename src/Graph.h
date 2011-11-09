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

class Edge {
	public:
        friend std::ostream &operator<<( std::ostream &out, const Edge &e ) {
			e.print(out);
			return out;
        }

		int id;
		Vertex *u;
		Vertex *v;

    private:
        void print( std::ostream &out ) const;
};


class Vertex {
	public:
        friend std::ostream &operator<<( std::ostream &out, const Vertex &v ) {
            v.print(out);
            return out;
        }
        
        int id;
		int label;
		std::vector<Edge *> edges;

    private:
        void print( std::ostream &out ) const;
};


class Graph {
	public:
		void generateRandom(int n, int m, int n_labels);
		void importSIF(const char *filepath);

        friend std::ostream &operator<<( std::ostream &out, const Graph &g ) {
            g.print(out);
            return out;
        }

		std::vector<Vertex *> vertices;
		std::vector<Edge *> edges;

		std::map<std::string,int> vertex_name_dict;
    private:
        void print( std::ostream &out ) const;
        void calculateStatistics();

        /* statistics */
        float average_degree;
        unsigned maximum_degree;
};

#endif
