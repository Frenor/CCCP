#include "TestCSG.h"

using namespace QTest;

TestCSG::TestCSG(QObject *parent) : QObject(parent)
{

}

void TestCSG::initTestCase()
{
	double trianglePos1[] = {3.0, 0.0};
	double trianglePos2[] = {0.0, 3.0};
	double origPos[] = {0.0, 0.0};
	double edgePos[] = {1.0, 0.0};
	
	circleEntity = new EntityCircle;
	circleEntity->createNode(origPos, -1);
	circleEntity->createNode(edgePos, -1);

	polyEntity = new EntityPoly;
	polyEntity->createNode(origPos, -1);
	polyEntity->createNode(trianglePos1, -1);
	polyEntity->createNode(trianglePos2, -1);
	polyEntity->close();

	std::cout << "ClockWise: [Circle,Poly]: [" << circleEntity->isClockWise() << ", " << polyEntity->isClockWise() << "] \n";
}

void TestCSG::testAddDefault()
{
	pFactory = new BRepFactory(circleEntity);
	pFactory->addCSGOperation(polyEntity, BRepFactory::ADD);

	qDebug() << "Perform: " << "\n";
	pFactory->perform();

	edges = pFactory->getEdges();
	qDebug() << "EDGES-Size: " << edges.size() << "\n";
	QVERIFY(edges.size() > 0);

	saveEntitiesToFile("TestCSG_AddDefault");
}

void TestCSG::testCutDefault()
{
	pFactory = new BRepFactory(circleEntity);
	pFactory->addCSGOperation(polyEntity, BRepFactory::SUBTRACT);

	qDebug() << "Perform: " << "\n";
	pFactory->perform();

	edges = pFactory->getEdges();
	qDebug() << "EDGES-Size: " << edges.size() << "\n";
	QVERIFY(edges.size() > 0);

	saveEntitiesToFile("TestCSG_CutDefault");
}

void TestCSG::testCutClean()
{
	double quad1[] = { 1.0, -0.5};
	double quad2[] = {-1.0, -0.5};
	double quad3[] = {-1.0, 0.5};
	double quad4[] = { 1.0, 0.5};

	double origPos[] = {0.0, 0.0};
	double edgePos[] = {1.0, 0.0};
	
	circleEntity = new EntityCircle;
	circleEntity->createNode(origPos, -1);
	circleEntity->createNode(edgePos, -1);

	polyEntity = new EntityPoly;
	polyEntity->createNode(quad1, -1);
	polyEntity->createNode(quad2, -1);
	polyEntity->createNode(quad3, -1);
	polyEntity->createNode(quad4, -1);
	polyEntity->close();

	pFactory = new BRepFactory(circleEntity);
	pFactory->addCSGOperation(polyEntity, BRepFactory::SUBTRACT);

	pFactory->perform();
	saveEntitiesToFile("TestCSG_CutThrough");
}

void TestCSG::testCutHole()
{
	double quad1[] = { 0.5, -0.5};
	double quad2[] = {-0.5, -0.5};
	double quad3[] = {-0.5, 0.5};
	double quad4[] = { 0.5, 0.5};

	double origPos[] = {0.0, 0.0};
	double edgePos[] = {1.0, 0.0};
	
	circleEntity = new EntityCircle;
	circleEntity->createNode(origPos, -1);
	circleEntity->createNode(edgePos, -1);

	polyEntity = new EntityPoly;
	polyEntity->createNode(quad1, -1);
	polyEntity->createNode(quad2, -1);
	polyEntity->createNode(quad3, -1);
	polyEntity->createNode(quad4, -1);
	polyEntity->close();

	pFactory = new BRepFactory(circleEntity);
	pFactory->addCSGOperation(polyEntity, BRepFactory::SUBTRACT);

	pFactory->perform();
	saveEntitiesToFile("TestCSG_CutHole");
}

void TestCSG::testAddBug()
{
	double quad1[] = { 2.0, 2.0};
	double quad2[] = {0, 0.5};
	double quad3[] = {0.5, 0};

	double origPos[] = {0.0, 0.0};
	double edgePos[] = {1.0, 0.0};

	circleEntity = new EntityCircle;
	circleEntity->createNode(origPos, -1);
	circleEntity->createNode(edgePos, -1);

	polyEntity = new EntityPoly;
	polyEntity->createNode(quad1, -1);
	polyEntity->createNode(quad2, -1);
	polyEntity->createNode(quad3, -1);
	polyEntity->close();

	pFactory = new BRepFactory(circleEntity);
	pFactory->addCSGOperation(polyEntity, BRepFactory::ADD);

	pFactory->perform();
	saveEntitiesToFile("TestCSG_AddBug");
}

void TestCSG::testAddBugEntity()
{
	double quad1[] = { 2.0, 2.0};
	double quad2[] = {0.5, 0};
	double quad3[] = {0, 0.5};

	double origPos[] = {0.0, 0.0};
	double edgePos[] = {1.0, 0.0};

	circleEntity = new EntityCircle;
	circleEntity->createNode(origPos, -1);
	circleEntity->createNode(edgePos, -1);

	polyEntity = new EntityPoly;
	polyEntity->createNode(quad1, -1);
	polyEntity->createNode(quad2, -1);
	polyEntity->createNode(quad3, -1);
	polyEntity->close();

	EntityBRep * entity = new EntityBRep(circleEntity, polyEntity, BRepFactory::ADD);
	DrawModel *drawModel = new DrawModel(this);

	int i = 0;
	for each (Entity *entity in pFactory->getEntities())
	{
		qDebug() << "ENTITY["<< i++ <<"]: Edges size: " << entity->edges.size() << "Nodes size: " <<  entity->nodes.size() <<"\n";
		drawModel->entities.push_back(entity);
		drawModel->activeEntity = entity;
	}
	
	saveFile("TestCSG_AddBugEntity", drawModel);
}

void TestCSG::testEntityBRep()
{
	initTestCase();

	qDebug() << "TestEntity BREP \n";

	EntityBRep * entity = new EntityBRep(circleEntity, polyEntity, BRepFactory::SUBTRACT);
	DrawModel *drawModel = new DrawModel(this);

	int i = 0;
	for each (Entity *entity in pFactory->getEntities())
	{
		qDebug() << "ENTITY["<< i++ <<"]: Edges size: " << entity->edges.size() << "Nodes size: " <<  entity->nodes.size() <<"\n";
		drawModel->entities.push_back(entity);
		drawModel->activeEntity = entity;
	}
	
	saveFile("TestCSG_BREP", drawModel);
}

void TestCSG::saveEntitiesToFile(std::string fileName)
{
	DrawModel *drawModel = new DrawModel(this);

	int i = 0;
	for each (Entity *entity in pFactory->getEntities())
	{
		qDebug() << "ENTITY["<< i++ <<"]: Edges size: " << entity->edges.size() << "Nodes size: " <<  entity->nodes.size() <<"\n";
		drawModel->entities.push_back(entity);
		drawModel->activeEntity = entity;
	}
	
	saveFile(fileName, drawModel);
}

void TestCSG::saveFile(std::string fileName, DrawModel* DrawModel)
{
	GeoExport expo(fileName+".geo", DrawModel);
	expo.write();
	expo.save();
}