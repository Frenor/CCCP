#include "Edge.h"

Edge::Edge(Node *node1, Node *node2)
{
	this->n1 = node1;
	this->n2 = node2;
	this->width1 = 0.1000;
	this->width2 = 0.1000;
	this->material = NULL;
}

Edge::Edge(const Edge &e)
{
	this->n1 = e.n1;
	this->n2 = e.n2;
	this->width1 = e.width1;
	this->width2 = e.width2;
	this->material = e.material;
}

Edge::~Edge()
{
	std::cout << "Edge deleted" << std::endl;
}

Edge* Edge::clone() const
{
	return new Edge(*this);
}

void Edge::setWidth(double width1, double width2)
{
	this->width1 = width1;
	this->width2 = width2;
}