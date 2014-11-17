#include "Entity.h"
#include <vector>
#include <iostream>
#include "DrawModel.h"


Entity::Entity(QObject *parent) : QObject(parent)
{
	//Entity(parent, true);
	this->editable = editable;
	this->finalized = false;
	this->closed = false;
	this->visible = true;
	this->level = 0;

	this->lastSelectedNode = NULL;
	this->name = "Entity";

	actor = vtkSmartPointer<vtkActor>::New();
	points = vtkSmartPointer<vtkPoints>::New();
}

Entity::~Entity()
{
	deleteEdges();
	deleteNodes();

	actor->Delete();
	points->Delete();

	std::cout << "Entity deleted" << std::endl; 
}

bool Entity::isHole()
{
	return hole;
}

bool Entity::isClosed()
{
	return closed;
}

void Entity::updatePolygon(int drawingType)
{
	switch (drawingType)
	{
	case DrawModel::MASSIVE:
		updateActor(getPolyData());
		break;
	case DrawModel::THINWALLED:
		updateActor(getPolyDataWalled());
		break;
	default:
		break;
	}
}

void Entity::updateActor(vtkSmartPointer<vtkPolyData> pd)
{
	vtkSmartPointer<vtkPolyDataMapper> mapperSurface = vtkSmartPointer<vtkPolyDataMapper>::New();
	vtkSmartPointer<vtkTriangleFilter> triangleFilter = vtkSmartPointer<vtkTriangleFilter>::New();
	
	triangleFilter->SetInputData(pd);
	triangleFilter->Update();

	mapperSurface->SetInputConnection(triangleFilter->GetOutputPort());
	actor->SetMapper(mapperSurface);
	
	this->actor = getZLeveledActor(0.1);
	std::cout << "MainActor done" << std::endl;
}

vtkSmartPointer<vtkActor> Entity::getZLeveledActor(double factor)
{
	double res = -level*factor;
	std::cout << "Z-Level: [level, factor, tot]: " << level << ", " << factor << ", " << res << "]" <<std::endl;
	double*pos = actor->GetPosition();
	pos[2] = -factor*level;
	actor->SetPosition(pos);
	return actor;
}

vtkSmartPointer<vtkPolyData> Entity::getPolyData()
{
	vtkSmartPointer<vtkCellArray> poly = vtkSmartPointer<vtkCellArray>::New();
	vtkSmartPointer<vtkPolyData> pd = vtkSmartPointer<vtkPolyData>::New();
		
	poly->InsertNextCell(getPolygon());

	pd->SetPoints(points);
	pd->SetPolys(poly);

	return pd;
}

vtkSmartPointer<vtkPolyData> Entity::getPolyDataWalled()
{
	vtkSmartPointer<vtkCellArray> poly = vtkSmartPointer<vtkCellArray>::New();
	vtkSmartPointer<vtkPolyData> pd = vtkSmartPointer<vtkPolyData>::New();

	points->Initialize();

	for each (Edge *edge in edges)
	{
		addWallToPoints(edge);
		poly->InsertNextCell(getWallPolygon(edge));
	}
	pd->SetPoints(points);
	pd->SetPolys(poly);

	return pd;
}

vtkSmartPointer<vtkPolygon> Entity::getPolygon()
{
	int n = 0;
	vtkSmartPointer<vtkPolygon> polygon = vtkSmartPointer<vtkPolygon>::New();
	polygon->GetPointIds()->SetNumberOfIds(nodes.size());

	for each (Node *node in nodes)
	{
		//node->id = n++;
		//std::cout << "Node: [id,x,y,z,h]: [" << node->id << "," << node->x << "," << node->y << "," <<node->z << "," << node->handle << "]" << std::endl;

		points->InsertPoint(node->id, node->x, node->y, 0);
		polygon->GetPointIds()->SetId(n++, node->id);
	}
	//std::cout << "Number of edges: " << polygon->GetNumberOfEdges() << std::endl;

	return polygon;
}

vtkSmartPointer<vtkPolygon> Entity::getWallPolygon(Edge* edge)
{
	//TODO: Too much hard coding, see "addWallToPoints" for more.
	vtkSmartPointer<vtkPolygon> polygon = vtkSmartPointer<vtkPolygon>::New();
	polygon->GetPointIds()->SetNumberOfIds(4); //!< An edge will always have two nodes, each node has two points. 2*2=4

	polygon->GetPointIds()->SetId(0, (edge->n1->id * 2) + 0);
	polygon->GetPointIds()->SetId(1, (edge->n2->id * 2) + 0);
	polygon->GetPointIds()->SetId(2, (edge->n2->id * 2) + 1);
	polygon->GetPointIds()->SetId(3, (edge->n1->id * 2) + 1);

	return polygon;
}

