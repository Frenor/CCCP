#pragma once
#ifndef DIMENSIONDIALOG_H
#define DIMENSIONDIALOG_H
#include <qstandarditemmodel.h>

#include "ui_dimensionDialog.h"
#include "Entity.h"
#include "EntityDisplayController.h"
#include "EntityDisplayModel.h"

//! Controller for the propery dialog box used to spesify edge properties. 

/*!
It has a table populated with the edges of an entity.
A visualisation of the given entity and highilights the selected edge.
It can be used to specify material properties for entities.
*/
class DimensionDialog :	public QDialog
{
	Q_OBJECT
public:
	DimensionDialog(QDialog *parent = 0);
	~DimensionDialog();

	//GraphicController* gController;		//!< Current active controller for VTK/GraphicsView
	Edge *selectedEdge;

	/*!
	Sets the entity and populates the property window.
	*/
	void setDataSource(Entity*);
	void update();
	
public slots:
	/*!
	Applies the changes and closes the dialog window
	*/
	void accept();
	/*!
	Closes the window
	*/
	void reject();
	/*!
	Function loops through the seeds and compare the entity's values with the ones in the table.
	If the difference is larger then a certain precision criterium, the entity is updated.
	*/
	void apply();
	/*!
		Edge selected in left list
	*/
	void edgeSelected(QModelIndex);

private:
	Ui::DimensionDialog ui;
	QStandardItemModel *tableModel;			//!< Model holding the UI table data
	EntityDisplayModel *displayModel;		//!< Model holding the data for the graphic display of edges
//	GraphicController *displayController;	//!< Controller for the graphic display of edges

	Entity *entity;							//!< The entity contain

	/*!
	Deletes the current GraphicController, if it exists.
	*/
	void removeActiveGraphicView();
	/*!
		Creates the labels for the header in tableModel
	*/
	void populateEdgeTable();
};

#endif //DIMENSIONDIALOG_H