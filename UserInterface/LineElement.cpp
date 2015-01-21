#include "LineElement.h"


LineElement::LineElement() : Element()
{
	this->type = Element::LINE;
}

void LineElement::calculateAreaCentre()
{
	ecx = (x1 + x2) / 2;
	ecy = (y1 + y2) / 2;

	xl1 = x1 - ecx;
	xl2 = x2 - ecx;
	yl1 = y1 - ecy;
	yl2 = y2 - ecy;
}

void LineElement::calculateArea()
{
	area = 0;
}

double LineElement::getSecondAreaMomentX(double Ay)
{
	return 0;
}

double LineElement::getSecondAreaMomentY(double Ax)
{
	return 0;
}

double LineElement::getSecondAreaMomentProduct(double Ax, double Ay)
{
	return 0;
}