void Entity::addWallToPoints(Edge* edge)
{
	double v[2] = { edge->n2->x - edge->n1->x, edge->n2->y - edge->n1->y };
	double vLength = sqrt(pow(v[0], 2) + pow(v[1], 2)); //Pythag. length of vector V. 
	//TODO: Test if this is fast enough, if not consider the magical fast inverse sqare root (http://en.wikipedia.org/wiki/Fast_inverse_square_root)
	
	/* TODO: Way to much hard coding. This should be a loop over nodes in Edge. 
	This requires reimplementation of all references to Edge, and I need to make this work first.
	Possible to loop more than this as well, to achieve better parallelization.	//FN 	*/
	
	double scalingFactorN1 = (edge->width1 / 2) / vLength;		//Divide by half, since node position is on center point of wall.
	double scalingFactorN2 = (edge->width2 / 2) / vLength;
	
	double u1[2] = { -scalingFactorN1 * v[1], scalingFactorN1 * v[0] };
	double u2[2] = { -scalingFactorN2 * v[1], scalingFactorN2 * v[0] };

	points->InsertPoint((edge->n1->id * 2) + 0, edge->n1->x + u1[0], edge->n1->y + u1[1], 0);
	points->InsertPoint((edge->n2->id * 2) + 0, edge->n2->x + u1[0], edge->n2->y + u1[1], 0);
	points->InsertPoint((edge->n2->id * 2) + 1, edge->n2->x - u1[0], edge->n2->y - u1[1], 0);
	points->InsertPoint((edge->n1->id * 2) + 1, edge->n1->x - u1[0], edge->n1->y - u1[1], 0);
}

double Entity::getLevel()
{
	return level;
}
void Entity::setLevel(double level)
{
	this->level = level;
}
void Entity::setIsFinalized(bool finalized)
{
	this->finalized = finalized;
}
bool Entity::isVisible()
{
	return visible;
}

vtkSmartPointer<vtkActor> Entity::getActor()
{
	return actor;
}

std::vector<vtkSmartPointer<vtkActor>> Entity::getHoleActors()
{
	return holeActors;
}

void Entity::deleteNodes()
{
	nodes.clear();
}
void Entity::deleteEdges()
{
	edges.clear();
}

void Entity::setName(std::string name)
{
	this->name = name;
}

bool Entity::isEmpty()
{
	return (nodes.size() < 1 || edges.size() < 1);
}

void Entity::setType(int type)
{
	this->type = type;
}

void Entity::addNode(double pos[], int handle)
{
	Node *node = new Node();
	node->setPosition(pos);
	node->handle = handle;
	node->id = nodes.size();

	nodes.push_back(node);

	if(lastSelectedNode)
	{
		createEdge(lastSelectedNode, node);
	}

	lastSelectedNode = node;
}

void Entity::close()
{
	if (!closed && !isEmpty()){
		Node *n1 = nodes.back();
		Node *n2 = nodes.front();

		createEdge(n1,n2);

		closed = true;
	}
}

void Entity::createEdge(Node *node1, Node *node2)
{
	Edge *edge = new Edge(node1, node2);
	edges.push_back(edge);

	//std::cout << "Edge created [ " << edge->n1->id << ", " << edge->n2->id << "]" << std::endl;
}

void Entity::createSeed(double pos[], int handle)
{
	Node *node = new Node();
	node->setPosition(pos);
	node->handle = handle;
	node->id = nodes.size();
	seeds.push_back(node);
}

void Entity::doneEditing()
{
	emit nodeChanged();
	emit entityChanged(this);
}

std::vector<Node*> Entity::getNodesOrdered()
{
	std::vector<Node *> orderedNodes(nodes.size());

	for each (Node *node in nodes)
	{
		orderedNodes.at(node->id) = node;
	}
	return orderedNodes;
}

std::list<Edge*> Entity::getEdgesOrderedClockWise()
{
	if(isClockWise()){
		return edges;
	}else{
		return reOrderEdges();
	}
}

std::list<Edge*> Entity::getEdgesOrderedCounterClockWise()
{
	if(isClockWise()){
		return reOrderEdges();
	}else{
		return edges;
	}
}

std::list<Edge*> Entity::reOrderEdges()
{
	std::list<Edge*> orderedEdges;
	for each (Edge* edge in edges)
	{
		Node *oldN1 = edge->n1;
		
		edge->n1 = edge->n2;
		edge->n2 = oldN1;

		orderedEdges.push_front(edge);
	}
	//std::cout << "REORDER EDGES" << std::endl;
	return orderedEdges;
}

bool Entity::isClockWise()
{
	double c = 0;
	for each (Edge *edge in edges)
	{
		c += (edge->n2->x - edge->n1->x)*(edge->n2->y + edge->n1->y);
		//std::cout << "c: " << c << "	[" << edge->n1->x << ", " << edge->n1->y << "] [" << edge->n2->x << ", " << edge->n2->y << "] " << std::endl;
	}

	return (c > 0);
}