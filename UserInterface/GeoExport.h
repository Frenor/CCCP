#pragma once

#include "AbstractExport.h"
#include "TestLib.h"

//! A file writer providing functionaltiy for writing Gmsh's ".geo" format.
/*!
	It contains information about header file structure, but relies on AbstractExport for data export.
*/
class TEST_LIB GeoExport : public AbstractExport
{
public: 
	GeoExport(std::string, DrawModel*);
	void write();

private:
	/*!
		Write the file header
	*/
	void writeHeader();
	/*!
		Write the nodes to file
	*/
	void writePoints();
	/*!
		Write the edges to file
	*/
	void writeLines();
	/*!
		Write the line loops and surfaces to file
	*/
	void writeLineloops();
};