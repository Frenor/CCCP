#pragma once
#ifndef ENTITYGRAPHICCONTROLLER_H
#define ENTITYGRAPHICCONTROLLER_H

#include "GraphicController.h"
#include "EntityGraphicModel.h"

#include "vtkLine.h"

class EntityGraphicController : public GraphicController
{
	Q_OBJECT
public:
	EntityGraphicController(EntityGraphicModel*, QWidget*, QObject *parent = 0);
	~EntityGraphicController();

public slots:
	void activeEdgeChanged(Edge*);
	void invalidate();

private:
	EntityGraphicModel *gModel;

	void actorClicked(vtkSmartPointer<vtkActor>);
	void actorDoubleClicked(vtkSmartPointer<vtkActor>);
	void connectView();
	void setModel(EntityGraphicModel*);
	void drawPointsAndLines(std::vector<Node*>, std::vector<Edge*>);
	void drawSurfaces();
};
#endif //ENTITYGRAPHICCONTROLLER_H