#pragma once

#include <qobject.h>
#include "Entity.h"

//! The class is an independent operations tracker that is connected to the model.
/*!
	It is extracted into a separate class to better control the feature, and make use of Qt's signal/slots to be loosly coupled from the model.
	The class, when active listens for user selections. Entity and operation selections are saved until a click outside an entity is carried out. 
	If two entities and an operation are selected, an execute signal is emitted, and the operation is executed by the model.
*/
class EntityOperation : public QObject
{
	Q_OBJECT
public:
	EntityOperation(QObject*, QObject *parent);
	~EntityOperation(){ std::cout << "DELETED: EntityOperation" << std::endl; }

	Entity *entity1;	//!< Reference to the first entity selected.
	Entity *entity2;	//!< Reference to the second and any later entity until operation is reset or executed
	int operation;		//!< Active operation selected
	bool locked;		//!< Operation is locked while it is executed

	/*!
		Check to verify that all data is set to carry out an operation
		\return bool. True if all data is set. False otherwise
	*/
	bool hasValidOperation();
	/*!
		Reset the operation.
		Sets entity references to NULL, and operation to -1.
	*/
	void resetOperation();

public slots:
	/*!
		Adds the given entity to the operation if it matches the criterias.
		It can't be NULL (NULL resets the operation), and not already selected.
	*/
	void newSelection(Entity* entity);
	/*!
		Sets the active operation to be executed if two entities are selected.
	*/
	void setEntityOperation(int operation);

	/*!
		Called if an entity is deleted, and removes the entity from operation.
	*/
	void removeEntity(Entity*);

signals:
	void execute(EntityOperation*);		//!< emitted if two entities and an operation are selected

private:
	/*!
		Emits execute signal if it is a valid operation and resets the operation.
	*/
	void execute();
};