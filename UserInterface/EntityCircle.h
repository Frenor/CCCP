#pragma once 
#ifndef ENTITYCIRCLE_H
#define ENTITYCIRCLE_H

#define _USE_MATH_DEFINES

#include "Entity.h"
#include <math.h>

#include "TestLib.h"

//!	An type of entity that represents a circle shape. It extends the abstract class entity, which hold most of the data
class TEST_LIB EntityCircle : public Entity
{
	Q_OBJECT
public:
	EntityCircle(QObject *parent = 0);
	~EntityCircle(){}
	EntityCircle(const EntityCircle &e, QObject *parent);

	EntityCircle* clone(QObject *parent) const;

	int segmentNum; //!< Number of segments used to draw and mesh this circle.

	/*!
		Creates a seed if the entity has less than two seeds. \n
		If first seed; create seed. \n
		If second seed; create seed and create circle edges based on the positon of the two seeds.
	*/
	void createNode(double[], int);
	/*!
		Changes the node and updates the circle edges.
	*/
	void changeNode(double[], int);
	/*!
		\return vector<Node*> containing the two seeds used to control a circle shape
	*/
	std::vector<Node*> getSeeds();
	
	/*!
		Clears the current nodes and edges. 
		Calculates the circle radius by: \n
		\f$ dx = Seed_{1x} - Seed_{2x} \f$ \n
		\f$ dy = Seed_{1y} - Seed_{2y} \f$ \n

		Positions for the nodes along the circle is then calculated by: \n
		\f$ Node(i)_x = getCentre()->x + r * cos{(startAngle + stepSize*i)} \f$, \n 
		\f$ Node(i)_y = getCentre()->y + r * sin{(startAngle + stepSize*i)} \f$ \n

		with step size being a size calculated by; \n
		\f$ stepSize = 2 * \frac{\pi}{numberOfSteps} \f$  
	*/
	void createCircleBorder();
	/*!
		\return the first seed representing the centre of the circle.
	*/
	Node* getCentre();

	/*!
		\return the second seed representing the position of the circles edge
	*/
	Node* getEdge();
	/*!
		Calculates the radius of the circle, given the two seeds defining the circle.
	*/
	double getRadius();

	void useSnapNode(Node*){};			//!< Implemented and ignored entity functionality

private:
	/*!
		Deletes the node and edge data making the circle shape. \n
		The seeds will be intact.
	*/
	void reset();
};
#endif //ENTITYCIRCLE_H