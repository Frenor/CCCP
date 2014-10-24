#include <QtTest/QtTest>
#include "qobject.h"

#include "EntityPoly.h"
#include "EntityCircle.h"
#include "Entity.h"

class TestEntityGeometry : public QObject
{
	Q_OBJECT

public:
	TestEntityGeometry(QObject *parent = 0);
	~TestEntityGeometry(){}

	Entity *circleEntity;
	Entity *polyEntity;

private slots:
	void initTestCase();
	void testClockWiseCircle();
	void testClockWisePolygon();

	void testRevertEntities();

private:
	void setup();
};