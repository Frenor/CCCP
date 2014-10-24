#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "DrawModel.h"

#include "TestLib.h"

//! Abstract class providing a general interface for data extracted from the draw model.
/*!
	It is done this way to make extended file format support easier.

	It exports all nodes and edges present in the model. 
	The edges and nodes are numbered within each node, and the class reenumerate these into a "global" system.
*/
class TEST_LIB AbstractExport {
public:
	AbstractExport(DrawModel*);
	~AbstractExport();

	/*!
		Opens an output file stream to the given filename.
		Everything sent to this file stream is saved to the file.
	*/
	bool open(std::string);
	/*!
		Close the opened file stream, releasing the write lock.
	*/
	void save();

protected:
	std::ofstream file;							//!< File stream with data written to file
	std::vector<Node*> globalNodes;				//!< All nodes in model reenumerated with a global value
	std::vector<Edge*> globalEdges;				//!< All edges in model reenumerated with a global value
	std::vector<std::vector<int>> lineloops;	//!< Line loops/wires in model
	std::vector<int> surfaces;					//!< Surfaces in the model
	std::map<Node*, int> nodeLookupTable;		//!< Table containing mapping a node reference to its global number.

	/*!
		Find the global node number given a node reference, 
		and an already computed map with node references and global number.
	*/
	int findGlobalNodeNumber(Node*);

private:
	/*!
		All nodes in model
	*/
	void createGlobalNodes(std::vector<Node*>);
	/*!
		All edges in model
	*/
	void createGlobalEdges(std::vector<Edge*>);

	/*!
		All edges in model grouped in line loops connecting nodes by their global number.
		It is done for each entity, 
		and uses the map with node reference and numbering to create the loops.
	*/
	void createLineloops(std::list<Entity*>);

	virtual void write() = 0;
};
