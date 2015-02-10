#pragma once
#ifndef VTKCONTROLLEDSEEDWIDGET_H
#define VTKCONTROLLEDSEEDWIDGET_H

#include "vtkSeedWidget.h"
#include "vtkHandleWidget.h"

#include "vtkRenderWindowInteractor.h"
#include "vtkWidgetEventTranslator.h"
#include "vtkCommand.h"
#include "vtkWidgetCallbackMapper.h"
#include "vtkWidgetEvent.h"
#include "vtkObjectFactory.h"
#include "vtkCallbackCommand.h"
#include "vtkEvent.h"

#include "vtkSeedRepresentation.h"
#include "vtkWidgetRepresentation.h"
#include "vtkHandleRepresentation.h"
#include "DrawModel.h"

#include "TestLib.h"

//!	Callback for seed widget. Handles creation of new seeds and seed interaction
class TEST_LIB vtkSeedCallback : public vtkCommand
{
public:
	static vtkSeedCallback *New() {	return new vtkSeedCallback;	}

	vtkSeedCallback() {	std::cout << "CREATED: vtkSeedCallback" << std::endl; }
	~vtkSeedCallback() { std::cout << "DELETED: vtkSeedCallback" << std::endl; }
	
	/*!
		Creates or changes a seed if interaction occurs.
		All seeds(nodes) added to entity is given an id based on the number the seed har in the widget.
		It is used to keep track of which node is being manipulated.
	*/
	virtual void Execute(vtkObject*, unsigned long event, void *calldata)
	{
		double pos[3];
		if (event == vtkCommand::PlacePointEvent)
		{
		//	std::cout << "Point placed, total of: " << this->SeedRepresentation->GetNumberOfSeeds() << "OR" << this->SeedRepresentation->GetActiveHandle() << std::endl;

			if(this->entity)
			{
				this->SeedRepresentation->GetHandleRepresentation(this->SeedRepresentation->GetActiveHandle())->GetWorldPosition(pos);
				Node *snapTo = model->findCloseNode(pos);
				if (snapTo)
				{
					this->entity->useSnapNode(snapTo, this->SeedRepresentation->GetActiveHandle());
				}
				else
				{
					this->entity->createNode(pos, this->SeedRepresentation->GetActiveHandle());
				}
			}
		}
		if (event == vtkCommand::InteractionEvent)	
		{
			if(calldata && calldata >= 0)
			{
				int handle = this->SeedRepresentation->GetActiveHandle();

				this->SeedRepresentation->GetHandleRepresentation(handle)->GetWorldPosition(pos);
				//std::cout << "Interacting with seed : " << handle << ", Pos: " << pos[0] << " , " << pos[1] << " , " << pos[2] << std::endl;

				if (handle >= 0)
				{
					this->entity->changeNode(pos, handle);
				}
			}
		}

		if (event == vtkCommand::DeleteEvent)
		{
			std::cout << "DeleteEvent" << std::endl;
		}
	}
	/*!
		Sets the entity the callback is doing work on.
	*/
	void setEntity(Entity *entity) { this->entity = entity;	}

	void setModel(DrawModel *model) { this->model = model; }

	void SetRepresentation(vtkSmartPointer<vtkSeedRepresentation> rep) { this->SeedRepresentation = rep; }
private:
	vtkSmartPointer<vtkSeedRepresentation> SeedRepresentation;
	Entity *entity;
	DrawModel *model;
};

//! Wrapper for the vtkSeedWidget, providing extended control of the seed widget.
/*!
	This class provides an interface to control if seed creation is enabled, or if only changing seeds are allowed.
	vtkSeedWidget, the class it extends, adds a set of forced interactions in the constructor. 
	The program relies heavily on the ability to enable/disable these interactions on the go, and vtkSeedWidget did not fulfill these needs in its current state.
*/
class TEST_LIB VTKControlledSeedWidget : public vtkSeedWidget
{
public:
	static VTKControlledSeedWidget *New();
	vtkTypeMacro(VTKControlledSeedWidget, vtkSeedWidget);

	void setEnableAddInteraction(bool);
	void setStartInteraction();
	void setCallback(vtkSmartPointer<vtkSeedCallback> scbk);
	void AddSeed(double, double, double);

	/*!
		Sets the entity containing the seeds to be displayed,
		and displays the seeds on the screen
	*/
	void setModel(Entity*);

	static void StartMoveAction(vtkAbstractWidget *);
	/*!
		Overrides the vtkSeedWidget's delete function.
	*/
	static void DeleteAction(vtkAbstractWidget *);
	/*!
		Edited and overridden VTK-code.
		It add the possibility of enable/disable "add seed" feature
	*/
	static void AddPointAction(vtkAbstractWidget *);

	vtkHandleWidget * CreateNewHandle();
	
	void update();

protected:	
	VTKControlledSeedWidget();
	~VTKControlledSeedWidget()
	{ 
		CompleteInteraction();
		EnabledOff();
		SetInteractor(NULL);

		std::cout << "DELETED: vtkControlledSeedWidget" << std::endl; 
	}
	
private:
	/*!
		Removes all interaction callback registered to the widget
	*/
	void resetInteractions();
	/*!
		Enables or disables the feature of adding seeds. 
		Use case: The seedWidget should not be able to add seeds to a finalized entity, 
		only move the existing seeds
	*/
	bool interactionAddEnabled;

	Entity *activeEntity;
};
#endif //VTKCONTROLLEDSEEDWIDGET_H