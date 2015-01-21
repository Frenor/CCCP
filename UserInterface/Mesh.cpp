#include "Mesh.h"

Mesh::Mesh(QObject *parent) : Entity(parent) {}

Mesh::Mesh(QString fileName, std::vector<Node> nodes, std::vector<Element*> elements, QObject *parent) : Entity(parent)
{
	this->fileName = fileName;
	this->elements = elements;
	
	std::list<Node*> compatibleNodes;
	std::vector<Node*> compatibleSeeds;

	for each (Node node in nodes)
	{
		Node *newNode = new Node;
		newNode->id = node.id;
		newNode->x = node.x;
		newNode->y = node.y;
		newNode->z = node.z;

		compatibleNodes.push_back(newNode);
		compatibleSeeds.push_back(newNode);
	}
	this->nodes = compatibleNodes;
	this->seeds = compatibleSeeds;
}

std::vector<Element*> Mesh::getElements()
{
	return elements;
}

QString Mesh::getFileName()
{
	return fileName;
}

int Mesh::getNumberOfNodes()
{
	return nodes.size();
}

int Mesh::getNumberOfElements()
{
	return elements.size();
}

void Mesh::updatePolygon()
{
	updateActor(getPolyData());
}

vtkSmartPointer<vtkPolyData> Mesh::getPolyData()
{
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	for each (Node* node in nodes)
	{
		//std::cout << "Point insert: " << node->id << ", " << node->x << ", " << node->y << std::endl;
		points->InsertPoint(node->id, node->x, node->y, 0);
	}

	vtkSmartPointer<vtkCellArray> polys = vtkSmartPointer<vtkCellArray>::New();

	for (Element *element : elements)
	{
		polys->InsertNextCell((element->nodes.size()));
		for (Node *node : element->nodes)
		{
			polys->InsertCellPoint(node->id);
		}
	}

	vtkSmartPointer<vtkPolyData> pd = vtkSmartPointer<vtkPolyData>::New();
	pd->SetPolys(polys);
	pd->SetPoints(points);
	
	return pd;
}