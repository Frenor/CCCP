#include <QtWidgets>
#include <QtTest/QtTest>

#include "TestCSG.h"
#include "TestEntityGeometry.h"

int main(int argc, char *argv[])
{
	TestEntityGeometry geomTest;
	QTest::qExec(&geomTest, argc, argv);

	TestCSG CSGTest;
	QTest::qExec(&CSGTest, argc, argv);


	return 0;
}