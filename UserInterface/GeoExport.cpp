#include "GeoExport.h"

GeoExport::GeoExport(std::string fileName, DrawModel* model) : AbstractExport(model)
{
	std::cout << "OpenFile" << std::endl;
	open(fileName);
}

void GeoExport::write()
{
	writeHeader();
	writePoints();
	writeLines();
	writeLineloops();
}

void GeoExport::writeHeader()
{
	std::cout << "Writing header" << std::endl;
	file << "cl__1 = 1;" << std::endl;
}

void GeoExport::writePoints()
{
	std::cout << "Writing Points [" << globalNodes.size() << "]" << std::endl;
	int i = 0;
	for each (Node* node in globalNodes)
	{
		file << "Point(" << ++i << ") = {" << node->x << ", " << node->y << ", " << node->z << ", 1};" << std::endl;
	}
}

void GeoExport::writeLines()
{
	std::cout << "Writing lines [" << globalEdges.size() << "]" << std::endl;
	int i = 0;
	for each (Edge* edge in globalEdges)
	{
		int nn1 = findGlobalNodeNumber(edge->n1);
		int nn2 = findGlobalNodeNumber(edge->n2);
		//std::cout << "Edge has " << i << "[ " << edge->n1 << ", " << edge->n2 << "] [ " << edge->n1->id << ", " << edge->n2->id << "], with: " << nn1 <<" , " << nn2 << std::endl;

		file << "Line(" << ++i << ") = {" << nn1+1 << ", " << nn2+1 << "};" << std::endl;
	}
}

void GeoExport::writeLineloops()
{
	int i = globalEdges.size();
	std::ostringstream out;

	for each (std::vector<int> lineloop in lineloops)
	{
		file << "Line Loop(" << ++i << ") = {";
		std::copy(lineloop.begin(), lineloop.end()-1, std::ostream_iterator<int>(file, ","));
		file << lineloop.back();
		file << "};" << std::endl;
		
		//std::cout << "Lineloop " << i << " has " << lineloop.size() << std::endl;
	}

	i = globalEdges.size();
	for each (int surface in surfaces)
	{
		file << "Plane Surface(" << ++i << ") = {" << i << "};" << std::endl;
	}
}
