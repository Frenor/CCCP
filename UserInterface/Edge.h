#include "Node.h"

#ifndef EDGE_OBJECT
#define EDGE_OBJECT

//!	A data object holding edge data
class Edge
{
public:
	Node *n1;	//!< Node 1 in edge
	Node *n2;	//!< Node 2 in edge

	double width1, width2; //!< Edge width at node 1

	Edge(Node*, Node*);
	
	~Edge();

	void setWidth(double, double);
};

#endif