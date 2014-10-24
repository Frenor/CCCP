#include "TreeDrawModel.h"

TreeDrawModel::TreeDrawModel(DrawModel *model, QObject *parent) : QStandardItemModel(parent)
{
	this->topNode = invisibleRootItem();
	
	connect(this, &TreeDrawModel::selectionChanged, model, &DrawModel::setActiveInput);
	connect(model, &DrawModel::entityCreated, this, &TreeDrawModel::addEntity);
	connect(model, &DrawModel::entityDeleted, this, &TreeDrawModel::invalidate);
	connect(model, &DrawModel::entityDeleted, this, &TreeDrawModel::removeEntity);
}

void TreeDrawModel::setDataSource(DrawModel* model)
{
	this->dataModel = model;
}

void TreeDrawModel::invalidate()
{
	setDataSource(dataModel);
}

void TreeDrawModel::addEntity(Entity* entity)
{
	this->topNode = invisibleRootItem();

	const QString name = entity->name.c_str();
	TreeItem* preparedRow = new TreeItem(name, entity);
	topNode->appendRow(preparedRow);

	QList<QStandardItem *> materialRow = prepareRow("Material");
	preparedRow->appendRow(materialRow);

	QList<QStandardItem *> nodesRow = prepareRow("Nodes");
	preparedRow->appendRow(nodesRow);

	treeItemLookupTable[entity] = preparedRow;
}

void TreeDrawModel::removeEntity(Entity* deletedEntity)
{
	TreeItem* treeItem = treeItemLookupTable[deletedEntity];
	//std::cout << "Remove entity from tree. Index:" << row << std::endl; 
	int row = indexFromItem(treeItem).row();

	removeRow(row);
}

void TreeDrawModel::clicked(const QModelIndex &index)
{
	TreeItem *entity = getTreeItemFromIndex(index);

	switch(entity->type)
	{
	case TreeItem::ENTITY:
		emit selectionChanged(entity->entityReferece);
		break;

	case TreeItem::MATERIAL:
		//emit material change
		break;
	}
}

TreeItem* TreeDrawModel::getTreeItemFromIndex(const QModelIndex &index)
{
	return (TreeItem*)itemFromIndex(index);
}

QList<QStandardItem *> TreeDrawModel::prepareRow(const QString &first)
{
	QList<QStandardItem *> rowItems;
	rowItems << new QStandardItem(first);
	return rowItems;
}

void TreeDrawModel::newEntity(Entity* entity)
{
	addEntity(entity);
}