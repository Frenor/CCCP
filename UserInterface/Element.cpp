#include "Element.h"

void Element::calculateArea()
{
	//MatrixXd J(2,2);

	//MatrixXd XY(2,3);
	//XY << x1, x2, x3, 
	//	  y1, y2, y3;

	//MatrixXd dNdx(3,2);
	//dNdx << 1, 0,
	//	    0, 1,
	//	   -1,-1;

	//J << XY * dNdx;
	//area = abs(0.5 * J.determinant());
}

void Element::calculateAreaCentre()
{
	ecx = (x1 + x2 + x3)/3;
	ecy = (y1 + y2 + y3)/3;
	
	xl1 = x1 - ecx;
	xl2 = x2 - ecx;
	xl3 = x3 - ecx;
	yl1 = y1 - ecy;
	yl2 = y2 - ecy;
	yl3 = y3 - ecy;
}

double Element::getSecondAreaMomentX(double Ay)
{
	double weight[3] = {1.0/3, 1.0/3, 1.0/3};
	double xg[3] = {2.0/3, 1.0/6, 1.0/6};
	double yg[3] = {1.0/6, 2.0/3, 1.0/6};

	Iex = 0;
	for (int j = 0; j < 3; j++)
	{
		for(int i = 0; i < 3; i++)
		{
			double g2 = y1 + (y2-y1)*xg[i] + (y3-y1)*yg[j];
			
			Iex += weight[1]*weight[1] *(g2*g2 - 1.0/3);
		}
	}
	
	dy = (Ay - ecy);
	return  2*area*Iex + dy*dy*area;
}

double Element::getSecondAreaMomentY(double Ax)
{
	double weight[3] = {1.0/3, 1.0/3, 1.0/3};
	double xg[3] = {2.0/3, 1.0/6, 1.0/6};
	double yg[3] = {1.0/6, 2.0/3, 1.0/6};

	Iey = 0;
	for (int j = 0; j < 3; j++)
	{
		for(int i = 0; i < 3; i++)
		{
			double g1 = x1 + (x2-x1)*(xg[i]) + (x3-x1)*yg[j];
			Iey += weight[1]*weight[1] *(g1*g1 - 1.0/3);
		}
	}

	dx = (Ax - ecx);
	return 2*area*Iey + dx*dx*area;
}

double Element::getSecondAreaMomentProduct(double Ax, double Ay)
{
	double weight[3] = {1.0/3, 1.0/3, 1.0/3};
	double xg[3] = {2.0/3, 1.0/6, 1.0/6};
	double yg[3] = {1.0/6, 2.0/3, 1.0/6};

	Iexy = 0;
	for (int j = 0; j < 3; j++)
	{
		for(int i = 0; i < 3; i++)
		{
			double g1 = x1 + (x2-x1)*(xg[i]) + (x3-x1)*yg[j];
			double g2 = y1 + (y2-y1)*xg[i] + (y3-y1)*yg[j];

			Iey += weight[1]*weight[1] *(g1*g2 - 1.0/3);
		}
	}

	dy = (Ay - ecy);
	dx = (Ax - ecx);
	return 2*area*Iexy + dx*dy*area;
}
