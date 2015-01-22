#include "EntityCircle.h"

EntityCircle::EntityCircle(QObject *parent) : Entity(parent)
{
	this->type = Entity::CIRCLE;
	this->name = "Entity-Circle";
	this->segmentNum = 100;
}

EntityCircle::EntityCircle(const EntityCircle &original, QObject *parent) : Entity(original, parent)
{
	this->segmentNum = original.segmentNum;
}

EntityCircle* EntityCircle::clone(QObject *parent) const
{
	return new EntityCircle(*this, parent);
}

double EntityCircle::getRadius()
{
	double dx = getEdge()->x - getCentre()->x;
	double dy = getEdge()->y - getCentre()->y;

	return sqrt(dx*dx + dy*dy);
}

Node* EntityCircle::getCentre()
{
	return seeds[0];
}

Node* EntityCircle::getEdge()
{
	return seeds[1];
}

void EntityCircle::createNode(double pos[], int handle)
{
	if(!finalized && seeds.size() < 1)
	{
		createSeed(pos, handle);
	}
	else if(!finalized && seeds.size() < 2)
	{
		createSeed(pos, handle);

		createCircleBorder();
		connect(this, &EntityCircle::nodeChanged, this, &EntityCircle::createCircleBorder);
	}
}

void EntityCircle::createCircleBorder()
{
	reset();

	double stepSize = 2 * M_PI / segmentNum;

	double dx = getEdge()->x - getCentre()->x;
	double dy = getEdge()->y - getCentre()->y;

	double r = sqrt(dx*dx + dy*dy);
	double startAngle = atan2(dy,dx);

	for (int i = 0; i < segmentNum; i++)
	{
		double pos[2];
		pos[0] = getCentre()->x + r * cos(startAngle + stepSize*i);
		pos[1] = getCentre()->y + r * sin(startAngle + stepSize*i);

		Entity::addNode(pos, -1);
	}
	close();
	emit entityChanged(this);
}

void EntityCircle::reset()
{
	this->lastSelectedNode = NULL;
	this->closed = false;

	deleteEdges();
	deleteNodes();
}

void EntityCircle::changeNode(double pos[], int handle)
{
	//std::cout << "nSeedNodes: " << getSeeds().size() << std::endl;
	for each (Node *node in getSeeds())
	{
		if(node->handle == handle)
		{
			node->setPosition(pos);
			break;
		}
	}

	emit nodeChanged();
}

std::vector<Node*> EntityCircle::getSeeds()
{
	return seeds;
}
