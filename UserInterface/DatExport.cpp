#include "DatExport.h"


DatExport::DatExport(std::string fileName, DrawModel* model) : AbstractExport(model)
{
	std::cout << "OpenDatFile" << std::endl;
	open(fileName);
}

void DatExport::write()
{
	writeDimensions();
}

void DatExport::writeDimensions()
{
	std::cout << "Writing dimensions [" << globalEdges.size() * 2 << "]" << std::endl;
	int i = 0;
	for each (Edge* edge in globalEdges)
	{
		//int nn1 = findGlobalNodeNumber(edge->n1);
		//int nn2 = findGlobalNodeNumber(edge->n2);
		//std::cout << "Edge has " << i << "[ " << edge->n1 << ", " << edge->n2 << "] [ " << edge->n1->id << ", " << edge->n2->id << "], with: " << nn1 <<" , " << nn2 << std::endl;

		file << "Width(" << ++i << ") = {" << edge->width1 << ", " << edge->width2 << "};" << std::endl;
	}
}