#include "EntityGraphicModel.h"


EntityGraphicModel::EntityGraphicModel(Entity *entity)
{
	this->entity = entity;
	this->selectedEdge = NULL;
}


EntityGraphicModel::~EntityGraphicModel()
{
}

void EntityGraphicModel::setSelectedEdge(Edge *selectedEdge)
{
	this->selectedEdge = selectedEdge;
	emit selectedEdgeChanged(selectedEdge);
}

std::vector<Node*> EntityGraphicModel::getNodes()
{
	std::vector<Node*> nodes;
	nodes.insert(nodes.end(), this->entity->nodes.begin(), this->entity->nodes.end());
	return nodes;
}

std::vector<Edge*> EntityGraphicModel::getEdges()
{
	std::vector<Edge*> edges;
	edges.insert(edges.end(), this->entity->edges.begin(), this->entity->edges.end());
	return edges;
}

void EntityGraphicModel::updateValues(double width1, double width2)
{
	selectedEdge->width1 = width1;
	selectedEdge->width2 = width2;

	emit valuesUpdated();
}
