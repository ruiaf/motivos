#include "graph.h"

/* edge */
edge *edge_new() {
	edge *e = (edge*) malloc(sizeof(edge));
	e->id = -1;
	e->u = NULL;
	e->v = NULL;
	return e;
}

void edge_set_nodes(edge *e, node *u, node *v) {
	
}

/* node */
node *node_new() {
	node *u = (node*) malloc(sizeof(node));
	u->id = -1;
	u->m_edges = 0;
	u->edges = (edge**) malloc(sizeof(edge*)*MAX_NUMBER_EDGES_GRAPH);
	return u;
}

void node_add_edge(node *u, edge *e) {

}

/* graph */
graph *graph_new() {
	graph *g = (graph*) malloc(sizeof(graph));
	g->nodes = (node**) malloc(sizeof(node*)*MAX_NUMBER_NODES_GRAPH);
	g->edges = (edge**) malloc(sizeof(edge*)*MAX_NUMBER_EDGES_GRAPH);
	return g;
}

void graph_add_node(node *u) {
}

void graph_add_edge(edge *e) {
}
