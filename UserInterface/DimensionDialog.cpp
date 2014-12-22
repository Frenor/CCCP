#include "DimensionDialog.h"
#include "DrawModel.h"


DimensionDialog::DimensionDialog(Entity **entity, DrawModel *model, QDialog *parent) : QDialog(parent)
{
	this->originalEntity = entity;
	Entity *ptr = *entity;
	this->entity = ptr->clone(parent);
	this->model = model;
	this->isPopulating = true;

	ui.setupUi(this);
	setupView();

	connect(ui.buttonBox->button(QDialogButtonBox::Apply), SIGNAL(released()), this, SLOT(apply()));

	tableModel = new QStandardItemModel(3, 2, this);
	ui.edgeListTableView->setModel(tableModel);
	populateEdgeTable();
	populateMaterialsComboBox();

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
	std::cout << "DELETED: DimensionDialog-GraphicsView" << std::endl;
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
		std::vector<QStandardItem*> row = generateRow(edge);
		tableModel->setItem(i, 0, row.at(0));
		tableModel->setItem(i, 1, row.at(1));

		i++;
	}
}

std::vector<QStandardItem*> DimensionDialog::generateRow(Edge *edge)
{
	std::vector<QStandardItem*> result;
	QStandardItem *col1 = new QStandardItem(QString::number(edge->width1));
	QStandardItem *col2 = new QStandardItem(QString::number(edge->width2));
	result.push_back(col1);
	result.push_back(col2);
	return result;
}

void DimensionDialog::update()
{
	if (gModel->selectedEdge)
	{
		isPopulating = true;

		ui.widthGroupBox->setEnabled(true);
		ui.materialGroupBox->setEnabled(true);
		ui.widthNode1SpinBox->setValue(gModel->selectedEdge->width1);
		ui.widthNode2SpinBox->setValue(gModel->selectedEdge->width2);
		
		if (gModel->selectedEdge->material) 
		{
			ui.materialsComboBox->setCurrentIndex(model->findMaterialId(gModel->selectedEdge->material));
		}
		else
		{
			ui.materialsComboBox->setCurrentIndex(-1);
		}
		
		isPopulating = false;
	}
	else
	{
		ui.widthGroupBox->setEnabled(false);
		ui.materialGroupBox->setEnabled(false);
	}
}

void DimensionDialog::accept()
{
	emit saveEntity(entity, originalEntity);

	this->hide();
	emit close();
}

void DimensionDialog::reject()
{
	this->hide();
	emit close();
}

void DimensionDialog::apply()
{
	//Do nothing, saves only on "OK"
}

void DimensionDialog::edgeSelected(QModelIndex index)
{
	selectedRow = index.row();

	emit selectedEdgeChanged(entity->getEdge(selectedRow));
}

void DimensionDialog::setupView()
{
	gModel = new EntityGraphicModel(entity);
	gController = new EntityGraphicController(this->gModel, ui.GraphicsWidget, this);

	connect(this, SIGNAL(selectedEdgeChanged(Edge*)), gModel, SLOT(setSelectedEdge(Edge*)));
}

void DimensionDialog::propertyChanged()
{
	if (!isPopulating)
	{
		gModel->updateValues(ui.widthNode1SpinBox->value(), ui.widthNode2SpinBox->value(), model->materials.at(1));

		tableModel->item(selectedRow, 0)->setText(QString::number(ui.widthNode1SpinBox->value()));
		tableModel->item(selectedRow, 1)->setText(QString::number(ui.widthNode2SpinBox->value()));
	}
}

void DimensionDialog::populateMaterialsComboBox()
{
	for each (Material *mat in model->materials)
	{
		ui.materialsComboBox->addItem(mat->name);
	}
}