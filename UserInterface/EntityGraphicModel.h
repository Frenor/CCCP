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

	Entity *entity;
	Edge *selectedEdge;

	std::vector<Node*> getNodes();
	std::vector<Edge*> getEdges();

signals:
	void selectedEdgeChanged(Edge*);

public slots:
	void setSelectedEdge(Edge*);

private:

};
#endif //ENTITYGRAPHICMODEL_H