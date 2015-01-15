#include "CModel.h"

CModel::CModel(QObject *parent) : QObject(parent)
{
	meshOutOfSync = false;
	resultOutOfSync = false;
	tmpPath = "tmp/";

	connect(this, &CModel::newDrawModel, this, &CModel::setDataModelListeners);
	createDataModels();

	connect(this, SIGNAL(meshMode()), this, SLOT(executeMeshProcess()));
	connect(this, SIGNAL(resultMode()), this, SLOT(executeSolveProcess()));
	connect(this, SIGNAL(meshMode()), resultModel, SLOT(hideScalarBar()));
	connect(this, SIGNAL(resultMode()), resultModel, SLOT(showScalarBar()));
	connect(drawModel, SIGNAL(activeEntityChanged(Entity*)), this, SLOT(activeEntityChanged(Entity*)));

	resetMeshOptions();
}

void CModel::createDataModels()
{
	this->drawModel = new DrawModel(this);
	this->resultModel = new ResultModel(this);

	emit newDrawModel(this->drawModel);
}

void CModel::setMeshOutOfSync()
{
	meshOutOfSync = true;
}

void CModel::setResultOutOfSync()
{
	resultOutOfSync = true;
}

void CModel::setDataModelListeners()
{
	connect(this, SIGNAL(uiModeChanged()), this->drawModel, SLOT(uiModeChanged()));

	connect(this->drawModel, SIGNAL(entityChanged(Entity*)), this, SLOT(setMeshOutOfSync()));
	connect(this->drawModel, SIGNAL(entityCreated(Entity*)), this, SLOT(setMeshOutOfSync()));
	connect(this->drawModel, SIGNAL(entityDeleted(Entity*)), this, SLOT(setMeshOutOfSync()));
	connect(this, SIGNAL(drawMode()), this, SLOT(setMeshOutOfSync()));
}

void CModel::setUIMode(int mode)
{
	switch(mode)
	{
	case CModel::DRAWMODE:
		std::cout << "ModelMode" << std::endl;
		emit drawMode();
		break;
	case CModel::MESHMODE:
		std::cout << "MeshMode" << std::endl;
		emit meshMode();
		break;
	case CModel::RESULTMODE:
		std::cout << "ResultMode" << std::endl;
		emit resultMode();
		break;
	}

	emit uiModeChanged();
	this->activeMode = mode;
}

int CModel::getActiveUIMode()
{
	return activeMode;
}

void CModel::executeMeshProcess()
{
	if(meshOutOfSync)
	{
		exportDataModel(tmpPath + "tmp_file");

		ExternalProcessHandler *eProc = new ExternalProcessHandler(this);
		connect(eProc, SIGNAL(finished(QString)), this, SLOT(openMSHFile(QString)));

		eProc->setMeshProcessName("gmsh");
		eProc->setWorkDir(tmpPath);
		eProc->setAdditionalArguments(getMeshOptions());
		eProc->execMesh();

		meshOutOfSync = false;
	}
}

void CModel::executeSolveProcess()
{
	if(resultModel->hasMeshData() && resultOutOfSync)
	{
		ExternalProcessHandler *eProc = new ExternalProcessHandler(this);
		connect(eProc, SIGNAL(finished(QString)), this, SLOT(openVTKFile(QString)));

		eProc->setSolveProcessName("solver");
		eProc->setWorkDir(tmpPath);
		eProc->execSolve();

		resultOutOfSync = false;
	}
}

void CModel::moveToTemporaryFolder(QString filename, QString tmpFileEnding)
{
	QFile::remove(tmpPath + "tmp_file" + tmpFileEnding);
	QFile::copy(filename, tmpPath + "tmp_file" + tmpFileEnding);
}

void CModel::exportDataModel(QString fileName)
{
	GeoExport geoFileExport(fileName.toStdString() + ".geo", this->drawModel);
	geoFileExport.write();
	geoFileExport.save();

	DatExport datFileExport(fileName.toStdString() + ".dat", this->drawModel);
	datFileExport.write();
	datFileExport.save();

	this->fileName = fileName;
}

void CModel::openMSHFile(QString fileName)
{
	meshOutOfSync = false;
	setUIMode(CModel::MESHMODE);

	MSHParser *meshParser = new MSHParser(this, fileName.toStdString());
	resultModel->setDataSource(meshParser);

	this->fileName = fileName;

	setResultOutOfSync();
}

void CModel::openVTKFile(QString fileName)
{
	resultOutOfSync = false;
	setUIMode(CModel::RESULTMODE);

	VTKParser *vtkParser = new VTKParser(fileName.toStdString(), this);
	resultModel->setDataSource(vtkParser);

	this->fileName = fileName;
	setResultOutOfSync();

	delete vtkParser;
}

void CModel::reset()
{
	delete this->drawModel;
	createDataModels();

	setUIMode(CModel::DRAWMODE);
}

void CModel::resetMeshOptions()
{
	minElementSize = "0";
	maxElementSize = "1e+22";

	setMeshOutOfSync();
}

QStringList CModel::getMeshOptions()
{
	QStringList meshOptions;
	if(minElementSize != "0")
	{	
		meshOptions << "-clmin";
		meshOptions << minElementSize;
	}

	if(maxElementSize != "1e+22")
	{
		meshOptions << "-clmax";
		meshOptions << maxElementSize;
	}

	meshOptions << customArguments;

	return meshOptions;
}

void CModel::setMinElementSize(QString minElementSize)
{
	this->minElementSize = minElementSize;
	setMeshOutOfSync();
}
void CModel::setMaxElementSize(QString maxElementSize)
{
	this->maxElementSize = maxElementSize;
	setMeshOutOfSync();
}
void CModel::setCustomArguments(QString customArgs)
{
	customArgs = customArgs.trimmed();

	if(customArgs.size() > 0)
	{
		this->customArguments = customArgs.split(" ");
	}
	setMeshOutOfSync();
}

QString CModel::getMinElementSize()
{
	return minElementSize;
}

QString CModel::getMaxElementSize()
{
	return maxElementSize;
}

void CModel::activeEntityChanged(Entity *activeEntity) 
{
	if (activeEntity != NULL) {
		switch (activeEntity->crossectionType)
		{
		case Entity::MASSIVE:
			emit massiveEntitySelected(true);
			break;
		case Entity::THINWALLED:
			emit thinwalledEntitySelected(true);
			break;
		default:
			break;
		}
	}
}