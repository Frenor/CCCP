#pragma once
#ifndef ENTITYDISPLAYMODEL_H
#define ENTITYDISPLAYMODEL_H

#include "Edge.h"

class EntityDisplayModel
{
public:
	EntityDisplayModel();
	~EntityDisplayModel();

	Edge *selectedEdge;
};
#endif //ENTITYDISPLAYMODEL_H