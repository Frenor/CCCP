#include <qstandarditemmodel.h>

#include "ui_entityDialog.h"
#include "Entity.h"

//! Controller for the propery dialog box used to specify entity dimensions. 
/*!
It has a table populated with the entity's line segments with x and y coordinates.
It can dimensions and material properties for each line segment.
*/
class DimensionDialog : public QDialog
{
	Q_OBJECT
public:
	DimensionDialog(QDialog *parent = 0);
	/*!
	Sets the entity and populates the property window.
	*/
	void setDataSource(Entity*);

private:
	Ui::EntityProperties ui;
};