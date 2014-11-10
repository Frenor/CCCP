#include "Edge.h"

Edge::Edge(Node* node1, Node* node2)
{
	this->n1 = node1;
	this->n2 = node2;
	this->width1 = 1.0;
	this->width2 = 1.0;
}

Edge::~Edge(){ std::cout << "Edge deleted" << std::endl; }

void Edge::setWidth(double width1, double width2)
{
	this->width1 = width1;
	this->width2 = width2;
}