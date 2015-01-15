#include "AbstractExport.h"

AbstractExport::AbstractExport(DrawModel *model)
{
	createGlobalNodes(model->getAllNodes());
	createGlobalEdges(model->getAllEdges());
	createLineloops(model->entities);
	findUsedMaterials(model->entities);
}

AbstractExport::~AbstractExport()
{
	save();
}

bool AbstractExport::open(std::string fileName)
{
	file.open(fileName);
	if (!file.is_open())
	{
		return false;
	}
	return true;
}

void AbstractExport::save()
{
	if (!file.is_open())
	{
		file.close();
	}
}

void AbstractExport::createGlobalNodes(std::vector<Node*> localNodes)
{
	int i = 0;
	for each (Node* node in localNodes)
	{
		nodeLookupTable[node] = i++;
		//std::cout << "Node " << node << ",  nr " <<  node->id << " has global nr: " << i << std::endl;
	}
	globalNodes = localNodes;
}

void AbstractExport::createGlobalEdges(std::vector<Edge*> localEdges)
{
	globalEdges = localEdges;
}

int AbstractExport::findGlobalNodeNumber(Node* node)
{
	return nodeLookupTable[node];
}

void AbstractExport::createLineloops(std::list<Entity*> entities)
{
	int edgeNumber = 0;
	int entityNumber = 0;
	for each (Entity* entity in entities)
	{
		if(entity->edges.size() > 0 && entity->isClosed()){
			std::vector<int> lineloop;
			for each (Edge *edge in entity->getEdgesOrderedClockWise())
			{
				lineloop.push_back(++edgeNumber);
			}

			lineloops.push_back(lineloop);
			if (entity->crossectionType != Entity::THINWALLED)
			{
				surfaces.push_back(entityNumber++);
			}
		}
	}
}

void AbstractExport::findUsedMaterials(std::list<Entity*> entities)
{
	//find materials in entities

	//find materials in edges
}