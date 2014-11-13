#pragma once
#ifndef TREEDRAWMODEL_H
#define TREEDRAWMODEL_H

#include <QStandardItemModel>
#include "Entity.h"
#include "TreeItem.h"
#include "DrawModel.h"

//! Tree model for Qt's tree widget. It implements functionality for entity selection in the tree, and listen for signals from the draw model.
class TreeDrawModel : public QStandardItemModel
{
	Q_OBJECT
public:
	QStandardItem* topNode;
	DrawModel* dataModel;

	std::map<Entity*, TreeItem*> treeItemLookupTable;
	
	TreeDrawModel(DrawModel*, QObject* parent = 0);
	void addEntity(Entity*);
	void invalidate();
	void setDataSource(DrawModel* model);
	QList<QStandardItem *> prepareRow(const QString &);
	void clicked(const QModelIndex &);
	TreeItem* getTreeItemFromIndex(const QModelIndex &index);

public slots:
	void newEntity(Entity*);
	void removeEntity(Entity*);

signals:
	void selectionChanged(Entity*);
};
#endif //TREEDRAWMODEL_H