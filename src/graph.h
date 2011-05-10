#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "defines.h"
#include <stdlib.h>

typedef struct edge_t {
	/* with u < v if graph is undirected */
	int id;

	node *u;
	node *v;
} edge;

typedef struct node_t {
	int id;

	/* number of incident edges */
	int m_edges;

	/* array of incident edges */
	edge **edges;
} node;

typedef struct graph_t {
	/* number of vertices */
	int n_nodes;

	/* number of edges */
	int m_edges;

	/* array of nodes */
	node **nodes;
	edge **edges;
} graph;

/* edge */
edge *edge_new();
void edge_set(edge *e, node *u, node *v);

/* node */
node *node_new();
void node_add_edge(node *u, edge *e);

/* graph */
graph *graph_new();
void graph_add_node(node *u);
void graph_add_edge(edge *e);

#endif
