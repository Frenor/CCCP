#include "TestEntityGeometry.h"


using namespace QTest;

TestEntityGeometry::TestEntityGeometry(QObject *parent) : QObject(parent)
{

}

void TestEntityGeometry::setup()
{
	double trianglePos1[] = {1.5, 0.0};
	double trianglePos2[] = {0.0, 1.5};
	double origPos[] = {0.0, 0.0};
	double edgePos[] = {1.0, 0.0};

	circleEntity = new EntityCircle;	//Counter ClockWise
	circleEntity->createNode(origPos, -1);
	circleEntity->createNode(edgePos, -1);
	//circleEntity->edges = circleEntity->getEdgesOrderedCounterClockWise();

	polyEntity = new EntityPoly;		//ClockWise
	polyEntity->createNode(origPos, -1);
	polyEntity->createNode(trianglePos2, -1);
	polyEntity->createNode(trianglePos1, -1);
	polyEntity->close();
}

void TestEntityGeometry::initTestCase()
{
	setup();
}

void TestEntityGeometry::testClockWiseCircle()
{
	qDebug() << "Circle is clockWise: " << circleEntity->isClockWise() << "\n";
	QVERIFY(!circleEntity->isClockWise());
}

void TestEntityGeometry::testClockWisePolygon()
{
	qDebug() << "Polygon is clockWise: " << polyEntity->isClockWise() << "\n";
	QVERIFY(polyEntity->isClockWise());
}

void TestEntityGeometry::testRevertEntities()
{
	polyEntity->getEdgesOrderedCounterClockWise();
	//QVERIFY(!polyEntity->isClockWise());
	//polyEntity->edges = polyEntity->getEdgesOrderedClockWise();
	//QVERIFY(polyEntity->isClockWise());

	/*circleEntity->edges = circleEntity->getEdgesOrderedClockWise();
	QVERIFY(circleEntity->isClockWise());
	circleEntity->edges = circleEntity->getEdgesOrderedCounterClockWise();
	QVERIFY(!circleEntity->isClockWise());*/
}