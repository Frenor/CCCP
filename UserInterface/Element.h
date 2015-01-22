#pragma once
#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include "Node.h"

//! A data object contains element data and relevant functions
class Element
{

public:
	Element();
	~Element();

	const static int LINE = 1;
	const static int TRIANGLE = 2;
	int type;

	double area;			//!< Elements total area
	double material;		//!< Young's modulus for the element

	double ecx, ecy;		//!< Elements area centre
	double dx, dy;			//!< Distance between mesh- and node area centre

	std::vector<Node*> nodes;	//!< List of all nodes in this element

	/*!
		Calculates the area of the element.
	*/
	virtual void calculateArea() = 0;

	/*!
		Calculates the area centre of the element.
	*/
	virtual void calculateAreaCentre() = 0;

	/*!
		Calculates the second moment of area for the element.
		\param Ay Area centre of the mesh
	*/
	virtual double getSecondAreaMomentX(double) = 0;
	
	/*!
		Calculates the second moment of area for the element.
		\param Ax Area centre of the mesh
	*/
	virtual double getSecondAreaMomentY(double) = 0;

	/*!
		Calculating the product of moment of inertia
	*/
	virtual double getSecondAreaMomentProduct(double, double) = 0;
	
protected:

private:
	void deleteNodes();
};
#endif //ELEMENT_H