#include <QtWidgets/QWidget>
#include <iostream>

#include "ui_LeftWidgetPaint.h"
#include "DrawModel.h"
#include "TreeDrawModel.h"
#include "EntityTreeMenu.h"
#include "EntityDialog.h"

namespace Ui {
	class LeftWidgetPaint;
}

//! A controller for the tree widget showing the entities in draw model.
/*!
	It lets the user select entities and edit their properties through a context menu
*/
class LeftWidgetPaint : public QWidget
{
	Q_OBJECT
public:
	LeftWidgetPaint(QWidget *parent = 0);
	~LeftWidgetPaint(){ std::cout << "DELETED: LeftWidgetPaint" << std::endl; }
	
	/*!
		Sets the model and connect the click callback to the model.
	*/
	void setModel(DrawModel*);

public slots:
	/*!
		Callback from the context menu. 
		The property window is activated through the draw model, on the entity selected in the tree.
	*/
	void showPropertiesWindow();

private:
	Ui::LeftWidgetPaint ui;
	DrawModel* model;			//!< Reference to the draw model. The data model
	TreeDrawModel *treeModel;	//!< Tree model contains items related to the tree.
};