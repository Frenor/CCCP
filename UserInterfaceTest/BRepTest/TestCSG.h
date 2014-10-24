#include <QtTest/QtTest>
#include "qobject.h"

#include "EntityPoly.h"
#include "EntityCircle.h"
#include "Entity.h"
#include "EntityBRep.h"

#include "BRepFactory.h"
#include "DrawModel.h"
#include "GeoExport.h"

#include "vtkSmartPointer.h"
#include "vtkPolyData.h"

class TestCSG : public QObject
{
	Q_OBJECT
public:
	Entity *circleEntity;
	Entity *polyEntity;
	BRepFactory *pFactory;

	//Result
	std::vector<Edge*> edges;

	TestCSG(QObject *parent = 0);
	~TestCSG(){}

private slots:
	void initTestCase();

	void testAddDefault();
	void testCutDefault();

	void testCutClean();
	void testCutHole();

	void testEntityBRep();

	void testAddBug();
	void testAddBugEntity();

private:
	void saveEntitiesToFile(std::string);
	void saveFile(std::string, DrawModel*);

};