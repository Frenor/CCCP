#pragma once
#ifndef DRAWCONTROLLER_H
#define DRAWCONTROLLER_H

#include "GraphicController.h"
#include "VTKControlledSeedWidget.h"
#include "DrawViewMenu.h"
#include "DrawModel.h"

//SeedModel---
#include "vtkSeedRepresentation.h"
#include "vtkPointHandleRepresentation3D.h"
#include "vtkLine.h"
#include "Node.h"

#include "TestLib.h"

//! A controller changing the style of GraphicsView, and lets the user draw shapes to the program. 
/*!	
	It sets up Graphicsview to use 2D, and adds a seedWidget to the GraphicsView
*/
class TEST_LIB DrawController : public GraphicController
{
	Q_OBJECT
public:
	DrawController(DrawModel*, QWidget *, QObject *parent = 0);
	~DrawController(){ std::cout << "DELETED: DrawController" << std::endl; }

	DrawModel* model;

	/*!
		Connect the view to this controller, 
		so the controller can handle the neccessary user interactions applied to the view.
	*/
	void connectView();
	/*!
		Resets the GraphicsView and draws lines, points and surfaces.
	*/
	void invalidate();
	/*!
		Draws all the nodes and edges present in the draw model.
	*/
	void drawPointsAndLines(std::vector<Node*>, std::vector<Edge*>);

	/*!
		Updates the seed widget interaction mode. 
		Used when a new entity is selected to Enable/disable "add seed" feature.
		Enabled if entity is selected, and the entity is closed. Otherwise disabled.
	*/
	void updateInteraction(Entity*);

	/*!
		Create surfaces for all closed entities in draw model.
	*/
	void drawSurfaces();
	/*!
		Create and add a surface actor given an entity. 
		It also handles the color and visibility of entities, given their state. (Active, regular, hole or invisible)
	*/
	void createSurface(Entity *);

public slots:
	/*!
		Updates the callback for the seedwidget, and update the seedwidgets interaction mode.
		Then the view is reset.
	*/
	void setActiveEntity(Entity*);
	/*!
		Invalidates the view and sets the seed widgets data model to the selected entity if the active entity is not finalized.
	*/
	void reset();
	/*!
		Sets the active draw model used to draw entities, and connects the model to the controller.
	*/
	void setModel(DrawModel *DrawModel);
	/*!
		Done event will cause the view to finalized the active entity. 
		Finalizing the active entity will close it if not closed and remove the seeds from the view.
	*/
	void doneEvent();
	/*!
		Deletes the active entity
	*/
	void cancelEvent();
	/*!
		Find the active entity based on the actor selected.
	*/
	void actorClicked(vtkSmartPointer<vtkActor>);
	/*!
		Find the active entity based on the actor selected, and unfinalizes it. 
		The seeds are then shown in the seed widget, and the entity is editable.
	*/
	void actorDoubleClicked(vtkSmartPointer<vtkActor>);

private:
	vtkSmartPointer<vtkSeedCallback> scbk;							//!< Seed call back class handling interactions with the seed widget
	vtkSmartPointer<VTKControlledSeedWidget> widget;				//!< The seed widget displayed in the overlay
	vtkSmartPointer<vtkSeedRepresentation> seedRep;					//!< Seed representation. The seeds
	vtkSmartPointer<vtkPointHandleRepresentation3D> handleRep;		//!< The actual seed symbol and its visual properties

	/*!
		Creates the seed widget and configures the visual look of the seeds.
		The widget is fragile, and the order of which the widget is added to the graphicsview make a big deal.
	*/
	void startSeedWidget();

	/*!
		Predefined visual style for a selected entity
	*/
	void setColorSelected(vtkSmartPointer<vtkActor>);
	/*!
		Predefined visual style for a regular entity
	*/
	void setColorDone(vtkSmartPointer<vtkActor>);
	/*!
		Predefined visual style for a hole-entity, making it appear as the programs background
	*/
	void setColorBackground(vtkSmartPointer<vtkActor>);
	
	/*!
		Loops through the entities comparing its actor to the one given.
		\return Entity represented by the given actor
	*/
	Entity* findEntityBasedOnActor(vtkSmartPointer<vtkActor>);
};
#endif //DRAWCONTROLLER_H