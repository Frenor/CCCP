#ifndef ENTITYTREEMENU_H
#define ENTITYTREEMENU_H

#include <qobject.h>
#include <qmenu.h>
#include "Entity.h"
#include <qtreeview.h>

//! Context menu displayed in the entity tree widget in draw mode. It is displayed when the user right click on an entity in the tree.
class EntityTreeMenu : public QObject
{
	Q_OBJECT
public: 
	QWidget *view;
	
	EntityTreeMenu(QWidget*, QObject*);
	/*!
		Adds "properties" to the menu and displays the menu at the given position
	*/
	void show(const QPoint& point);

signals:
	void propertiesSelected();	//!< Emitted the properties is clicked in the context menu
};
#endif //ENTITYTREEMENU_H