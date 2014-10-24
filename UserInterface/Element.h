#pragma once

#include <vector>
#include "Node.h"

//! A data object contains element data and relevant functions
class Element
{

public:
	Node *i;
	Node *j;
	Node *k;

	double area;		//!< Elements total area
	double material;	//!< Young's modulus for the element

	double Iex;		//!< Elements second area moment x
	double Iey;		//!< Elements second area moment y
	double Iexy;	//!< Elements second area moment product

	double xl1;
	double xl2;
	double xl3;
	double yl1;
	double yl2;
	double yl3;

	double ecx, ecy;		//!< Elements area centre
	double dx, dy;			//!< Distance between mesh- and node area centre

	double x1, x2, x3;		//!< Elements nodepositions in x-directions
	double y1, y2, y3;		//!< Elements nodepositions in x-directions

	/*!
		Calculates the area of the element. \n
		\f$ A_e = \frac{1}{2} \cdot |J| \f$
	*/
	void calculateArea();

	/*!
		Calculates the area centre of the element. \n
		\f$ ec_x = \frac{x1 + x2 + x3}{3} \f$ \n
		\f$ ec_y = \frac{y1 + y2 + y3}{3} \f$
	*/
	void calculateAreaCentre();

	/*!
		Calculates the second moment of area for the element.
		\param Ay Area centre of the mesh

		\f$ dy_e = A_y - Ac_{ey} \f$ \n
		\f$ I_x = \sum{( I_{x_e} + dy_e^2*A_e) } \f$ 
	*/
	double getSecondAreaMomentX(double);
	
	/*!
		Calculates the second moment of area for the element.
		\param Ax Area centre of the mesh

		\f$ dx_e = A_x - Ac_{ex} \f$ \n
		\f$ I_y =  \sum{(I_{y_e} + dx_e^2*A_e)} \f$ 
	*/
	double getSecondAreaMomentY(double);

	/*!
		Calculating the product of moment of inertia

		\f$ dx_e = Ac_x - Ac_{ex} \f$ \n
		\f$ dy_e = Ac_y - Ac_{ey} \f$ \n
		\f$ I_{xy} = \sum{(I_{xy_e} + dx_e*dy_e*A_e)} \f$ 
	*/
	double getSecondAreaMomentProduct(double, double);
	
	/*!
		Creates a vector with node numbers that makes up the element.
		\return Vector<Int> containing element nodes.
	*/
private:
};
