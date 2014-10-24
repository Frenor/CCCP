#include "VTKControlledSeedWidget.h"

/*
	ControlledSeedWidget created due to vtkSeedWidgets lack of control options.
	Disables /(fixes?) the bugged delete button, and enables more direct control of features in seedwidget.
*/
vtkStandardNewMacro(VTKControlledSeedWidget);
class vtkSeedList : public std::list<vtkHandleWidget*> {}; //!< Data structure used for seeds in VTK

VTKControlledSeedWidget::VTKControlledSeedWidget()
{
	this->interactionAddEnabled = false;
}

void VTKControlledSeedWidget::setCallback(vtkSmartPointer<vtkSeedCallback> scbk)
{
	AddObserver(vtkCommand::PlacePointEvent, scbk);
	AddObserver(vtkCommand::InteractionEvent, scbk);
	AddObserver(vtkCommand::DeleteEvent, scbk);
} 

void VTKControlledSeedWidget::setStartInteraction()
{
	resetInteractions();

	this->CallbackMapper->SetCallbackMethod(vtkCommand::LeftButtonPressEvent, vtkWidgetEvent::AddPoint, this, VTKControlledSeedWidget::AddPointAction);
	this->CallbackMapper->SetCallbackMethod(vtkCommand::RightButtonPressEvent, vtkWidgetEvent::Completed, this, VTKControlledSeedWidget::CompletedAction);
	this->CallbackMapper->SetCallbackMethod(vtkCommand::MouseMoveEvent, vtkWidgetEvent::Move, this, VTKControlledSeedWidget::MoveAction);
	this->CallbackMapper->SetCallbackMethod(vtkCommand::LeftButtonReleaseEvent, vtkWidgetEvent::EndSelect, this, VTKControlledSeedWidget::EndSelectAction);
	this->CallbackMapper->SetCallbackMethod(vtkCommand::KeyPressEvent, vtkEvent::NoModifier, 127, 1, "Delete", vtkWidgetEvent::Delete, this, VTKControlledSeedWidget::DeleteAction);
}

void VTKControlledSeedWidget::setEnableAddInteraction(bool enabled)
{
	this->interactionAddEnabled = enabled;

	if(enabled){
		std::cout << "set Enable interaction" << std::endl;
	}else{
		std::cout << "set Disable interaction" << std::endl;
	}

	RestartInteraction();
}

void VTKControlledSeedWidget::resetInteractions()
{
	this->EventTranslator->ClearEvents();
}

void VTKControlledSeedWidget::AddPointAction(vtkAbstractWidget *w)
{
	VTKControlledSeedWidget *self = reinterpret_cast<VTKControlledSeedWidget*>(w);
	self->WidgetRep->BuildRepresentation();
	
	if(!self->interactionAddEnabled)
	{
		self->WidgetState = vtkSeedWidget::PlacedSeeds;
	}
	else
	{
		self->InvokeEvent(vtkCommand::MouseMoveEvent, NULL);
	}
	Superclass::AddPointAction(w);

	if(self->activeEntity)
	{
		self->EventCallbackCommand->SetAbortFlag(1);
	}
}

void VTKControlledSeedWidget::DeleteAction(vtkAbstractWidget *w)
{
	std::cout << "DeleteAction!" << std::endl;

	vtkSeedWidget *self = reinterpret_cast<vtkSeedWidget*>(w);
	self->InvokeEvent(vtkCommand::DeleteEvent, NULL);

	self->DeleteAction(w);
}

void VTKControlledSeedWidget::setModel(Entity *entity)
{
	this->activeEntity = entity;
	
	while( ! this->Seeds->empty() )
    {
		this->DeleteSeed(static_cast<int>(this->Seeds->size())-1);
    }

	update();
}

void VTKControlledSeedWidget::update()
{
	if(this->activeEntity)
	{
		for each (Node *node in this->activeEntity->getSeeds())
		{
			AddSeed(node->x, node->y, node->z);
			std::cout << "Node added to Widget: " << node->x <<":" << node->y <<":" << node->z << std::endl;
		}
	}
}

void VTKControlledSeedWidget::AddSeed(double x, double y, double z)
{
	CompleteInteraction();

	vtkHandleWidget * handleWidget2 = CreateNewHandle();
	handleWidget2->SetEnabled(1);

	double p[3] = {x, y, z + 0.1};
	vtkSeedRepresentation *rep = reinterpret_cast<vtkSeedRepresentation*>(this->WidgetRep); 
	rep->GetHandleRepresentation(rep->GetNumberOfSeeds()-1)->SetWorldPosition(p);
	
	RestartInteraction();
}

vtkHandleWidget * VTKControlledSeedWidget::CreateNewHandle()
{
	vtkHandleWidget * handle = Superclass::CreateNewHandle();

	return handle;
}

