#include "DimensionDialog.h"


DimensionDialog::DimensionDialog(Entity *entity, QDialog *parent) : QDialog(parent)
{
	this->entity = entity;
	this->selectedEdge = NULL;

	ui.setupUi(this);
	setupView();

	tableModel = new QStandardItemModel(3, 2, this);
	ui.edgeListTableView->setModel(tableModel);
	populateEdgeTable();

	connect(this, SIGNAL(selectedEdgeChanged(Edge*)), this, SLOT(update()));
	
	update();
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

void DimensionDialog::update()
{
	if (selectedEdge)
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

	emit selectedEdgeChanged(selectedEdge);
}

void DimensionDialog::setupView()
{
	gModel = new EntityGraphicModel(entity);
	gController = new EntityGraphicController(this->gModel, ui.GraphicsWidget, this);

	connect(this, SIGNAL(selectedEdgeChanged(Edge*)), gModel, SLOT(setSelectedEdge(Edge*)));

	//connect(this->cModel, &CModel::newDrawModel, (DrawController*)gController, &DrawController::setModel);
}