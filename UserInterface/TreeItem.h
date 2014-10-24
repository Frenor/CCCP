#pragma once

#include <QStandardItemModel>
#include "Entity.h"

//! Holder for an entity shown in the TreeWidget. It holds a reference to the entity for fast selection.
class TreeItem : public QStandardItem
{
public:
	TreeItem(const QString &, Entity*entity);
	~TreeItem() {}

	int type;

	static const int MATERIAL = 0;
	static const int ENTITY = 1;

	Entity * entityReferece;	//!< Reference to the entity
};