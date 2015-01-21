#pragma once
#ifndef ENTITYDIALOG_H
#define ENTITYDIALOG_H
#include <qstandarditemmodel.h>

#include "ui_entityDialog.h"
#include "Entity.h"
#include "EntityCircle.h"

//! Controller for the propery dialog box used to spesify entity properties. 
/*!	
	It has a table populated with the entity'ss seed positions on x and y axes. 
	It can also be used to spesify material properties for entities.
*/
class EntityDialog : public QDialog
{
	Q_OBJECT
public:
	EntityDialog(QDialog *parent = 0);
	/*!
		Sets the entity and populates the property window.
	*/
	void setDataSource(Entity* );

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

private:
	Ui::EntityProperties ui;

	Entity* entity;						//!< Data model modified if changes are saved
	QStandardItemModel *tableModel;		//!< Model holding the UI table data

	/*!
		Creates a number of material names to fill the material box, 
		to show planned work flow. Not implemented further than a list of example materials.
	*/
	void fillMaterialList();

	/*!
		Creates and adds header labels to the table widget
	*/
	void createHeaderLabels();
	/*!
		Loop through the entity's seed and adding the yx position to table positions.
	*/
	void update();
	
	/*!
		Converts content in a table cell to a double. 
		Used to retrieve data from the table model to the entity when data is saved.
	*/
	double tableCellToDouble(int, int);
};
#endif //ENTITYDIALOG_H