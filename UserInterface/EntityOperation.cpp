#include "EntityOperation.h"

EntityOperation::EntityOperation(QObject* model, QObject *parent) : QObject(parent)
{
	resetOperation();

	connect(model, SIGNAL(activeEntityChanged(Entity*)), this, SLOT(newSelection(Entity*)));
	connect(model, SIGNAL(entityDeleted(Entity*)), this, SLOT(removeEntity(Entity*)));
	connect(this, SIGNAL(execute(EntityOperation*)), model, SLOT(executeEntityOperation(EntityOperation*)));
}

void EntityOperation::resetOperation()
{
	entity1 = NULL;
	entity2 = NULL;
	operation = -1;
	locked = false;
}

void EntityOperation::setEntityOperation(int operation)
{
	this->operation = operation;
	execute();
}

void EntityOperation::removeEntity(Entity* entity)
{
	if(entity1 == entity)
	{
		entity1 = NULL;
	}
	if(entity2 == entity)
	{
		entity2 = NULL;
	}
}

void EntityOperation::newSelection(Entity * entity)
{
	if(!locked)
	{
		if(!entity)
		{
			resetOperation();
			return;
		}
		else if(!entity->isEmpty())
		{
			if(!this->entity1)
			{
				this->entity1 = entity;
			}
			else if(this->entity1 != entity)
			{
				this->entity2 = entity;
				execute();
			}
		}
	}
}

void EntityOperation::execute()
{
	if(hasValidOperation())
	{
		locked = true;
		emit execute(this);

		resetOperation();
	}
}

bool EntityOperation::hasValidOperation()
{
	if(!locked)
	{
		if(entity1 && entity2 && operation >= 0)
		{
			return true;
		}
	}
	return false;
}
