#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <string>
#include <vector>
#include <qobject.h>

#include "Node.h"
#include "Element.h"
#include "TestLib.h"

//! A parser for interpreting meshes structured in the ".msh" format
class TEST_LIB MSHParser : public QObject
{
	Q_OBJECT
public:
	/*!
		\param String Filename of the file to parse.
		> Excluding the file type (ending)
	*/
	MSHParser(QObject *parent, std::string);
	
	/*!
		\return vector<Element> containing all valid elements parsed from file
	*/
	std::vector<Element> getElements();
	
	/*!
		\return vector<Node> containing all nodes parsed from file
	*/
	std::vector<Node> getNodes();

	/*!
		\return number of nodes
	*/	
	int getNumberOfNodes();
		
	/*!
		\return number of elements
	*/
	int getNumberOfElements();

	/*!
		\return name of parsed file
	*/
	std::string getFilename();

	/*!
		\return Element at the given position
	*/
	Element MSHParser::getElementAt(int);
	/*!
		\return Node at the given position
	*/
	Node MSHParser::getNodeAt(int);

private:
	std::string fileName;
	int nNodes;						//!< Number of nodes read from file
	int nElements;					//!< Number of valid elements read from file
	std::string line;				//!< Data on line in current position in file
	std::vector<Element> elements;	//!< Vector containing all elements
	std::vector<Node> nodes;		//!< Vector containing all nodes

	/*!
		Interprets the mesh data in the datastream and creates two vectors, 
		containing nodes and elements respectively.
	*/
	void load_msh(std::ifstream&);
	/*!
		Reads and verifies the data format in the format section of file.
		\return true if header and version is correct, \n else false
	*/
	bool readMeshFormat(std::ifstream&, double*);
	
	/*!
		Reads the section of file containg element definitions, and creates a vector containing all supported elements. \n
		Currently, only triangle elements are supported. All other elements is ignored.
	*/
	bool readElements(std::ifstream&, std::vector<Element> *, int*);
	
	/*!
		Reads the section of file containing node definitions and create a vector.
	*/
	bool readNodes(std::ifstream&, std::vector<Node> *, int *);

	void readInt(std::ifstream&, int *);
	void readDouble(std::ifstream&, double*);
	bool filePosEqualsLine(std::ifstream&, std::string);
};
