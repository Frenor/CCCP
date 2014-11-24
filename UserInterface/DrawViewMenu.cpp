#include "DrawViewMenu.h"

DrawViewMenu::DrawViewMenu(QWidget *view, EntityOperation* eOperation, DrawModel* model, QObject *parent) : QObject(parent)
{
	this->view = view;
	this->model = model;

	connect(view, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(ShowContextMenu(const QPoint&)));
	connect(this, SIGNAL(newAction(int)), eOperation, SLOT(setEntityOperation(int)));
	connect(this, SIGNAL(propertiesSelected(Entity*)), model, SLOT(showProperties(Entity*)));
	connect(this, SIGNAL(dimensionsSelected(Entity*)), model, SLOT(showDimensions(Entity*)));
}

void DrawViewMenu::ShowContextMenu(const QPoint& pos)
{
    QPoint globalPos = view->mapToGlobal(pos);
	Entity *activeEntity = model->activeEntity;

    QMenu menu;
	QAction *aProperties = menu.addAction("Properties");
	QAction *aDimensions;
	if (activeEntity != NULL && activeEntity->crossectionType == Entity::THINWALLED) {
		aDimensions = menu.addAction("Dimensions");
	}

	menu.addSeparator();

    QAction *aCut = menu.addAction("Cut");
	QAction *aFuse = menu.addAction("Fuse");
    
    QAction* selectedItem = menu.exec(globalPos);
    if (selectedItem)
    {
		//std::cout << "Item selected from MENU" << std::endl;
		if(selectedItem == aCut)
		{
			int out = BRepFactory::SUBTRACT;
			emit newAction(out);
		}
		if(selectedItem == aFuse)
		{
			int out = BRepFactory::ADD;
			emit newAction(out);
		}
		if(selectedItem == aProperties)
		{
			emit propertiesSelected(NULL);
		}
		if (selectedItem == aDimensions)
		{
			emit dimensionsSelected(activeEntity);
		}
    }
}
