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

Element MSHParser::getElementAt(int e){
	return elements[e];
}

std::vector<Element> MSHParser::getElements()
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

bool MSHParser::readElements(std::ifstream& in, std::vector<Element> *elements, int *nElement)
{
	readInt(in, nElement);

	//Unused
	int elementNumber, validElements = 0;
	int type, args, unusedTag;
	int n1,n2,n3;

	for(int e = 0; e< *nElement; e++)
	{
		readInt(in, &elementNumber);
		readInt(in, &type);
		switch (type)
		{
		case 1: //2-node line
			getline(in, line);
			break;
		case 2: //3-node triangle.
			Element element;

			readInt(in, &args);
			readDouble(in, &element.material);
			for (int i = 0; i < args - 1; i++)
			{
				readInt(in, &unusedTag);
			}

			readInt(in, &n1);
			readInt(in, &n2);
			readInt(in, &n3);

			element.i = &nodes[n1 - 1];
			element.j = &nodes[n2 - 1];
			element.k = &nodes[n3 - 1];

			element.x1 = (*element.i).x;
			element.x2 = (*element.j).x;
			element.x3 = (*element.k).x;

			element.y1 = (*element.i).y;
			element.y2 = (*element.j).y;
			element.y3 = (*element.k).y;

			element.calculateArea();		// Efficiency could be improved by doing calculation in Mesh
			element.calculateAreaCentre();

			(*elements).push_back(element);
			validElements++;
			break;
		default:
			getline(in, line);
			break;
		}
	}
	*nElement = validElements;

	return filePosEqualsLine(in,"$EndElements");
}