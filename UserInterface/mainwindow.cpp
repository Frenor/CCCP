#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	gController = NULL;

	this->cModel = new CModel;
	connect(cModel, SIGNAL(drawMode()), this, SLOT(showDrawController()));
	connect(cModel, SIGNAL(meshMode()), this, SLOT(showMeshView()));
	connect(cModel, SIGNAL(resultMode()), this, SLOT(showResultController()));
	connect(cModel, SIGNAL(massiveEntitySelected(bool)), this, SLOT(massiveEntitySelectedSlot(bool)));
	connect(cModel, SIGNAL(thinwalledEntitySelected(bool)), this, SLOT(thinwalledEntitySelectedSlot(bool)));

	ui.leftWidgetPaint->setModel(cModel->drawModel);
	ui.leftWidgetResult->setModel(cModel->resultModel);
	
	ShortcutManager::setMainWindow(this);
	setupGraphicsView();
}

void MainWindow::setupGraphicsView()
{
	ShortcutManager::setWidget(ui.GraphicsWidget);
	setDrawMode();
}

void MainWindow::openFile()
{
	cModel->fileName = QFileDialog::getOpenFileName(this, tr("Open file"),"",tr("Files (*.*)"));
	std::string extension = vtksys::SystemTools::GetFilenameLastExtension(cModel->fileName.toStdString());

	if (extension == ".msh")
	{
		cModel->openMSHFile(cModel->fileName);
		cModel->moveToTemporaryFolder(cModel->fileName, QString::fromStdString(extension));
	}
	else if (extension == ".vtk")
	{
		cModel->openVTKFile(cModel->fileName);		
	}
}
void MainWindow::saveFile()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"),"",tr("Files (*.*)"));
	cModel->exportDataModel(fileName);
}
void MainWindow::newFile()
{
	cModel->reset();
}

void MainWindow::addPolygon()
{
	cModel->drawModel->createEntityPolygon();
}
void MainWindow::addCircle()
{
	cModel->drawModel->createEntityCircle();
}
void MainWindow::deleteEntity()
{
	cModel->drawModel->deleteActiveEntity();
}

void MainWindow::setMode(int mode)
{
	cModel->setUIMode(mode);
}
void MainWindow::setDrawMode()
{
	cModel->setUIMode(CModel::DRAWMODE);
}
void MainWindow::setMeshMode()
{
	cModel->setUIMode(CModel::MESHMODE);
}
void MainWindow::setResultMode()
{
	cModel->setUIMode(CModel::RESULTMODE);
}

void MainWindow::showDrawController()
{
	ui.leftWidgetPaint->show();
	ui.leftWidgetResult->hide();

	ui.tabWidget->setCurrentWidget(ui.drawTab);

	std::cout << "add DrawController" << std::endl;
	if(cModel->getActiveUIMode() != CModel::DRAWMODE){
		removeActiveGraphicView();
		addPaintView();
	}
}
void MainWindow::showMeshView()
{
	ui.leftWidgetPaint->hide();
	ui.leftWidgetResult->hide();

	ui.tabWidget->setCurrentWidget(ui.meshTab);

	std::cout << "add meshView" << std::endl;
	if(cModel->getActiveUIMode() == CModel::DRAWMODE){
		removeActiveGraphicView();
		addResultController();
	}

	setResultVisible(false);
	setMeshVisible(true);
}
void MainWindow::showResultController()
{
	ui.leftWidgetResult->show();
	ui.leftWidgetPaint->hide();

	ui.tabWidget->setCurrentWidget(ui.resultsTab);

	std::cout << "add ResultController: " << cModel->getActiveUIMode() << std::endl;
	if(cModel->getActiveUIMode() == CModel::DRAWMODE){
		removeActiveGraphicView();
		addResultController();
	}

	setResultVisible(true);
	setMeshVisible(true);
}

void MainWindow::addPaintView()
{
	gController = new DrawController(this->cModel->drawModel, ui.GraphicsWidget);
	connect(this->cModel, &CModel::newDrawModel, (DrawController*)gController, &DrawController::setModel);
}

void MainWindow::addResultController()
{
	gController = new ResultController(this->cModel->resultModel, ui.GraphicsWidget);
}

void MainWindow::removeActiveGraphicView()
{
	if(gController)
	{
		delete gController;
	}
	ui.GraphicsWidget->resetInteractor();
}

void MainWindow::setMinElementSize()
{
	cModel->setMinElementSize(ui.minElementSize->text());
}
void MainWindow::setMaxElementSize()
{
	cModel->setMaxElementSize(ui.maxElementSize->text());
}
void MainWindow::setCustomArguments()
{
	cModel->setCustomArguments(ui.customArgs->text());
}
void MainWindow::resetMeshOptions()
{
	cModel->resetMeshOptions();
	ui.minElementSize->setText(cModel->getMinElementSize());
	ui.maxElementSize->setText(cModel->getMaxElementSize());
}

void MainWindow::setMeshVisible(bool visible)
{
	cModel->resultModel->setMeshVisible(visible);
	emit meshVisible(visible);
}
void MainWindow::setResultVisible(bool visible)
{
	cModel->resultModel->setResultVisible(visible);
	emit resultVisible(visible);
}
void MainWindow::setDrawTypeThin(bool enable)
{
	if (enable)
	{
		cModel->drawModel->setDrawType(Entity::THINWALLED);
		emit drawTypeThin();
	}
}
void MainWindow::setDrawTypeMassive(bool enable)
{
	if (enable)
	{
		cModel->drawModel->setDrawType(Entity::MASSIVE);
		emit drawTypeMassive();
	}
}
void MainWindow::massiveEntitySelectedSlot(bool selected)
{
	emit massiveEntitySelectedSig(selected);
}
void MainWindow::thinwalledEntitySelectedSlot(bool selected)
{
	emit thinwalledEntitySelectedSig(selected);
}