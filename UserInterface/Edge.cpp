#include "Edge.h"

Edge::Edge(Node *node1, Node *node2)
{
	this->n1 = node1;
	this->n2 = node2;
	this->width1 = NULL;
	this->width2 = NULL;
	this->material = NULL;
}

Edge::Edge(Node *node1, Node *node2, double w1, double w2) : Edge(node1, node2)
{
	this->width1 = w1;
	this->width2 = w2;
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