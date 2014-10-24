#include "BRepFactory.h"

BRepFactory::BRepFactory(Entity* entity)
{
	currentFace = createFaceFromEntity(entity);

	if(entity->type == Entity::BREP)
	{
		EntityBRep *BRepEntity = ((EntityBRep*)entity);
		for (int i = 1; i < BRepEntity->childEntities.size(); i++)
		{
			std::cout << "addCSGOperation from BRepEntity" << std::endl;
			addCSGOperation(BRepEntity->childEntities.at(i), BRepEntity->operations.at(i));
		}
	}
}
BRepFactory::~BRepFactory()
{
	currentFace.Nullify();
	for each (TopoDS_Shape shape in faces)
	{
		shape.Nullify();
	}
}

void BRepFactory::addCSGOperation(Entity* entity, int operation)
{
	TopoDS_Shape face = createFaceFromEntity(entity);
	faces.push_back(face);
	operations.push_back(operation);
}

TopoDS_Shape BRepFactory::createFaceFromEntity(Entity* entity)
{
	BRepBuilderAPI_MakeWire wireMaker = BRepBuilderAPI_MakeWire();

	for each (Edge *edge in entity->edges)
	{
		Node *n1 = edge->n1;
		Node *n2 = edge->n2;

		gp_Pnt point1(n1->x, n1->y, n1->z);
		gp_Pnt point2(n2->x, n2->y, n2->z);

		TopoDS_Edge aEdge1 = BRepBuilderAPI_MakeEdge(point1, point2);
		wireMaker.Add(aEdge1);
	}

	return BRepBuilderAPI_MakeFace(wireMaker.Wire());
}

void BRepFactory::perform()
{
	for (int i = 0; i < operations.size(); i++)
	{
		switch(operations.at(i))
		{
		case SUBTRACT:
			currentFace = cut(currentFace, faces.at(i));
			break;
		case ADD:
			currentFace = fuse(currentFace, faces.at(i));
			break;
		default:
			currentFace = fuse(currentFace, faces.at(i));
		}
	}
}

TopoDS_Shape BRepFactory::fuse(TopoDS_Shape face1, TopoDS_Shape face2)
{
	BRepAlgoAPI_Fuse fusedFace(face1, face2);
	if(!fusedFace.IsDone())
	{
		std::cout << "Fuse is NOT DONE" << std::endl;
	}
	//Checks if fuse has face in order to avoid null exception
	if(fusedFace.HasGenerated()){
		std::cout << "Fuse IS DONE" << std::endl;
		return getFaceFromShape(fusedFace.Shape());
	}
	return face1;
}

TopoDS_Shape BRepFactory::cut(TopoDS_Shape face1, TopoDS_Shape face2)
{
	BRepAlgoAPI_Cut cuttedFace(face1, face2);
	if(!cuttedFace.IsDone())
	{
		std::cout << "Cut is NOT DONE" << std::endl;
	}
	std::cout << "Cut IS DONE" << std::endl;

	return cuttedFace.Shape();
}

TopoDS_Face BRepFactory::getFaceFromShape(TopoDS_Shape shape)
{
	Prs3d_ShapeTool Tool(shape);
	BRepBuilderAPI_MakeWire wireMaker = BRepBuilderAPI_MakeWire();
	for (Tool.InitCurve(); Tool.MoreCurve(); Tool.NextCurve())
	{
		TopoDS_Edge edge = Tool.GetCurve();
		Standard_Integer neighbour = Tool.Neighbours(); 
		if(neighbour == 1){
			wireMaker.Add(edge);
		}
	}
	
	return BRepBuilderAPI_MakeFace(wireMaker.Wire());
}

std::vector<Edge*> BRepFactory::getEdges()
{
  std::vector<Edge*> border;
    
  //Want separate wires for holes
  for (TopExp_Explorer exp (currentFace, TopAbs_ShapeEnum::TopAbs_WIRE); exp.More(); exp.Next()) 
  {
    //std::cout << "WIRE FOUND IN FACE" << std::endl;
    TopoDS_Wire wire = TopoDS::Wire(exp.Current());

    int k = 0;
    Node *currentNode =  NULL;
    BRepTools_WireExplorer Ex;
    for(Ex.Init(wire); Ex.More(); Ex.Next())
    {
      k++;
      
      Node* newNode = createNodeFromVertex(Ex.CurrentVertex());

      if(currentNode)
      {
        Edge *edge = new Edge(currentNode, newNode);
        border.push_back(edge);
      }
      currentNode = newNode;
    }
    //std::cout << "Has vertex count: " << k << std::endl;
  }
  return border;
}

std::list<Entity*> BRepFactory::getEntities()
{
	std::list<Entity*> entities;
	
	//Want separate wires for holes
	for (TopExp_Explorer exp (currentFace, TopAbs_ShapeEnum::TopAbs_WIRE); exp.More(); exp.Next()) 
	{
		//std::cout << "WIRE FOUND IN FACE" << std::endl;
		TopoDS_Wire wire = TopoDS::Wire(exp.Current());
		
		Entity* entity = new EntityPoly;
		int nodeIds = 0;

		int k = 0;
		Node *currentNode =  NULL;
		BRepTools_WireExplorer Ex;
		for(Ex.Init(wire); Ex.More(); Ex.Next())
		{
			gp_Pnt p = BRep_Tool::Pnt(Ex.CurrentVertex());
			double pos[3] = { p.X(), p.Y(), p.Z() };

			entity->createNode(pos, -1);
			entity->nodes.back()->id = nodeIds++;

			k++;
		}
		entity->close();
		entities.push_back(entity);
		//std::cout << "Has vertex count: " << k << std::endl;
	}
	return entities;
}

double* BRepFactory::getPos(TopoDS_Vertex v)
{
	gp_Pnt point = BRep_Tool::Pnt(v);
		
	pos[0] = point.X();
	pos[1] = point.Y();
	pos[2] = point.Z();

	return pos;
}

Node* BRepFactory::createNodeFromVertex(TopoDS_Vertex v)
{
	gp_Pnt point = BRep_Tool::Pnt(v);

	Node *node = new Node();
	node->x = point.X();
	node->y = point.Y();
	node->z = point.Z();

	return node;
}

