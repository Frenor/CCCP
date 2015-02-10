#pragma once
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
//! A data object storing node data.
class Node
{
public:
	int id;			//!< Node id. Used for node ordering
	double x, y, z;
	std::vector<int> handle;		//!< Node handle used for seed interaction.

	Node() 
	{
		id = -1;
		handle.push_back(-1);
	}

	void setPosition(double pos[])
	{
		x = pos[0];
		y = pos[1];
		z = 0;

		//std::cout << "Node setPosition" << std::endl;
	}
	void addHandle(int handle)
	{
		this->handle.push_back(handle);
	}
	~Node(){ //std::cout << "Node deleted" << std::endl; 
	}
};
#endif //NODE_H