#include <QtTest/QtTest>
#include "qobject.h"

#include "MSHParser.h"
#include "VTKParser.h"

class TestParser : public QObject
{
	Q_OBJECT
public: 
	std::string meshTest1;
	std::string meshTest2;

	std::string vtkTest1;
	std::string vtkTest2;

	TestParser(QObject *parent = 0);
	~TestParser(){}

private slots:
    void testVerifyMeshNumbers();
	void testVerifyNodeIds();

private:
	void verifyMSHNumbers(std::string, int , int);
	bool uniqueIds(MSHParser *);
};