#pragma once

#include <TopoDS.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <TopLoc_Location.hxx>

#include <TopExp_Explorer.hxx>
#include <BRepTools_WireExplorer.hxx>
#include <TopAbs_ShapeEnum.hxx>

#include <gp.hxx>
#include <gp_Pnt.hxx>

#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <BRep_Tool.hxx>

#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>

#include <Prs3d_ShapeTool.hxx>
#include <ShapeFix_Wire.hxx>
#include <ShapeFix_Face.hxx>

#include "Entity.h"
#include "EntityPoly.h"
#include "EntityBRep.h"
#include "TestLib.h"

//! An adapter connecting the application with openCASCADE, used when boolean operations are executed.
/*!
	It takes two entities and an operation and returns one or several new entities.
	The class is only used inside EntityBRep when updating resultEntities.
*/
class TEST_LIB BRepFactory
{

public:
	//Available operations
	const static int SUBTRACT = 0; 
	const static int ADD = 1;

	std::vector<TopoDS_Shape> faces;	//!< Vector holding one or more faces to be performed operations on.
	std::vector<int> operations;		//!< vector holding one or more operations to be performed.

	TopoDS_Shape currentFace; //!< Shape class holding the current faces. Cut operations might create more than one face.
	
	/*!
		Adding the main entity on which operations are performed.
	*/
	BRepFactory(Entity*);
	~BRepFactory();

	/*!
		Adds secondary entity and operation to the list of entities that are used to either add or cut the main entity.
		Nothing is done before perform() is called.
	*/
	void addCSGOperation(Entity*, int);

	/*!
		Loops through faces and either adds or subtracts the face from the currentFace 
	*/
	void perform();
	
	/*!
		Converting the currentFace to entities. It loops through the wires
		\return list<Entity*> Containing entities resulting from the boolean operations
	*/
	std::list<Entity*> getEntities();
	
	/*!
		Gets all edges after the boolean operation. Only used in tests to verify result before data is exported to entities.
		\return vector<Edge*> Edges in face after boolean operation
	*/
	std::vector<Edge*> getEdges();

private:
	double pos[3];
	
	/*!
		Creates as face in the openCASCADE format fromt he entity given as argument.
		It lookps through all the edges in the entity and creates a wire. This wire is made a face.
	*/
	TopoDS_Shape createFaceFromEntity(Entity*);
	
	/*!
		Wrapper for the BRepAlgoAPI. 
		It checks if the fuse has a result and converts the resulting shape to face.
		The resulting face is not one consistent face, but instead two faces and as well as a face that represents the intersection between the two faces fused.
		
		\return TopoDS_Shape containing one face
	*/
	TopoDS_Shape fuse(TopoDS_Shape face1, TopoDS_Shape face2);
	
	/*!
		Wrapper for the BRepAlgoAPI. 
		It performs the cut and returns a shape containing cut faces.
		
		\return TopoDS_Shape containing one or more faces
	*/
	TopoDS_Shape cut(TopoDS_Shape face1, TopoDS_Shape face2);

	/*!
		Used in fuse to merge several faces into one face. 
		It is performed by looping through the wires in each face, determining which edges are outside. 
		All the edges outside are added to a new wire representing the outer wire, and the merged face.
		
		\return TopoDS_Face containing only one face
	*/
	TopoDS_Face getFaceFromShape(TopoDS_Shape shape);

	/*!
		Gets the position of a point in the openCASCADE as a double array.
		\return double[3]
	*/
	double* getPos(TopoDS_Vertex);

	/*!
		Duplicates the information from an openCASCADE node into a node used in this program.
		\return Node*
	*/
	Node* createNodeFromVertex(TopoDS_Vertex);
};