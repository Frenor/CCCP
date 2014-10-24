#include "TreeItem.h"

TreeItem::TreeItem(const QString &name, Entity* entity) : QStandardItem(name)
{
	this->type = ENTITY;
	this->entityReferece = entity;
}