#pragma once

#include "vtkSmartPointer.h"
#include "vtkActor.h"
#include "DrawModel.h"
#include "GraphicsView.h"

//!	An abstract class for controllers, used mostly as an interface for DrawController and ResultController. 
class GraphicController : public QObject
{
	Q_OBJECT 
public:
	/*!
		Resets the GraphicView when a new controller is created
	*/
	GraphicController(QWidget* view, QObject *parent) : QObject(parent)
	{
		gView = (GraphicsView*)view;
		gView->reset();
	}

	GraphicsView *gView;

	virtual void actorClicked(vtkSmartPointer<vtkActor>) = 0;
	virtual void actorDoubleClicked(vtkSmartPointer<vtkActor>) = 0;

};
