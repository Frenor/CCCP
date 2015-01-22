#include "EntityDialog.h"

EntityDialog::EntityDialog(QDialog *parent) : QDialog(parent)
{
	ui.setupUi(this);
	fillMaterialList();

	connect(ui.buttonBox->button(QDialogButtonBox::Apply), SIGNAL(released()), this, SLOT(apply()));

	tableModel = new QStandardItemModel(3,2,this);
	ui.tableView->setModel(tableModel);
}

void EntityDialog::setDataSource(Entity* entity)
{
	this->entity = entity;

	ui.EntityNameLabel->setText(entity->name.c_str());
	if (entity->type == Entity::CIRCLE)
	{
		ui.segmentSpinBox->setValue(dynamic_cast<EntityCircle*>(entity)->segmentNum);
	}
	else
	{
		ui.segmentLabel->deleteLater();
		ui.segmentSpinBox->deleteLater();
	}

	tableModel->clear();
	createHeaderLabels();

	update();
}

void EntityDialog::fillMaterialList()
{
	ui.comboBox->addItem("Steel-A6");
	ui.comboBox->addItem("Titanium");
	ui.comboBox->addItem("Fiberglass/Epoxy(90)");
	ui.comboBox->addItem("Fiberglass/Epoxy(45)");
}

void EntityDialog::createHeaderLabels()
{
	QStringList headerNames;
	headerNames.append(QString("X"));
	headerNames.append(QString("Y"));
	tableModel->setHorizontalHeaderLabels(headerNames);
}

void EntityDialog::update()
{
	int i = 0;
	for each (Node* seedNode in entity->getSeeds())
	{
		QStandardItem *rowx = new QStandardItem(QString::number(seedNode->x));
		QStandardItem *rowy = new QStandardItem(QString::number(seedNode->y));

		tableModel->setItem(i, 0, rowx);
		tableModel->setItem(i, 1, rowy);

		++i;
	}
}

void EntityDialog::accept()
{
	apply();

	this->hide();
}
void EntityDialog::apply()
{
	std::cout << "ACCEPTED pressed" << std::endl;

	double precision = 0.00001;
	bool updateRequired = false;

	std::vector<Node*> seedNodes = entity->getSeeds();
	for (int i = 0; i < tableModel->rowCount(); i++)
	{
		Node* seedNode = seedNodes[i];

		double x = tableCellToDouble(i, 0);
		double y = tableCellToDouble(i, 1);

		std::cout << "[X,x,X-x], [Y,y,Y-y]: [" << x << " - " << seedNode->x << " = " << abs(x - seedNode->x) << "],  [" << y << " - " << seedNode->y  << " = " << abs(y - seedNode->y) << "] "<< std::endl;

		if(abs(seedNode->x - x) > precision || abs(seedNode->y - y) > precision)
		{
			std::cout << "Found change in node table" << std::endl; 

			seedNode->x = x; 
			seedNode->y = y;
			updateRequired = true;
		}
	}
	if (entity->type == Entity::CIRCLE)
	{
		dynamic_cast<EntityCircle*>(entity)->segmentNum = ui.segmentSpinBox->value();
		updateRequired = true;
	}

	if(updateRequired)
	{
		entity->doneEditing();
	}
}
void EntityDialog::reject()
{
	std::cout << "REJECT pressed" << std::endl;
	this->hide();
}

double EntityDialog::tableCellToDouble(int row, int col)
{
	QStandardItem *cellItem = tableModel->item(row, col);
	return cellItem->text().toDouble();
}