#ifndef LEFTWIDGETRESULT_H
#define LEFTWIDGETRESULT_H

#include <QtWidgets/QWidget>

#include "ui_LeftWidgetResult.h"
#include "ResultModel.h"

#include <iostream>

namespace Ui {
	class LeftWidgetResult;
}

//! A controller for the result widget that shows results available in the result model.
/*!	
	It lets the user change the active result.
*/
class LeftWidgetResult : public QWidget
{
	Q_OBJECT
public:
	LeftWidgetResult(QWidget *parent = 0);
	~LeftWidgetResult(){ std::cout << "DELETED: LeftWidgetResult" << std::endl; }

public slots:
	void setModel(ResultModel*);
	/*!
		Sets the model active result name to the name of the list item.
	*/
	void clicked(QListWidgetItem*);
	/*	
		Clear the list and add result names in the model to the list.
	*/
	void updateList();

private:
	Ui::LeftWidgetResult ui;	//!< Reference to widget ui file 
	ResultModel * model;		//!< Reference to the model
};
#endif //LEFTWIDGETRESULT_H