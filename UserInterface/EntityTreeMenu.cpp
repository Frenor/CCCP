#include "EntityTreeMenu.h"

EntityTreeMenu::EntityTreeMenu(QWidget* treeView, QObject *parent)
{
	this->view = treeView;

	connect(treeView, &QTreeView::customContextMenuRequested, this, &EntityTreeMenu::show);
	connect(this, SIGNAL(propertiesSelected()), parent, SLOT(showPropertiesWindow()));
}

void EntityTreeMenu::show(const QPoint& point)
{
	QMenu menu;
	QPoint globalPos = view->mapToGlobal(point);

    QAction *aProperties = menu.addAction("Properties");

	QAction* selectedItem = menu.exec(globalPos);
    if (selectedItem)
    {
		if(selectedItem == aProperties)
		{
			emit propertiesSelected();
		}
	}
}