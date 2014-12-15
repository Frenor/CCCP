#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <list>
#include <qobject.h>

#include "vtkCellArray.h"
#include "vtkSmartPointer.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper.h"
#include "vtkPolygon.h"
#include "vtkActor.h"
#include "vtkTriangleFilter.h"
#include "vtkProperty.h"

#include "Node.h"
#include "Edge.h"
#include "Material.h"

#include "TestLib.h"

//! An abstract class containing methods and datafields required by all types of entities.
/*! 
	It holds information regarding shapes displayed on screen. Nodes, edges and as well as functionality common to all types of shapes.
*/
class TEST_LIB Entity : public QObject
{
	Q_OBJECT
public:
	Entity(QObject *parent);
	Entity(const Entity &, QObject *parent);
	~Entity();

	virtual Entity* clone(QObject *parent) const = 0;
	//Entity* duplicate(Entity const &, QObject*);

	const static int POLYGON = 0;
	const static int CIRCLE = 1;
	const static int RECTANGLE = 2;
	const static int BREP = 3;
	int type;			//!<Type of element. Polygon, Circle, Rectangle or shapes determined by boundary operations.

	const static int MASSIVE = 0;
	const static int THINWALLED = 1;
	int crossectionType;

	//Could be cleaner if extracted to a separate class called "EntityProperty"
	std::string name;	//!< Name of entity
	Material* material;	//!< Material

	std::vector<Node *> seeds;	//!< Tangible nodes representing the entity
	std::list<Node*> nodes;		//!< All nodes in entity
	std::list<Edge*> edges;		//!< All edges in entity

	/*! 
		Sets the name of the entity
	*/
	void setName(std::string);	
	
	/*! 
		Sets the entitytype
	*/
	void setType(int);

	/*!
		Sets the crossection type
	*/
	void setCrossectionType(int);

	/*!
		Is this the active entity (currently editing)
	*/
	void setActive(bool);

	/*! 
		Abstract function required by all entities in order to be editied by the seed widget.
		When an entity is chosen, the entity is set as the seed widget's callback and this method is called.
	*/
	virtual void changeNode(double pos[], int) = 0;	

	/*! 
		Abstract function required by all entities in order to be created. When an empty entity is created, 
		the entity is set as the seed widget's callback and this method is called.
	*/
	virtual void createNode(double pos[], int) = 0;

	/*! 
		Abstract function required by all entities in order to be drawn in the seed widget. 
		The seeds are a sub set of nodes which can be moved.
	*/	
	virtual std::vector<Node*> getSeeds() = 0;
		
	/*!
		Abstract function required by all entities in order to be displayed by the GraphicView
		Updates the PolyData and the actor.
	*/
	virtual void updatePolygon();

	/*! 
		Closes the entity if not already closed. 
		It adds an edge from the last node to the first, and sets isClosed = true.
	*/
	void close();

	/*!
		Returns true if the entity is closed. False otherwise
	*/
	bool isClosed();
	
	/*!
		Returns wether the entity is a hole or not. 
		This property is only set to true if a boundary operation has been executed.
	*/
	bool isHole();

	/*!
		Loops through edges and calculates the overall direction of the entity.
		\f$ \sum{x_2 - x_1)(y_2 + y_1)}
	*/
	bool isClockWise();

	/*!
		Return true if entity does not have nodes or edges.
	*/
	bool Entity::isEmpty();

	/*!
		Loops through all nodes, sorting them by nodeId.
		\return vector<Node*> containing nodes sorted by their given ID.
	*/
	std::vector<Node*> getNodesOrdered();
	
	/*!
		Copies edges list into a vector, for use during selection of single edge in list.
		\return vector<Edge*> containing all edges
	*/
	Edge* getEdge(int);

	/*!
		\return list<Node*> containing all nodes ordered clock wise by their ids.
	*/
	std::list<Edge*> getEdgesOrderedClockWise();
	
	/*!
		\return list<Edge*> containing all nodes ordered counter clock wise by their ids.
	*/
	std::list<Edge*> getEdgesOrderedCounterClockWise();
	
	/*!
		\return list<Edge*> containing all edges in reverted order.
	*/
	std::list<Edge*> reOrderEdges();
	
	/*!
		\return vector<vtkSmartPointer<vtkActor>> All hole actors in the entity.
	*/
	std::vector<vtkSmartPointer<vtkActor>> getHoleActors();

	/*!
		\return vtkSmartPointer<vtkActor> actor representing the polygon.
	*/
	vtkSmartPointer<vtkActor> getActor();
	
	/*!
		Returns the actor representing the entity, but also calculates the appropriate z-level
		\return vtkSmartPointer<vtkActor> actor representing the polygon. 
	*/
	vtkSmartPointer<vtkActor> getZLeveledActor(double);
	
	/*!
		Returns the polygon representing the entity shape. Used in composite entities were shape data is retrieved by this function? 
	*/
	vtkSmartPointer<vtkPolygon> getPolygon();

	/*!
		Returns the polygons representing the shape of the walls in this entity.
		\return vtkSmartPointer<vtkCellArray> collection of polygons representing the shape of the walls
	*/
	vtkSmartPointer<vtkPolygon> getWallPolygon(Edge*);
	
	/*!
		Emits entityChanged. 
		Used after a lot of data is changed in order to avoid redrawing each change.
	*/
	void doneEditing();

	/*!
		\return double Z-level where the entity lies.
	*/
	double getLevel();
		
	/*!
		Assigns the actor a Z-level.
	*/
	void setLevel(double);

	/*!
		Sets the finalized status
	*/
	void setIsFinalized(bool);
	
	/*!
		Return true if the entity is visible. Is checked before every draw.
	*/
	bool isVisible();

signals:
		
	/*!
		Fires whenever the entity contains a node which is moved or added.
	*/
	void nodeChanged();
			
	/*!
		Fires whenever a property in the entity is changed
	*/
	void entityChanged(Entity *);
	
	/*!
		Fires when a entity is finalized
	*/
	void entityFinalized();
	
public slots:
	void drawTypeChanged(int);

protected:
	bool editable;		//!<Entity is editable by the user and seed widget
	bool visible;		//!<Entity hidden or visible
	bool finalized;		//!<Done editing entity.
	bool closed;		//!<Entity is closed.
	bool hole;			//!<Entity is hole.
	bool active;		//!<Entity is the active entity
	int level;

	Node *lastSelectedNode;		//!<Last added node. Used to keep track of nodes when drawing lines in polygon
	
	vtkSmartPointer<vtkPolyData> getPolyData();
	vtkSmartPointer<vtkPolyData> getPolyDataWalled();	//!< Uses original PolyData to generate a visualisation of wall thickness
	void updateActor(vtkSmartPointer<vtkPolyData>);

	void deleteNodes();
	void deleteEdges();

	void addNode(double pos[], int);
	void createSeed(double[], int);
	void createEdge(Node*, Node*);
	void addWallToPoints(Edge*);

	vtkSmartPointer<vtkActor> actor;
	std::vector<vtkSmartPointer<vtkActor>> holeActors;
	vtkSmartPointer<vtkPoints> points;
};
#endif //ENTITY_H