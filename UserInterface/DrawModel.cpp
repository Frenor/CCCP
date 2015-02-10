#include "DrawModel.h"

DrawModel::DrawModel(QObject *parent) : QObject(parent)
{
	activeEntity = NULL;
	activeEntityFinalized = true;
	activeType = Entity::MASSIVE;
	populateMaterials();
}

void DrawModel::setActiveInput(Entity *entity)
{
	if (activeEntity)
	{
		activeEntity->setActive(false); //Deactivate old first
	}
	this->activeEntity = entity;
	emit activeEntityChanged(entity);
}

bool DrawModel::isActiveEntity(Entity * entity)
{
	if(activeEntity && activeEntity == entity)
	{
		return true;
	}

	return false;
}

bool DrawModel::isNotActiveEntity(Entity *entity)
{
	if(activeEntity == entity)
	{
		return false;
	}

	return true;
}

void DrawModel::executeEntityOperation(EntityOperation* eOperation)
{
	std::cout << "Operation executed" << std::endl;
	EntityBRep *entity = new EntityBRep(eOperation->entity1, eOperation->entity2, eOperation->operation);

	addEntity(entity);
	
	std::cout << "Add entity: " << entity << std::endl;

	removeEntity(eOperation->entity1);
	removeEntity(eOperation->entity2);
}

void DrawModel::createEntityPolygon()
{
	EntityPoly *polygon = new EntityPoly;
	addEntity(polygon);
}

void DrawModel::createEntityCircle()
{
	EntityCircle *circle = new EntityCircle;
	addEntity(circle);
}

void DrawModel::addEntity(Entity* entity)
{
	entities.push_back(entity);
	updateEntityLevels();

	entity->setCrossectionType(getActiveDrawType());
	setActiveInput(entity);
	std::cout << "Entity added" << std::endl;

	connect(entity, &Entity::entityChanged, this, &DrawModel::setEntityChanged);
	connect(entity, &Entity::entityFinalized, this, &DrawModel::setActiveEntityNULL);
	connect(this, &DrawModel::drawTypeChanged, entity, &Entity::drawTypeChanged);

	emit entityCreated(entity);
}

void DrawModel::deleteActiveEntity()
{
	if(activeEntity)
	{
		Entity * lastActiveEntity = activeEntity;
		activeEntity = NULL;
		deleteEntity(lastActiveEntity);
	}
}
void DrawModel::uiModeChanged()
{
	setActiveEntityNULL();
	for each (Entity *entity in entities)
	{
		finalizeEntity(entity);
	}
}

void DrawModel::deleteEntity(Entity *entity)
{
	removeEntity(entity);
	delete entity;
}

void DrawModel::removeEntity(Entity *entity)
{
	entities.remove(entity);
	updateEntityLevels();
	std::cout << "Entity removed" << std::endl;
	emit entityDeleted(entity);
}

void DrawModel::finalizeActiveEntity()
{
	if(activeEntity)
	{
		finalizeEntity(activeEntity);
	}
}

void DrawModel::finalizeEntity(Entity *entity)
{
	if (entity->crossectionType == Entity::MASSIVE)
	{
		entity->close();
	}

	entity->setIsFinalized(true);
	setActiveEntityNULL();
}

void DrawModel::setActiveEntityNULL()
{
	activeEntityFinalized = true;
	for each (Entity *entity in entities)
	{
		entity->setActive(false);
	}
	setActiveInput(NULL);
}

std::vector<Node*> DrawModel::getAllNodes()
{
	std::vector<Node*> nodes;

	for each (Entity* entity in entities)
	{
		nodes.insert(nodes.end(), entity->nodes.begin(), entity->nodes.end());
	}

	return nodes;
}

std::vector<Edge*> DrawModel::getAllEdges()
{
	std::vector<Edge*> edges;

	for each (Entity* entity in entities)
	{
		edges.insert(edges.end(), entity->edges.begin(), entity->edges.end());
	}

	return edges;
}

void DrawModel::setEntityChanged(Entity * entity)
{
	emit entityChanged(entity);
}

void DrawModel::updateEntityLevels()
{
	int i = 0;
	for each (Entity* entity in entities)
	{
		entity->setLevel(++i);
	}
}

void DrawModel::showProperties(Entity* entity)
{
	if(entity || activeEntity)
	{
		EntityDialog *eDialog = new EntityDialog;
		eDialog->setDataSource(entity ? entity : activeEntity);
		eDialog->show();
	}
}

void DrawModel::showDimensions(Entity* entity)
{
	if (entity || activeEntity)
	{
		DimensionDialog dDialog(entity ? &entity : &activeEntity, this);
		connect(&dDialog, SIGNAL(close()), this, SLOT(dialogClosing()));
		connect(&dDialog, SIGNAL(saveEntity(Entity*, Entity**)), this, SLOT(saveEntity(Entity*, Entity**)));
		dDialog.exec();
	}
}

void DrawModel::setDrawType(int type)
{
	this->activeType = type;
	emit drawTypeChanged(type);
}

int DrawModel::getActiveDrawType() {
	return activeType;
}

void DrawModel::dialogClosing()
{
	std::cout << "Dialog closing" << std::endl;
	emit dialogClosed();
}

void DrawModel::saveEntity(Entity *newEntity, Entity **originalEntity)
{
	removeEntity(*originalEntity);
	addEntity(newEntity);
}


void DrawModel::populateMaterials()
{
	for (int i = 0; i < 10; i++)
	{
		Material *m = new Material("Material " + std::to_string(i));
		materials.push_back(m);
	}
}

int DrawModel::findMaterialId(Material *mat)
{
	int i = -1;
	if (mat)
	{
		std::vector<Material*>::iterator it;
		it = std::find(materials.begin(), materials.end(), mat);
		if (it != materials.end())
			i = std::distance(materials.begin(), it);
	}
	return i;
}

Node* DrawModel::findCloseNode(double pos[])
{
	for each (Entity *entity in entities)
	{
		if (entity != activeEntity) {
			for each (Node *node in entity->nodes)
			{
				std::cout << "Searching for close nodes" << std::endl;
				if (abs(node->x - pos[0]) < snapPrecision || abs(node->y - pos[1]) < snapPrecision)
				{
					std::cout << "Close node found!" << std::endl;
					return node;
				}
			}
		}
	}
	return NULL;
}

void DrawModel::mergeEntities(Entity*, Entity*)
{

}