#ifndef DRAWVIEWMENU_H
#define DRAWVIEWMENU_H

#include <iostream>

#include <qobject.h>
#include <qmenu.h>
#include "BRepFactory.h"
#include "EntityOperation.h"
#include "DrawModel.h"

//! Context menu shown in the GraphcsView in draw mode after the user right click on an entity.
class DrawViewMenu : public QObject
{
	Q_OBJECT
public:
	DrawViewMenu(QWidget*, EntityOperation*, DrawModel*, QObject *parent);

public slots:
	/*!
		Adds possible actions to the menu and displays it at the given postion.
	*/
	void ShowContextMenu(const QPoint& pos);

signals:
	void newAction(int operation);		//!< Emitted when an operation is selected
	void propertiesSelected(Entity*);	//!< Emitted when properties is selected

private:
	QWidget *view;
};
#endif //DRAWVIEWMENU_H