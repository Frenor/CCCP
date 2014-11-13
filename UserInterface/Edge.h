#ifndef EDGE_H
#define EDGE_H

//!	A data object holding edge data
class Edge
{
public:
	Node *n1;	//!< Node 1 in edge
	Node *n2;	//!< Node 2 in edge

	Edge(Node* node1, Node *node2)
	{
		this->n1 = node1;
		this->n2 = node2;
	}
	
	~Edge(){  std::cout << "Edge deleted" << std::endl; }
};

#endif //EDGE_H