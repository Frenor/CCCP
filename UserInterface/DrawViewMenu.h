#include <iostream>

#include <qobject.h>
#include <qmenu.h>
#include "BRepFactory.h"
#include "EntityOperation.h"
#include "DrawModel.h"
#include <vector>

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
	void showContextMenu(const QPoint& pos);
	/*!
		Adds and removes menu elements based on current drawing type
	*/
	void drawTypeChanged(int);

signals:
	void newAction(int operation);		//!< Emitted when an operation is selected
	void propertiesSelected(Entity*);	//!< Emitted when properties is selected
	void dimensionsSelected(Entity*);	//!< Emitted when dimensions is selected

private:
	QWidget *view;
	bool showDimensions;				//!< Should Dimensions be displayed in the context menu?
};