#pragma once
#ifndef LINEELEMENT_H
#define LINEELEMENT_H

#include "Element.h"
class LineElement :	public Element
{
public:
	LineElement();

	double x1, x2;		//!< Elements nodepositions in x-directions
	double y1, y2;		//!< Elements nodepositions in y-directions
	
	double xl1, xl2;
	double yl1, yl2;

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
};
#endif //LINEELEMENT_H
