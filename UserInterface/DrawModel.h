#pragma once
#include <vector>

#include <qstring.h>
#include <qobject.h>
#include <vtkSmartPointer.h>

#include "Element.h"
#include "Edge.h"
#include "Node.h"
#include "EntityPoly.h"
#include "EntityCircle.h"
#include "BRepFactory.h"
#include "EntityBRep.h"
#include "EntityOperation.h"
#include "EntityDialog.h"
#include "DimensionDialog.h"

#include "TestLib.h"

//! Data model containing entity data and functions to manipulate entity data. 
/*!
	It also keeps track of the selected entity.
	Because the model manipulates the entity data, it also supply and implements the tools made for drawing sections. (Entity operations)
*/
class TEST_LIB DrawModel : public QObject
{
	Q_OBJECT
public:
	static const int MASSIVE = 1;
	static const int THINWALLED = 2;

	explicit DrawModel(QObject *parent);
	~DrawModel() { std::cout << "DELETED: DrawModel" << std::endl; }

	Entity *activeEntity;			//!< Reference to the selected entity. It is active for input. NULL if none selected
	bool activeEntityFinalized;		//!< State of active entity. The seed widget is shown if false.

	std::list<Entity*> entities;	//!< Entities in model

	/*!
		Loops trough all entities creating a vector of all the nodes
		\return vector<Node*> All nodes in entities
	*/
	std::vector<Node*> getAllNodes();
	/*!
		Loops trough all entities creating a vector of all the edges
		\return vector<Node*> All edges in entities
	*/
	std::vector<Edge*> getAllEdges();

	/*!
		Creates an empty entity of type polygon and adds the entity to the model
	*/
	void createEntityPolygon();
	/*!
		Creates an empty entity of type circle and adds the entity to the model
	*/
	void createEntityCircle();

	/*!
		Adds the given entity to the list of entities and connects the entity signals to the model.
		It also assigns the entity a depth level to which it is rendered.
		The added entity is always set as the selected entity.
	*/
	void addEntity(Entity*);

	/*!
		Sets the active/selected entity to the given entity.
	*/
	void setActiveInput(Entity*);
	/*!
		Deletes the active/selected entity.
	*/
	void deleteActiveEntity();
	/*!
		Removes the given entity from the model and deletes it.
	*/
	void deleteEntity(Entity *);
	/*!
		Removes the given entity from the model 
		and updates the entity depth levels of the remaining entities.
	*/
	void removeEntity(Entity *);
	/*!
		Checks wether the given entity is selected.
		\return bool True if active entity
	*/
	bool isActiveEntity(Entity *);
	/*!
		Checks wether the given entity is not selected.
		\return bool True if NOT active entity
	*/
	bool isNotActiveEntity(Entity *);

public slots:
	/*!
		Called whenever UI mode changes.
		It unselects any selected entity and deletes all unfinished(not closed) entities.
	*/
	void uiModeChanged();
	/*!
		Listens for changes in any entity and fire entity changed signal
	*/
	void setEntityChanged(Entity *);
	/*!
		Function closes active entity and unselects it.
	*/
	void finalizeActiveEntity();
	/*!
		Unselects any active/selected entity
	*/
	void setActiveEntityNULL();
	/*!
		Listener for entity operations. Called if the correct sequence is completed.
		It creates an entity boundary representation based on data extracted from the entity operation.

		The entity boundary representation is added to the model, 
		and the entities now part of the new entity is removed from the model.
	*/
	void executeEntityOperation(EntityOperation* eOperation);
	
	/*!
		Display property window for an entity. 
		The entity to display is either given by an argument or by the active entity set in model.
	*/
	void showProperties(Entity*);

	/*!
	Display dimensions window for an entity.
	The entity to display is either given by an argument or by the active entity set in model.
	*/
	void showDimensions(Entity*);

	/*!
		Sets the drawing type to the given input value
	*/
	void setDrawType(int);

	/*!
		\return integer representing the active draw type
	*/
	int getActiveDrawType();

signals:
	void entityCreated(Entity*);		//!< Emitted when a entity is created and added to the model
	void entityChanged(Entity*);		//!< Emitted when a entity in the model is changed
	void entityDeleted(Entity*);		//!< Emitted when a entity in the model is removed
	void activeEntityChanged(Entity*);	//!< Emitted when the active/selected entity is changed
	void drawTypeChanged(int);			//!< Emitted when the drawing type is changed

private:
	/*!
		Function loops through the list of entities assigning each entity a number given its place in the list.
		The level is used inside the entity, before it is drawn, when its actor's position is calculated.
	*/
	void updateEntityLevels();
	int activeType;						//!< Active drawing type

};
