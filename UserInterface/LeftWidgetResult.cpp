#include "LeftWidgetResult.h"

LeftWidgetResult::LeftWidgetResult(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.listWidget, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem *)), this, SLOT(clicked(QListWidgetItem *))); 

	std::cout << "CREATED: LeftWidgetResult" << std::endl;
}

void LeftWidgetResult::setModel(ResultModel* model)
{
	this->model = model;
	connect(model, SIGNAL(modelDataSourceChanged()), this, SLOT(updateList()));

	updateList();
}

void LeftWidgetResult::updateList()
{
	ui.listWidget->clear();
	
	for each (std::string resultName in model->resultNames)
	{
		ui.listWidget->addItem(new QListWidgetItem(resultName.c_str()));
	}
}

void LeftWidgetResult::clicked(QListWidgetItem *current)
{
	//Receives a NULL pointer on clear() because of connection to "currentItemChanged"
	if(current)
	{
		model->setActiveResult(current->text());
	}
}