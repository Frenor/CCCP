#pragma once
#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <vector>

#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkSmartPointer.h>
#include <vtkCellArray.h>
#include <vtkInteractorStyleImage.h>

#include <QVTKWidget.h>
#include <vtkProperty.h>
#include <vtkPropPicker.h>
#include <vtkCamera.h>

#include "Node.h"
#include "Element.h"

#include "TestLib.h"
//! A wrapper for the VTK, providing the graphics and is represents the blue field viewed in the UI.
/*!
	It extends QVTKWidget to ease control of 2D and 3D view mode and to better handle the actors.
	Its responsebility is limited to handle active actors and set up view modes like interaction style and perspective.
	GraphicsView is only a view controlled by two very different graphic controllers; DrawController and ResultController. 
	This approach of only swapping controllers lets the program switch modes without reinitialize VTK on every mode change. 
*/
class TEST_LIB GraphicsView : public QVTKWidget
{
	Q_OBJECT
public:
	explicit GraphicsView(QWidget *parent);
	~GraphicsView(){ std::cout << "DELETED: GraphicsView" << std::endl; }

	double pos[2];		//!< Position for last click. Used to separate a double click from a regular mouse click
	vtkSmartPointer<vtkRenderer> renderer;	//!< Renderer used to display all entities and results

	vtkSmartPointer<vtkCamera> cam2D;	//!< Camera configured without perspective
	vtkSmartPointer<vtkCamera> cam3D;	//!< Camera with perspective

	std::vector<vtkSmartPointer<vtkActor>> actors;	//!< All actors active in the GraphicsView
	
	/*!
		Configures the interactor style to use an image interactor style, which removes the rotation capabilities.
		It also adds listeners for clicks and context menus to the graphics view.
	*/
	void set2DInteractor();
	/*!
		Sets the interactor style to trackball camera. The default interactor style.
	*/
	void resetInteractor();

	/*!
		Adds the given renderer to the renderWindow and updates the widget
	*/
	void addRenderer(vtkSmartPointer<vtkRenderer>);
	/*!
		Removes the given renderer from the renderWindow and updates the widget
	*/
	void removeRenderer(vtkSmartPointer<vtkRenderer>);

	/*!
		Sets the number of layers/renderers possible in the renderWindow 
		and creates a backgroundrenderer on layer 0.
		The background is set to a weak gradient of blue. (Default is black)
	*/
	void createBackground();
	/*!
		Creates the renderer used for presentation and assigns it to layer 1
		(Background layer is 0)

		\return vtkSmartPointer<vtkRenderer> Renderer to render entity- and result actors.
	*/
	vtkSmartPointer<vtkRenderer> createRenderer();

	/*!
		Function loops through all actors and removes them from the view.
	*/
	void removeActors();
	/*!
		Adds the given actor to the view and the vector containing all active actors.
	*/
	void addActor(vtkSmartPointer<vtkActor> actor);
	
	/*!
		Sets the renderers active camera to a camera configured without perspective.
		This is necessary in order to the depth separation of entities and seeds to work.
	*/
	void set2DMode();
	/*!
		Sets the renderers active camera to a regular camera.
	*/
	void set3DMode();

	/*!
		Click callback for mouse clicks done inside the render window.
		A prop picker is used to check wether an entity actor was clicked given the event position.

		Double clicks are implemented by comparing the position of the last with a new. If the distance is less than 0.001, it is a double click.
	*/
	void clickCallback();
	/*!
		Context menu callback for mouse clicks done inside the render window.
		A prop picker is used to check wether an entity actor was clicked given the event position.

		The interactor uses a coordinate system with origo placed in the upper left corner, unlike the contextmenu which uses the bottom left. 
		This means the y-axes is swapped before it is passed on to draw the context menu.
	*/
	void contextMenuCallback();

public slots:
	/*!
		Creates a cancel/delete signal based on a keyboard shortcut signal
	*/
	void escapePressed();
	/*!
		Creates a "done" signal based on a keyboard shortcut signal
	*/
	void enterPressed();
	
	/*!
		Removes all actors and updates the widget
	*/
	void reset();

	/*!
		Updates the widget
	*/
	void invalidate();
	
signals:
	void doneEvent();		//!< Closes active entity
	void cancelEvent();		//!< Deletes active entity/unfinished entity
	void actorClicked(vtkSmartPointer<vtkActor>);	
	void actorDoubleClicked(vtkSmartPointer<vtkActor>);
};

#endif //GRAPHICSVIEW_H