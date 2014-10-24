#include <iostream>

#include <qobject.h>
#include <qprocess.h>

//! External process handler. It is extraced from CModel to make the process execution clearer.
/*!
	It was originally planned to keep track of file names used for data exchange between processes.
	It is one of the last properties implemented, and would probably benefit from some refactoring..
*/
class ExternalProcessHandler : public QObject
{
	Q_OBJECT
public:
	ExternalProcessHandler(QObject *parent);
	
	void setMeshProcessName(QString);
	void setSolveProcessName(QString);
	void setWorkDir(QString);
	void setAdditionalArguments(QStringList);

	/*!
		Adds arguments necessary to run the mesher and starts the process.
		It also connects a process callback in this class, emitted when the process is done.
	*/
	void execMesh();
	/*!
		Adds arguments necessary to run the solver and starts the process.
		It also connects a process callback in this class, emitted when the process is done.
	*/
	void execSolve();

public slots:
	void meshFinished();
	void solveFinished();

signals:
	void finished(QString);

private:
	QString meshProgram;
	QString solveProgram;

	QString workPath; 
	QStringList additionalArguments;

	QProcess *meshProcess;
	QProcess *solveProcess;
};