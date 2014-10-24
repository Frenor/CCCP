#include "GraphicsView.h"

GraphicsView::GraphicsView(QWidget *parent) : QVTKWidget(parent)
{
	createBackground();

	renderer = createRenderer();

	cam2D = vtkSmartPointer<vtkCamera>::New();
	cam2D->ParallelProjectionOn();

	cam3D = vtkSmartPointer<vtkCamera>::New();
}

void GraphicsView::reset()
{
	removeActors();
	invalidate();
}

void GraphicsView::removeActors()
{
	for each (vtkSmartPointer<vtkActor> actor in actors)
	{
		//std::cout << "Delete actor" << std::endl;
		renderer->RemoveActor(actor);
	}
	actors.clear();
}

void GraphicsView::addActor(vtkSmartPointer<vtkActor> actor)
{
	actors.push_back(actor);
	renderer->AddActor(actor);
	//std::cout << "Created actor" << std::endl;
}

void GraphicsView::set2DInteractor()
{
	vtkSmartPointer<vtkInteractorStyleImage> interactorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();
	interactorStyle->RemoveAllObservers();

	interactorStyle->AddObserver(vtkCommand::LeftButtonPressEvent, this, &GraphicsView::clickCallback);
	interactorStyle->AddObserver(vtkCommand::RightButtonPressEvent, this, &GraphicsView::contextMenuCallback);
	
	GetInteractor()->SetInteractorStyle(interactorStyle);
	interactorStyle->EnabledOn();
}

void GraphicsView::resetInteractor()
{
	vtkSmartPointer<vtkInteractorStyleTrackballCamera> interactorStyle = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
	GetInteractor()->SetInteractorStyle(interactorStyle);
}

void GraphicsView::createBackground()
{
	GetRenderWindow()->SetNumberOfLayers(2);
	vtkSmartPointer<vtkRenderer> bgRenderer = vtkSmartPointer<vtkRenderer>::New();
	bgRenderer->SetBackground(10/256.0, 76/256.0, 161/256.0);
	bgRenderer->SetBackground2(0.031, 0.2665, 0.476);
	bgRenderer->SetGradientBackground(true);
	bgRenderer->SetLayer(0);
	bgRenderer->InteractiveOff();

	addRenderer(bgRenderer);
}

void GraphicsView::invalidate()
{
	update();
	GetRenderWindow()->Render();
}

void GraphicsView::escapePressed()
{
	//Shotcut signals can only be connected to a QWidget/View..
	emit cancelEvent();
}

void GraphicsView::enterPressed()
{
	std::cout << "Enter Pressed" << std::endl;
	emit doneEvent();
}

void GraphicsView::set2DMode()
{
	renderer->SetActiveCamera(cam2D);
}

void GraphicsView::set3DMode()
{
	renderer->SetActiveCamera(cam3D);
	resetInteractor();
}

vtkSmartPointer<vtkRenderer> GraphicsView::createRenderer()
{
	renderer = vtkSmartPointer<vtkRenderer>::New();
	renderer->SetLayer(1);
	addRenderer(renderer);

	return renderer;
}

void GraphicsView::addRenderer(vtkSmartPointer<vtkRenderer> renderer)
{
	GetRenderWindow()->AddRenderer(renderer);
	update();
}

void GraphicsView::removeRenderer(vtkSmartPointer<vtkRenderer> renderer)
{
	GetRenderWindow()->RemoveRenderer(renderer);
	update();
}

void GraphicsView::clickCallback()
{
	int* clickPos = GetInteractor()->GetEventPosition();

	// Pick from this location.
	vtkSmartPointer<vtkPropPicker>  picker = vtkSmartPointer<vtkPropPicker>::New();
	picker->Pick(clickPos[0], clickPos[1], 0, renderer);
	double* posLocal = picker->GetPickPosition();
	
	vtkSmartPointer<vtkActor> pickedActor = picker->GetActor();
	if(pickedActor)
	{
		double* newPos = picker->GetPickPosition();
		std::cout << "Clicked: "<< newPos[0] << ", " << newPos[1] << std::endl;

		double xDist = pos[0] - newPos[0];
		double yDist = pos[1] - newPos[1];

		double dist = sqrt((double)(xDist*xDist + yDist*yDist));
		std::cout  << " Distance: " << dist << std::endl;

		if(dist < 0.001)
		{
			std::cout << "oldPOS: "<< pos[0] << ", " << pos[1] << std::endl;
			emit actorDoubleClicked(pickedActor);
		}
		else
		{
			emit actorClicked(pickedActor);
		}

		pos[0] = newPos[0];
		pos[1] = newPos[1];

		return;
	}
	emit actorClicked(NULL);
}

void GraphicsView::contextMenuCallback()
{
	int* clickPos = GetInteractor()->GetEventPosition();
	
	vtkSmartPointer<vtkPropPicker>  picker = vtkSmartPointer<vtkPropPicker>::New();
	picker->Pick(clickPos[0], clickPos[1], 0, renderer);

	int x = clickPos[0];
	int y = renderer->GetSize()[1] - clickPos[1];

	vtkSmartPointer<vtkActor> pickedActor = picker->GetActor();
	if(pickedActor){
		std::cout << "Local ContextPos: [" << x << ", " << y << "]" << std::endl;
		
		emit actorClicked(pickedActor);
		emit customContextMenuRequested(QPoint(x, y));
	}
}