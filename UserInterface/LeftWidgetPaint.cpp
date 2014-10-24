#include "LeftWidgetPaint.h"

LeftWidgetPaint::LeftWidgetPaint(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
	EntityTreeMenu *eMenu = new EntityTreeMenu(ui.treeView, this);
	
	std::cout << "CREATED: LeftWidgetPaint" << std::endl;
}

void LeftWidgetPaint::setModel(DrawModel* model)
{
	this->model = model;
	treeModel = new TreeDrawModel(model);

	connect(ui.treeView, &QTreeView::clicked, treeModel, &TreeDrawModel::clicked);

	ui.treeView->setHeaderHidden(true);
	ui.treeView->setModel(treeModel);
	ui.treeView->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.treeView->expandAll();
}

void LeftWidgetPaint::showPropertiesWindow()
{
	QModelIndex index = ui.treeView->currentIndex();
	if(treeModel->hasChildren(index))
	{
		TreeItem *treeItem = treeModel->getTreeItemFromIndex(index);
		model->showProperties(treeItem->entityReferece);
	}
}