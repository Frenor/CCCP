#include "DrawController.h"

DrawController::DrawController(DrawModel *model, QWidget *view, QObject* parent) : GraphicController(view, parent)
{
	connectView();

	EntityOperation *eOperation = new EntityOperation(model, this);
	DrawViewMenu *cMenu = new DrawViewMenu(gView, eOperation, model, this);

	scbk = vtkSmartPointer<vtkSeedCallback>::New();
	seedRep = vtkSmartPointer<vtkSeedRepresentation>::New();
	widget = vtkSmartPointer<VTKControlledSeedWidget>::New();

	gView->set2DMode();

	gView->set2DInteractor();
	gView->GetInteractor()->Initialize();

	setModel(model);

	startSeedWidget();

	std::cout << "DrawControllerStarted!" << std::endl;
}

void DrawController::connectView()
{
	//Old conenctions are automatically disconnected when listener/controller object is deleted
	connect(gView, SIGNAL(doneEvent()), this, SLOT(doneEvent()));
	connect(gView, SIGNAL(cancelEvent()), this, SLOT(cancelEvent()));
	connect(gView, SIGNAL(actorClicked(vtkSmartPointer<vtkActor>)), this, SLOT(actorClicked(vtkSmartPointer<vtkActor>)));
	connect(gView, SIGNAL(actorDoubleClicked(vtkSmartPointer<vtkActor>)), this, SLOT(actorDoubleClicked(vtkSmartPointer<vtkActor>)));
}

void DrawController::startSeedWidget()
{
	handleRep = vtkSmartPointer<vtkPointHandleRepresentation3D>::New();
	handleRep->GetProperty()->SetColor(0, 0.7, 0);
	handleRep->GetProperty()->SetLineWidth(3.0);
	seedRep->SetHandleRepresentation(handleRep);

	scbk->SetRepresentation(seedRep);

	widget->setStartInteraction();
	widget->SetRepresentation(seedRep);
	widget->SetInteractor(gView->GetInteractor());
	widget->setModel(model->activeEntity);

	widget->setCallback(scbk);

	gView->GetRenderWindow()->Render();
	gView->GetInteractor()->Initialize();
	gView->GetRenderWindow()->Render();

	widget->On();
}

void DrawController::setModel(DrawModel *DrawModel)
{
	this->model = DrawModel;
	reset();

	connect(model, &DrawModel::activeEntityChanged, this, &DrawController::setActiveEntity);
	connect(model, &DrawModel::entityChanged, this, &DrawController::invalidate);
	connect(model, &DrawModel::entityDeleted, this, &DrawController::reset);
	connect(model, &DrawModel::dialogClosed, this, &DrawController::invalidate);
}

void DrawController::reset()
{
	invalidate();
	if(model->activeEntityFinalized)
	{
		widget->setModel(nullptr);
	}
	else
	{
		widget->setModel(model->activeEntity);
	}
}

void DrawController::invalidate()
{
	std::cout << "Invalidate" << std::endl;

	gView->removeActors();
	drawPointsAndLines(model->getAllNodes(), model->getAllEdges());
	drawSurfaces();

	gView->invalidate();
}

void DrawController::drawPointsAndLines(std::vector<Node*> nodes, std::vector<Edge*> edges)
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	vtkSmartPointer<vtkPolyData> pd = vtkSmartPointer<vtkPolyData>::New();
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

	int i = 0;
	for (Node *node : nodes)
	{
		node->id = i++;
		points->InsertPoint(node->id, node->x, node->y, 0);

		//std::cout << "Node: [id,x,y,z,h]: [" << node->id << "," << node->x << "," << node->y << "," <<node->z << "," << node->handle << "]" << std::endl;
	}

	for (Edge *edge : edges)
	{
		vtkSmartPointer<vtkLine> line =vtkSmartPointer<vtkLine>::New();
		line->GetPointIds()->SetId(0, edge->n1->id);
		line->GetPointIds()->SetId(1, edge->n2->id);

		lines->InsertNextCell(line);

		//std::cout << "Edge [n1,n2]: [" << edge->n1->id << "," << edge->n2->id << "]" << std::endl;
	}

	pd->SetPoints(points);
	pd->SetLines(lines);

	mapper->SetInputData(pd);

	actor->GetProperty()->SetRepresentationToWireframe();
	actor->SetMapper(mapper);

	gView->addActor(actor);
}

void DrawController::drawSurfaces()
{
	for each (Entity *entity in model->entities)
	{
		//std::cout << "SurfEntity: " << entity->finalized << " : " << model->isNotActiveEntity(entity) << " : " << model->activeEntity << std::endl;
		if(entity->isClosed())
		{
			createSurface(entity);
		}
	}
}

void DrawController::createSurface(Entity* entity)
{
	if(entity->isVisible())
	{
		entity->updatePolygon();

		if(model->isNotActiveEntity(entity))
		{
			setColorDone(entity->getActor());
		}
		else
		{
			setColorSelected(entity->getActor());
		}
		gView->addActor(entity->getActor());

		//Adding holes in entity to the view
		for each (vtkSmartPointer<vtkActor> holeActor in entity->getHoleActors())
		{
			setColorBackground(holeActor);
			gView->addActor(holeActor);
		}
	}
}

void DrawController::setColorSelected(vtkSmartPointer<vtkActor> actor)
{
	actor->GetProperty()->SetOpacity(0.5);
}

void DrawController::setColorDone(vtkSmartPointer<vtkActor> actor)
{
	actor->GetProperty()->SetOpacity(0.8);
}

void DrawController::setColorBackground(vtkSmartPointer<vtkActor> actor)
{
	actor->GetProperty()->SetColor(10/256.0, 76/256.0, 161/256.0);
	actor->GetProperty()->SetOpacity(1.0);
}

void DrawController::setActiveEntity(Entity *activeEntity)
{
	scbk->setEntity(activeEntity);
	updateInteraction(activeEntity);
	if (activeEntity)
	{
		activeEntity->setActive(true);
	}

	reset();
}

void DrawController::updateInteraction(Entity *activeEntity)
{
	if(activeEntity && !activeEntity->isClosed())
	{
		widget->setEnableAddInteraction(true);
	}
	else
	{
		if(activeEntity)
		{
			std::cout << "activeEntity->closed(): " << activeEntity->isClosed() << std::endl;
		}
		widget->setEnableAddInteraction(false);
	}
}

void DrawController::actorClicked(vtkSmartPointer<vtkActor> pickedActor)
{
	if(pickedActor)
	{
		Entity *selectedEntity = findEntityBasedOnActor(pickedActor);
		model->setActiveInput(selectedEntity);
	}
	else
	{
		model->setActiveEntityNULL();
	}
}

void DrawController::actorDoubleClicked(vtkSmartPointer<vtkActor> pickedActor)
{
	Entity *selectedEntity = findEntityBasedOnActor(pickedActor);

	if(selectedEntity)
	{
		selectedEntity->setIsFinalized(false);
		model->activeEntityFinalized = false;
	}
	model->setActiveInput(selectedEntity);
}

Entity* DrawController::findEntityBasedOnActor(vtkSmartPointer<vtkActor> actor)
{
	for each (Entity* entity in model->entities)
	{
		if(entity->getActor() == actor)
		{
			return entity;
		}
	}
	return NULL;
}

void DrawController::doneEvent()
{
	model->finalizeActiveEntity();
}

void DrawController::cancelEvent()
{
	model->deleteActiveEntity();
}
