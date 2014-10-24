#include "EntityPoly.h"

EntityPoly::EntityPoly(QObject *parent) : Entity(parent)
{
	this->editable = editable;
	this->finalized = false;
	this->type = Entity::POLYGON;
	this->name = "Entity-Polygon";

	this->lastSelectedNode = NULL;
}

void EntityPoly::changeNode(double pos[], int handle)
{
	clickNode(handle);		//vtkSeedWidget does not fire it's event on mousePress
	for each (Node *node in getSeeds())
	{
		if(node->handle == handle)
		{
			node->setPosition(pos);
			break;
		}
	}
	emit entityChanged(this);
}

void EntityPoly::clickNode(int handle)
{
	if(handle == 0 && nodes.size() > 1 && !isClosed())
	{
		close();
		emit entityFinalized();
	}
}

void EntityPoly::createNode(double pos[], int handle)
{
	Entity::addNode(pos, handle);
	emit entityChanged(this);
}

std::vector<Node*> EntityPoly::getSeeds()
{
	std::cout << nodes.size() << std::endl;
	std::vector<Node *> seeds;
	for each (Node *node in nodes)
	{
		seeds.push_back(node);
	}
	return seeds;
}