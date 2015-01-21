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
		++i;
		if (edge->width1 && edge->width2){
			file << "Width(" << i << ") = {" << edge->width1 << ", " << edge->width2 << "};" << std::endl;
		}
	}
}