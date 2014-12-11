#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

//!	A data object holding edge data
class Edge
{
public:
	Node *n1;	//!< Node 1 in edge
	Node *n2;	//!< Node 2 in edge

	double width1;	//!< Edge width at Node 1
	double width2;	//!< Edge width at Node 1

	Edge(Node*, Node*);
	Edge(const Edge &);
	~Edge();

	Edge* clone() const;

	void setWidth(double, double);
};

#endif //EDGE_H