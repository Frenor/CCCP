#include "MSHParser.h"

MSHParser::MSHParser(QObject *parent, std::string fileName) : QObject(parent)
{
	nNodes = -1;
	nElements = -1;
	this->fileName = fileName;

	std::ifstream file;
	file.open(fileName, std::ifstream::in);
	if(!file.is_open())
	{
		fprintf(stderr, "Cannot load file:%s!\n", fileName);
	}
	load_msh(file);
}

std::string MSHParser::getFilename()
{
	return fileName;
}

Node MSHParser::getNodeAt(int n){
	return nodes[n];
}

Element* MSHParser::getElementAt(int e){
	return elements[e];
}

std::vector<Element*> MSHParser::getElements()
{
	return elements;
}

std::vector<Node> MSHParser::getNodes()
{
	return nodes;
}

int MSHParser::getNumberOfNodes()
{
	return nNodes;
}
int MSHParser::getNumberOfElements()
{
	return nElements;
}

void MSHParser::load_msh(std::ifstream &file)
{
	int _nNode, _nElement;
	double version;
	int i = 0;

	for(;;)
	{
		file >> line;
		if(line == "$MeshFormat")
		{
			if(readMeshFormat(file, &version))
			{
				printf("File invalid. Missing $EndMeshFormat or not v2.2 !\n");
				return;
			}
		}
		else if(line == "$Nodes")
		{
			if(!readNodes(file, &nodes, &_nNode))
			{
				return;
			}
			nNodes = _nNode;
		}
		else if(line == "$Elements") 
		{
			if(!readElements(file, &elements, &_nElement))
			{
				return;
			}
			nElements = _nElement;
		}
		else{
			printf("Found[Nodes, Elements]: [%i,%i]\n", nNodes, nElements);
			return;
		}
	}
}

void MSHParser::readInt(std::ifstream& in, int *number)
{
	in >> line;
	*number = atoi(line.c_str()); 
}
void MSHParser::readDouble(std::ifstream& in, double *number)
{
	in >> line;
	*number=atof(line.c_str());
}

bool MSHParser::filePosEqualsLine(std::ifstream& in, std::string correctLine)
{
	in >> line;
	return line == correctLine;
}

bool MSHParser::readMeshFormat(std::ifstream& in, double *version)
{
	int unused = 0;
	readDouble(in, version);
	readInt(in, &unused);
	readInt(in, &unused);

	if(!filePosEqualsLine(in,"$EndMeshformat") || *version != 2.2)
	{
		return false;
	}
	return true;
}

bool MSHParser::readNodes(std::ifstream& in, std::vector<Node> *nodes, int *number){
	readInt(in, number);

	//Unused
	int nodeNumber;
	double z;

	Node node;
	for(int n = 0; n< *number; n++)
	{
		readInt(in, &node.id);
		readDouble(in, &node.x);
		readDouble(in, &node.y);
		readDouble(in, &z);
	
		(*nodes).push_back(node);
	}

	return filePosEqualsLine(in,"$EndNodes");
}

bool MSHParser::readElements(std::ifstream& in, std::vector<Element*> *elements, int *nElement)
{
	readInt(in, nElement);

	//Unused
	int elementNumber, validElements = 0;
	int type, args, originalId, unusedTag;
	int n1,n2,n3;

	for(int e = 0; e< *nElement; e++)
	{
		readInt(in, &elementNumber);
		readInt(in, &type);

		LineElement *lElement = new LineElement();
		TriangleElement *tElement = new TriangleElement();

		switch (type)
		{
		case 1: //2-node line
			delete tElement; //unused -> delete.

			readInt(in, &args);
			for (int i = 0; i < args - 1; i++)
			{
				readInt(in, &unusedTag);
			}
			readInt(in, &originalId);

			readInt(in, &n1);
			readInt(in, &n2);

			lElement->nodes.push_back(&nodes[n1 - 1]);
			lElement->nodes.push_back(&nodes[n2 - 1]);

			lElement->x1 = (*lElement->nodes.at(0)).x;
			lElement->x2 = (*lElement->nodes.at(1)).x;

			lElement->y1 = (*lElement->nodes.at(0)).y;
			lElement->y2 = (*lElement->nodes.at(1)).y;

			elements->push_back(lElement);
			validElements++;
			break;
		case 2: //3-node triangle.
			delete lElement; //unused -> delete.

			readInt(in, &args);
			readDouble(in, &tElement->material);
			for (int i = 0; i < args - 2; i++)
			{
				readInt(in, &unusedTag);
			}
			readInt(in, &originalId);

			readInt(in, &n1);
			readInt(in, &n2);
			readInt(in, &n3);

			tElement->nodes.push_back(&nodes[n1 - 1]);
			tElement->nodes.push_back(&nodes[n2 - 1]);
			tElement->nodes.push_back(&nodes[n3 - 1]);

			tElement->x1 = (*tElement->nodes.at(0)).x;
			tElement->x2 = (*tElement->nodes.at(1)).x;
			tElement->x3 = (*tElement->nodes.at(2)).x;

			tElement->y1 = (*tElement->nodes.at(0)).y;
			tElement->y2 = (*tElement->nodes.at(1)).y;
			tElement->y3 = (*tElement->nodes.at(2)).y;

			tElement->calculateArea();		// Efficiency could be improved by doing calculation in Mesh
			tElement->calculateAreaCentre();

			elements->push_back(tElement);
			validElements++;
			break;
		default:
			delete tElement; //unused -> delete.
			delete lElement; //unused -> delete.

			getline(in, line);
			break;
		}
	}
	*nElement = validElements;

	return filePosEqualsLine(in,"$EndElements");
}