#include "ExternalProcessHandler.h"

ExternalProcessHandler::ExternalProcessHandler(QObject *parent) : QObject(parent)
{

}

void ExternalProcessHandler::setMeshProcessName(QString program)
{
	this->meshProgram = program;
}

void ExternalProcessHandler::setSolveProcessName(QString program)
{
	this->solveProgram = program;
}

void ExternalProcessHandler::setWorkDir(QString tmpPath)
{
	this->workPath = tmpPath;
}

void ExternalProcessHandler::setAdditionalArguments(QStringList meshOptions)
{
	this->additionalArguments = meshOptions;
}

void ExternalProcessHandler::execMesh()
{
	std::cout << "Execute Meshing" << std::endl;
	meshProcess = new QProcess(this);
	connect(meshProcess, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(meshFinished()));

	QStringList arguments;
	arguments << "-o";
	arguments << workPath + "tmp_file.msh";
	arguments << "-2";
	arguments << additionalArguments;
	arguments << workPath + "tmp_file.geo";
	meshProcess->start(meshProgram, arguments);
}

void ExternalProcessHandler::execSolve()
{
	std::cout << "Execute Solving" << std::endl;
	solveProcess = new QProcess(this);
	connect(solveProcess, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(solveFinished()));

	QStringList arguments;
	arguments << "-f";
	arguments << workPath + "tmp_file";
	solveProcess->start(solveProgram, arguments);
}

void ExternalProcessHandler::meshFinished()
{
	std::cout << "Mesh Process Finished" << std::endl;
	
	QString outFile = workPath + "tmp_file.msh";
	emit finished(outFile);
	meshProcess->kill();
	
	delete this;
}

void ExternalProcessHandler::solveFinished()
{
	std::cout << "Solve Process Finished" << std::endl;
	
	QString outFile = workPath + "tmp_file.vtk";
	emit finished(outFile);
	solveProcess->kill();

	delete this;
}