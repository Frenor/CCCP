#pragma once
#include "AbstractExport.h"

//! A file writer providing functionaltiy for writing a custom ".dat" format.
/*!
	It contains information about header file structure, but relies on AbstractExport for data export.
*/
class DatExport : public AbstractExport
{
public:
	DatExport(std::string, DrawModel*);
	void write();

private:
	/*!
	Write the properties of edges ordered like nodes on edge
	*/
	void writeDimensions();
};

