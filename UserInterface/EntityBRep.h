#pragma once

#include "Entity.h"
#include "BRepFactory.h"

#include "TestLib.h"

//! A data object used to hold entity data made up of several other entities
/*!
	Entity boundary representation is created by boolean operations on multiple entities. 
	The entities making up the boundary represented entity is added as child entities.
	It keep track of the child entitites's state and execute the boolean operation again if they've changed since last update.
*/
class TEST_LIB EntityBRep : public Entity
{
	Q_OBJECT
public:
	EntityBRep(Entity*, Entity*, int, QObject *parent=0);
	~EntityBRep();

	const static int SUBTRACT = 0;
	const static int ADD = 1;

	bool updateRequired;

	std::vector<Entity*> childEntities; //!< Child entities. The entities whos boundaries make this entity
	std::vector<int> operations;		//!< Operations executed on the child entities

	std::list<Entity*> resultEntities;		//!< Result entities. A boundary represented entity can consist of multiple entities if a operation splits one of the child entities.
	std::list<Entity*> resultHoleEntities;	//!< Result entities which are holes in the BRep entity.
	
	/*!
		Verify that the entity has the properties required to be converted to a regular entity.
		\return True if BRep entity safely can be converted. False otherwise
	*/
	bool safeConvertToEditableEntity();
	/*!
		Overridden Entity function to enable the entity to also update the child entities.
		The BRep entity actor is based on polygons retrieved from the result entities. 
		It is done this way to use one clickable actor for the whole boundary representation.
	*/
	void updatePolygon();
	/*!
		Creates a polygon for each result entity.
	*/
	vtkSmartPointer<vtkPolyData> getPolyData();

	void changeNode(double pos[], int){};	//!< Implemented and ignored entity functionality
	void createNode(double pos[], int){};	//!< Implemented and ignored entity functionality
	/*!
		If seeds from childEntities are returned here, the seed references will point to this entity.
		\return Always a empty vector of seeds.
	*/
	std::vector<Node*> getSeeds();

public slots:
	/*!
		Force the boolean operation to be redone if child entities change
	*/
	void setRequireUpdate();

private:
	/*!
		Executes the boolean operations on the child nodes and updates the result entities which the BRep entity is drawing.
		The boolean operations are executed by passing all the child entities to the BRepFactory, which returns the result entities.
	*/
	void updateResultEntities();
	/*!
		Retrieves nodes and edges from the resultEntities and update the boundary represented entity's nodes and edges.
	*/
	void updateNodesAndEdges();
	/*!
		Updates the entity's hole actors to the z-level of the entity. 
		In addition, it adds a distance of 0.01 between every hole actor.
	*/
	void updateHoleActors();
};