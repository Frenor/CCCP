#include "EntityGraphicController.h"


EntityGraphicController::EntityGraphicController(EntityGraphicModel *model, QWidget *view, QObject* parent) : GraphicController(view, parent)
{
	connectView();

	gView->set2DMode();
	gView->set2DInteractor();
	gView->GetInteractor()->Initialize();

	setModel(model);
	
	invalidate();
}


EntityGraphicController::~EntityGraphicController()
{
}

void EntityGraphicController::actorClicked(vtkSmartPointer<vtkActor>)
{

}

void EntityGraphicController::actorDoubleClicked(vtkSmartPointer<vtkActor>)
{

}

void EntityGraphicController::connectView()
{
	//connect(gView, SIGNAL(doneEvent()), this, SLOT(doneEvent()));
	//connect(gView, SIGNAL(cancelEvent()), this, SLOT(cancelEvent()));
	connect(gView, SIGNAL(actorClicked(vtkSmartPointer<vtkActor>)), this, SLOT(actorClicked(vtkSmartPointer<vtkActor>)));
	connect(gView, SIGNAL(actorDoubleClicked(vtkSmartPointer<vtkActor>)), this, SLOT(actorDoubleClicked(vtkSmartPointer<vtkActor>)));
}

void EntityGraphicController::activeEdgeChanged(Edge *edge)
{

}

void EntityGraphicController::setModel(EntityGraphicModel *model)
{
	this->gModel = model;
	connect(model, SIGNAL(selectedEdgeChanged(Edge*)), this, SLOT(invalidate()));
	connect(model, SIGNAL(valuesUpdated()), this, SLOT(invalidate()));
}

void EntityGraphicController::invalidate()
{
	gModel->entity->updatePolygon();

	gView->removeActors();
	drawPointsAndLines(gModel->getNodes(), gModel->getEdges());
	drawSurfaces();

	gView->invalidate();
	gView->renderer->ResetCamera();
}

void EntityGraphicController::drawPointsAndLines(std::vector<Node*> nodes, std::vector<Edge*> edges)
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
	}

	for (Edge *edge : edges)
	{
		vtkSmartPointer<vtkLine> line = vtkSmartPointer<vtkLine>::New();
		line->GetPointIds()->SetId(0, edge->n1->id);
		line->GetPointIds()->SetId(1, edge->n2->id);

		lines->InsertNextCell(line);
	}

	pd->SetPoints(points);
	pd->SetLines(lines);

	mapper->SetInputData(pd);

	actor->GetProperty()->SetRepresentationToWireframe();
	actor->SetMapper(mapper);

	gView->addActor(actor);
}

void EntityGraphicController::drawSurfaces()
{
	//for each (Edge *edge in gModel->entity->edges)
	//{
	//
	//}
	gModel->entity->getActor()->GetProperty()->SetOpacity(0.8);
	gView->addActor(gModel->entity->getActor());
}