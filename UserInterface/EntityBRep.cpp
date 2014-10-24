#include "EntityBRep.h"

EntityBRep::EntityBRep(Entity* e1, Entity* e2, int operation, QObject *parent) : Entity(parent)
{
	this->type = BREP;
	this->editable = false;
	this->closed = true;
	this->updateRequired = true;
	this->name = "Entity-Composite";

	childEntities.push_back(e1);
	childEntities.push_back(e2);
	
	connect(e1, SIGNAL(entityChanged(Entity*)), this, SLOT(setRequireUpdate()));
	connect(e2, SIGNAL(entityChanged(Entity*)), this, SLOT(setRequireUpdate()));

	operations.push_back(operation);
}

void EntityBRep::setRequireUpdate()
{
	this->updateRequired = true;
}

EntityBRep::~EntityBRep(){}

void EntityBRep::updatePolygon()
{
	if(updateRequired)
	{
		updateResultEntities();
		updateNodesAndEdges();
	}
	
	updateActor(getPolyData());
	updateHoleActors();
}

void EntityBRep::updateNodesAndEdges()
{
	nodes.clear();
	edges.clear();
	for each (Entity* entity in resultEntities)
	{
		nodes.insert(nodes.end(), entity->nodes.begin(), entity->nodes.end());
		edges.insert(edges.end(), entity->edges.begin(), entity->edges.end());
	}
}

void EntityBRep::updateResultEntities()
{
	BRepFactory bfactory = BRepFactory(childEntities.at(0));
	for (int i = 0; i < operations.size(); i++)
	{
		bfactory.addCSGOperation(childEntities.at(i+1), operations.at(i));
	}
	bfactory.perform();
	
	for each (Entity* entity in bfactory.getEntities())
	{
		if(entity->isClockWise()){
			resultEntities.push_back(entity);
		}else{
			resultHoleEntities.push_back(entity);
		}
	}

	updateRequired = false;
	bfactory.~BRepFactory();
}

vtkSmartPointer<vtkPolyData> EntityBRep::getPolyData()
{
	vtkSmartPointer<vtkCellArray> poly = vtkSmartPointer<vtkCellArray>::New();
	vtkSmartPointer<vtkPolyData> pd = vtkSmartPointer<vtkPolyData>::New();
	
	for each (Entity* entity in resultEntities)
	{
		for each (Node *node in entity->nodes)
		{
			points->InsertPoint(node->id, node->x, node->y, 0);
		}
		poly->InsertNextCell(entity->getPolygon());
	}
	
	pd->SetPoints(points);
	pd->SetPolys(poly);
	
	return pd;
}

void EntityBRep::updateHoleActors()
{
	holeActors.clear();
	for each (Entity* entity in resultHoleEntities)
	{
		entity->updatePolygon();
		entity->setLevel(this->level);
		vtkSmartPointer<vtkActor> holeActor = entity->getZLeveledActor(0.01);
		holeActors.push_back(holeActor);

		std::cout << "holeActor added to holeActors" << std::endl;
	}
}

bool EntityBRep::safeConvertToEditableEntity()
{
	return resultEntities.size() < 2;
}

std::vector<Node*> EntityBRep::getSeeds()
{
	//If seeds from childEntities are returned here, 
	//the seed references will be to this entity..
	return seeds;
}