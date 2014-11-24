#include "DimensionDialog.h"


DimensionDialog::DimensionDialog(QDialog *parent) : QDialog(parent)
{
	ui.setupUi(this);
	tableModel = new QStandardItemModel(3, 2, this);
	ui.edgeListTableView->setModel(tableModel);

	selectedEdge = NULL;
}


DimensionDialog::~DimensionDialog()
{
	removeActiveGraphicView(); 
	std::cout << "DELETED: DimensionDialog" << std::endl;
}

void DimensionDialog::removeActiveGraphicView()
{
	std::cout << "DELETED: GraphicsView" << std::endl;
}

void DimensionDialog::populateEdgeTable()
{
	QStringList headerNames;
	headerNames.append(QString("Width 1"));
	headerNames.append(QString("Width 2"));
	tableModel->setHorizontalHeaderLabels(headerNames);

	int i = 0;
	for each (Edge* edge in entity->edges)
	{
		QStandardItem *row1 = new QStandardItem(QString::number(edge->width1));
		QStandardItem *row2 = new QStandardItem(QString::number(edge->width2));

		tableModel->setItem(i, 0, row1);
		tableModel->setItem(i, 1, row2);

		i++;
	}
}

void DimensionDialog::setDataSource(Entity *entity)
{
	this->entity = entity;

	populateEdgeTable();

	update();
}

void DimensionDialog::update()
{
	if (selectedEdge != NULL)
	{
		ui.widthGroupBox->setEnabled(true);
		ui.materialGroupBox->setEnabled(true);
		ui.widthNode1SpinBox->setValue(selectedEdge->width1);
		ui.widthNode2SpinBox->setValue(selectedEdge->width2);
	}
	else
	{
		ui.widthGroupBox->setEnabled(false);
		ui.materialGroupBox->setEnabled(false);
	}
}

void DimensionDialog::accept()
{

}

void DimensionDialog::reject()
{
	this->hide();
}

void DimensionDialog::apply()
{

}

void DimensionDialog::edgeSelected(QModelIndex index)
{
	selectedEdge = entity->getEdgesVector()[index.row()];
	std::cout << "Edge selected!" << std::endl;

	update();
}