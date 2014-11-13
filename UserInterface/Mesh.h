#pragma once
#ifndef MESH_H
#define MESH_H

#include <vector>
#include <list>

#include <qobject.h>
#include <qstring.h>
#include "Entity.h"
#include "Element.h"

//! A data object that holds mesh data.	
/*! 
	It extends entity to make the drawing more streamlined, and relies upon functions in Entity as far as possible.
	The resemblence to Entity permits the operation of converting it to a standard entity, to further edit.
*/
class Mesh : public Entity
{
	Q_OBJECT
public:
	Mesh(QObject *parent);
	/*!
		Creates a Mesh entity that is drawed in ResultController. 
		It copies the nodes and element from the MSHParser as well as the filename.
	*/
	Mesh(QString, std::vector<Node>, std::vector<Element>, QObject *parent);

	void changeNode(double pos[], int handle){}
	void createNode(double pos[], int handle){}
	std::vector<Node*> getSeeds(){return seeds; }
	std::vector<Element> getElements();
	//Entity* getEntity();

	/*!
		\return QString File name of the mesh loaded.
	*/
	QString getFileName();

	int getNumberOfNodes();
	int getNumberOfElements();
	
	/*! 
		Overridden function from Entity. 
		UpdatePolygon calls the Mesh's getPolyData() and uses it to update the entityActor.
	*/
	void updatePolygon(int);

	/*! 
		Overridden function from Entity. 
		Polydata is created based on nodes and elements instead of nodes and edges.
	*/
	vtkSmartPointer<vtkPolyData> getPolyData();

private:
	QString fileName;
	std::vector<Element> elements;
};
#endif //MESH_H