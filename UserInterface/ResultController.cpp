#include "ResultController.h"

#include <vtkRendererCollection.h>
#include <vtkPoints.h>

ResultController::ResultController(ResultModel *model, QWidget *widget, QObject* parent) : GraphicController(widget, parent)
{
	gView->set3DMode();
	
	resultActor = vtkSmartPointer<vtkActor>::New();
	meshActor = vtkSmartPointer<vtkActor>::New();

	scalarBarActor = vtkSmartPointer<vtkScalarBarActor>::New();
	scalarBarWidget = vtkSmartPointer<vtkScalarBarWidget>::New();
	
	axesActor = vtkSmartPointer<vtkAxesActor>::New();
	axesWidget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();

	setModel(model);

	createOrientationMarker();
	
	std::cout << "Created: ResultController" << std::endl; 
}
ResultController::~ResultController()
{
	axesWidget->InteractiveOff();
	axesWidget->EnabledOff();

	scalarBarWidget->Off();
	scalarBarWidget->EnabledOff();

	std::cout << "Deleted: ResultController" << std::endl;
}

void ResultController::createOrientationMarker()
{
	axesWidget->SetOrientationMarker(axesActor);
	axesWidget->SetInteractor(gView->GetInteractor());
	axesWidget->SetEnabled(1);
	axesWidget->InteractiveOn();
}

void ResultController::createScalarBarActor()
{
	scalarBarActor->SetLookupTable(model->lut);
	scalarBarActor->SetOrientationToVertical();
	scalarBarActor->SetTitle(model->getActiveResultName().c_str());
	scalarBarActor->SetVisibility(model->scalarBarVisible);
	
	scalarBarWidget->SetInteractor(gView->GetInteractor());
	scalarBarWidget->SetScalarBarActor(scalarBarActor);
	scalarBarWidget->On();

	scalarBarActor->SetWidth(0.5);
}

void ResultController::setModel(ResultModel *model)
{
	this->model = model;
	connect(model, SIGNAL(modelChanged()), this, SLOT(invalidate()));
	connect(model, SIGNAL(modelDataSourceChanged()), this, SLOT(reset()));

	reset();
}

void ResultController::invalidate()
{
	setVisibility();
	scalarBarActor->SetTitle(model->getActiveResultName().c_str());

	gView->invalidate();
}

void ResultController::reset()
{
	gView->reset();
	createResultActor();
	createMeshActor();
	createScalarBarActor();
	
	std::cout << "ResultController Reset Done" << std::endl;
}

void ResultController::createResultActor()
{
	if(model->hasResultData()){

		resultActor->SetMapper(model->getMapper());

		gView->addActor(resultActor);
		resultActor->SetVisibility(model->resultVisible);
		
		gView->renderer->ResetCamera();

		////std::cout << "Number of renderers: " << gView->GetRenderWindow()->GetRenderers()->GetNumberOfItems() << std::endl;

		std::cout << "Created ResultActor" << std::endl;
	}
}

void ResultController::createMeshActor()
{
	std::cout << "HasMeshData: " << model->hasMeshData() << std::endl;
	if(model->hasMeshData()){
		std::cout << "CreateMeshActor[ResultController]: N: " << model->getMesh()->getNumberOfNodes() << ", E: " << model->getMesh()->getNumberOfElements() << std::endl;

		model->getMesh()->updatePolygon();

		meshActor = model->getMesh()->getActor();
		meshActor->GetProperty()->SetRepresentationToWireframe();
		meshActor->SetVisibility(model->meshVisible);

		gView->addActor(meshActor);
		gView->renderer->ResetCamera();
	}
}

void ResultController::setVisibility()
{
	if(resultActor){
		resultActor->SetVisibility(model->resultVisible);
	}
	if(meshActor)
	{
		meshActor->SetVisibility(model->meshVisible);
	}
	scalarBarActor->SetVisibility(model->scalarBarVisible);
}