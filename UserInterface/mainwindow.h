#pragma once 

#include <QFileDialog>
#include <QFileSystemModel>
#include <QtWidgets/QMainWindow>
#include <qstandarditemmodel.h>
#include <vtksys\SystemTools.hxx>

#include "ui_mainwindow.h"

#include "MSHParser.h"
#include "VTKParser.h"

#include "CModel.h"
#include "ResultModel.h"

#include "ShortcutManager.h"
#include "GraphicsView.h"
#include "DrawController.h"
#include "ResultController.h"

#include "TestLib.h"

//! A controller for the window, and handles the initialization of views and other controllers
/*!
	This class controls which widgets that are being displayed and handles most of the signals from the UI.
*/
class TEST_LIB MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow(){ removeActiveGraphicView(); std::cout << "DELETED: MainWindow" << std::endl; }

	CModel *cModel;						//!< Main model. Handles IO operations and contains drawModel and resultModel.
	GraphicController* gController;		//!< Current active controller for VTK/GraphicsView

public slots:
	/*!
		Calls createEntity in drawModel given a UI signal
	*/
	void addPolygon();
	/*!
		Calls createEntityCircle in drawModel given a UI signal
	*/
	void addCircle();
	/*!
		Calls deleteActiveEntity in drawModel given a UI signal
	*/
	void deleteEntity();
	/*!
		Opens the file dialog box for opening files. 
		It evaluates the file extension and opens the file in the model.

		Extensions supported: 
		".msh" - Mesh file
		".vtk" - VTK file (Results)
	*/
	void openFile();
	/*!
		Opens a file dialog for saving geometry files. 
		Only ".geo" files are supported.
		ExportDataModel is called on the model, which writes the data.
	*/
	void saveFile();
	/*!
		Resets the models and redraws the active view
	*/
	void newFile();

	/*!
		Sets the mode in the model given a UI signal from the tabWidget
	*/
	void setMode(int);

	/*!
		Sets the model to drawMode given an UI signal
	*/
	void setDrawMode();

	/*!
		Sets the model to meshMode given an UI signal
	*/
	void setMeshMode();
	/*!
		Sets the model to resultMode given an UI signal
	*/
	void setResultMode();

	/*!
		ShowDrawController hides the resultWidget and shows the paintWidget, 
		and set the active tab to draw.

		It also removes the active GraphicsController and adds a DrawController -if its not a DrawController.
		(GraphicsController is not to be confused with GraphicsView, which never is removed from the window) 
	*/
	void showDrawController();
	
	/*!
		ShowMeshView hides the paintWidget and shows the resultWidget, 
		and set the active tab to mesh.

		It also removes the active GraphicsController and adds a ResultController -if its not a ResultController.
		(GraphicsController is not to be confused with GraphicsView, which never is removed from the window) 
	*/
	void showMeshView();

	/*!
		ShowMeshView hides the paintWidget and shows the resultWidget, 
		and set the active tab to results.

		It also removes the active GraphicsController and adds a ResultController -if its not a ResultController.
		(GraphicsController is not to be confused with GraphicsView, which never is removed from the window) 
	*/
	void showResultController();

	/*!
		Signal from "Mesh Tab"
		Sets the model's minimum element size used for meshing given an UI signal.
	*/
	void setMinElementSize();
	/*!
		Signal from "Mesh Tab"
		Sets the model's maximum element size used for meshing given an UI signal.
	*/
	void setMaxElementSize();
	/*!
		Signal from "Mesh Tab"
		Sets the model's custom arguments that are passed to the mesher.
	*/
	void setCustomArguments();
	/*!
		Signal from "Mesh Tab"
		Resets the model's mesh options and reloads the UI mesh elements given an UI signal.
	*/
	void resetMeshOptions();

	/*!
		Signal from "Result Tab"
		Sets the model's visibility status for mesh and refreshes the ResultController.
	*/
	void setMeshVisible(bool);
	/*!
		Signal from "Result Tab"
		Sets the model's visibility status for results and refreshes the ResultController.
	*/	
	void setResultVisible(bool);
	/*!
		Signal from "Draw Tab"
		Sets the drawing type to thin walled mode
	*/
	void setDrawTypeThin(bool);
	/*!
	Signal from "Draw Tab"
	Sets the drawing type to filled crossection mode
	*/
	void setDrawTypeMassive(bool);
signals:
	/*!
		Signal emitted when setMeshVisible is called by the UI.
	*/
	void meshVisible(bool);
	/*!
		Signal emitted when setResultVisible is called by the UI.
	*/
	void resultVisible(bool);
	/*!
		Signal emitted when setDrawTypeThin is called by the UI.
	*/
	void drawTypeThin();
	/*!
	Signal emitted when setDrawTypeFilled is called by the UI.
	*/
	void drawTypeMassive();

private:
	Ui::MainWindowClass ui;
	/*!
		Sets the active tab to draw, and shows draw mode.
	*/
	void setupGraphicsView();

	/*!
		Deletes the current GraphicController, if it exists.
	*/
	void removeActiveGraphicView();

	/*!
		Creates a draw controller and sets it as the current controller for GraphicsView.
	*/
	void addPaintView();
	/*!
		Creates a result controller and sets it as the current controller for GraphicsView.
	*/
	void addResultController();
};

