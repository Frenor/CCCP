#pragma once
#ifndef DIMENSIONDIALOG_H
#define DIMENSIONDIALOG_H
#include <qstandarditemmodel.h>
#include <qpushbutton.h>

#include "ui_dimensionDialog.h"
#include "Entity.h"
#include "EntityGraphicController.h"
#include "EntityGraphicModel.h"

//! Controller for the propery dialog box used to spesify edge properties. 

/*!
It has a table populated with the edges of an entity.
A visualisation of the given entity and highilights the selected edge.
It can be used to specify material properties for entities.
*/
class DimensionDialog : public QDialog
{
	Q_OBJECT

public:
	DimensionDialog(Entity*, QDialog* parent = 0);
	~DimensionDialog();

	EntityGraphicController* gController;	//!< Current active controller for VTK/GraphicsView
	EntityGraphicModel* gModel;				//!< Model holding the data for the graphic display of edges

	int selectedRow;
	bool isPopulating;						//!< When fields are being populated, ignore change events

signals:
	/*!
		Signal fired when a new edge is selected
	*/
	void selectedEdgeChanged(Edge*);
	/*!
	Signal fired when a this dialog is closing
	*/
	void close();
	/*!
	Signal fired when the user wants to save the Entity

	*/
	void saveEntity(Entity* newEntity, Entity* oldEntity);

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
	Applies the changes to the active edge.
	*/
	void apply();
	/*!
		Edge selected in left list
	*/
	void edgeSelected(QModelIndex);

	/*!
	Updates enabled/disabled interface features, field values and passes updated values to the graphic widget
	*/
	void update();

	/*!
	Collects data from all fields and stores them temporarily
	*/
	void propertyChanged();
private:
	Ui::DimensionDialog ui;
	QStandardItemModel* tableModel; //!< Model holding the UI table data

	Entity* entity;					//!< Entity clone for editing
	Entity* originalEntity;			//!< The original entity

	/*!
	Deletes the current GraphicController, if it exists.
	*/
	void removeActiveGraphicView();
	/*!
		Creates the labels for the header in tableModel
	*/
	void populateEdgeTable();
	/*!
		Initalize and prepare VTK Widget for display
	*/
	void setupView();
	std::vector<QStandardItem*> generateRow(Edge*);
};

#endif //DIMENSIONDIALOG_H

