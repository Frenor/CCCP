#pragma once
#ifndef ENTITYPOLY_H
#define ENTITYPOLY_H

#include "Entity.h"
#include "TestLib.h"

//! A type of entity representing a polygon shape. 
/*!
	It extends the abstract class entity, which hold most of the data entity data
*/
class TEST_LIB EntityPoly : public Entity
{
	Q_OBJECT
public:
	EntityPoly(QObject *parent = 0);
	~EntityPoly(){}
	EntityPoly(const EntityPoly &e, QObject *parent);

	EntityPoly* clone(QObject *parent) const;

	/*!
		Changes one of the entity's nodes based on the node id, and emits entityChanged
	*/
	void changeNode(double pos[], int);

	/*!
		Listens for clicks on seeds in entity. 
		Closes the entity if the first seed is clicked and the entity is not already closed.
	*/
	void EntityPoly::clickNode(int);
	
	/*!
		Adds a node to the entity and emits entityChanged.
	*/
	void createNode(double pos[], int);
	
	/*!
		Adds an existing node to the entity and emits entityChanged
	*/
	void useSnapNode(Node*);

	/*!
		Creates an edge between the two given, and adds the edge to the entity.
	*/
	void createEdge(Node*, Node*);

	/*!
		\return vector<Node*> containing the entity's seeds (This implies all nodes for EntityPolygon)
	*/
	std::vector<Node*> getSeeds();
};
#endif //ENTITYPOLY_H