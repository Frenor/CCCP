#pragma once

#include <iostream>
//! A data object storing node data.
class Node
{
public:
	int id;			//!< Node id. Used for node ordering
	double x, y, z;
	int handle;		//!< Node handle used for seed interaction.

	Node() 
	{
		id = -1;
		handle = -1;
	}

	void setPosition(double pos[])
	{
		x = pos[0];
		y = pos[1];
		z = 0;

		//std::cout << "Node setPosition" << std::endl;
	}
	~Node(){ //std::cout << "Node deleted" << std::endl; 
	}
};