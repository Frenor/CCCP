#pragma once
#ifndef CMODEL_H
#define CMODEL_H

#include <qobject.h>
#include <QFile.h>

#include "DrawModel.h"
#include "ResultModel.h"
#include "GeoExport.h"
#include "MSHParser.h"
#include "ExternalProcessHandler.h"

#include "TestLib.h"
//! The main model used in the application
/*
	It coordinates external processes on UI mode changes, as well as import and export of data.
	It also holds application settings and references the to two data models; DrawModel and ResultModel. 
*/
class TEST_LIB CModel : public QObject
{
	Q_OBJECT
public:
	CModel(QObject *parent = 0);
	CModel::~CModel() {}

	static const int DRAWMODE = 0;
	static const int MESHMODE = 1;
	static const int RESULTMODE = 2;

	QString fileName;		//!< Current fileName opened
	QString tmpPath;

	DrawModel *drawModel;		//!< Data model for drawing and storing entities
	ResultModel *resultModel;	//!< Data model holding mesh and result data.

	bool meshOutOfSync;			//!< The validity of the mesh. False whenever changes are done to entities after meshing
	bool resultOutOfSync;
	/*!
		\return integer representing the current UI mode
	*/
	int getActiveUIMode();
	/*!
		Sets the current UI mode and emits signal based on the given UI mode.
	*/
	void setUIMode(int);
	/*!
		Deletes the data models and creates new ones.
	*/
	void reset();

	/*!
		Creates an instance of GeoExport which saves the geometry data in drawModel to a file
	*/
	void exportDataModel(QString);

	/*!
		Creates a QStringList based on the mesh settings configured in text boxes, in the UI.
		\return QStringList with arguments to be passed to the mesh application
	*/
	QStringList getMeshOptions();

	/*!
		Sets the model's minimum element size for meshing
	*/
	void setMinElementSize(QString);
	/*!
		Sets the model's maximum element size for meshing
	*/
	void setMaxElementSize(QString);
	/*!
		Sets the model's custom arguments used in meshing
	*/
	void setCustomArguments(QString);

	/*!
		\return QString Minimum element size used in meshing
	*/
	QString getMinElementSize();
	/*!
		\return QString Maximum element size used in meshing
	*/
	QString getMaxElementSize();
	
public slots:
	/*!
		Connects the data model signals to this model.
	*/
	void setDataModelListeners();
	
	/*!
		Set the mesh state to out of sync with the geometry. 
		This function is called whenever an entity is added, changed or deleted from the draw model.
	*/
	void setMeshOutOfSync();
	/*!
		Set the result state to out of sync with the mesh. 
		This function is called whenever a new mesh is loaded or genereated.
	*/
	void setResultOutOfSync();

	/*!
		Starts the meshing. It creates an external process manager to controll the mesh process 
		and exports the draw data model to a temporary file "tmp/tmp_file.geo".
		The external process handler monitors the external process and emits a signal when it is done.
	*/
	void executeMeshProcess();
	/*!
		Starts the solver. It creates an external process manager to controll the solver process 
		and passes the mesh file name to the solver.
		The external process handler monitors the external process and emits a signal when it is done.
	*/
	void executeSolveProcess();

	/*!
		Moves a file from a path to the temporary folder with the given file type ending
	*/
	void moveToTemporaryFolder(QString filename, QString tmpFileEnding);
	/*!
		Opens and loads a mesh file using MSHParser.
		The parser is set as a mesh data source in the result model.
	*/
	void openMSHFile(QString);

	/*!
		Opens and loads a result file using a VTKParser.
		The data is set as a result data soure in the result model.
	*/
	void openVTKFile(QString);

	/*!
		Sets the mesh to outofsync and reverts the mesh options to default values defined in this function.

		Default values are:
			MinElement: 0,
			MaxElement: 1e+22
	*/
	void resetMeshOptions();

	void activeEntityChanged(Entity *activeEntity);

signals:
	void newDrawModel(DrawModel *);			//!< Emitted when a new draw model is created
	void drawMode();						//!< Emitted when the UI mode is changed to draw mode
	void meshMode();						//!< Emitted when the UI mode is changed to mesh mode
	void resultMode();						//!< Emitted when the UI mode is changed to result mode
	void uiModeChanged();					//!< Emitted whenever the UI mode is changed
	void massiveEntitySelected(bool);		//!< Signal emitted when a massive crossection is selected (clicked).
	void thinwalledEntitySelected(bool);	//!< Signal emitted when a thin walled crossection is selected (clicked).
private:
	int activeMode;		//!< Reference to the current active UI mode
	
	QString minElementSize;			//!< Minimum element mesh size
	QString maxElementSize;			//!< Maximum element mesh size
	QStringList customArguments;	//!< Custom mesh arguments

	void createDataModels();		//!< Creates a new draw model and result model
};
#endif //CMODEL_H