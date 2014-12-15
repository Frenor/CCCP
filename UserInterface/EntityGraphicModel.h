#pragma once
#ifndef ENTITYGRAPHICMODEL_H
#define ENTITYGRAPHICMODEL_H

#include <qobject.h>

#include "Entity.h"
#include "Edge.h"

class EntityGraphicModel : public QObject
{
	Q_OBJECT
public:
	EntityGraphicModel(Entity*);
	~EntityGraphicModel();

	Entity *entity;				//<! Pointer to the entity we currently are changing
	Edge *selectedEdge;

	std::vector<Node*> getNodes();
	std::vector<Edge*> getEdges();
	/*!
	Updates all values on the currently active edge, then triggers a redraw
	*/
	void updateValues(double, double, Material*);

signals:
	void selectedEdgeChanged(Edge*);
	void valuesUpdated();

public slots:
	void setSelectedEdge(Edge*);

private:

};
#endif //ENTITYGRAPHICMODEL_H