#include "TestParser.h"

using namespace QTest;

TestParser::TestParser(QObject *parent) : QObject(parent)
{
	meshTest1 = "../../Data/45L.msh";
	meshTest2 = "../../Data/18Triangle.msh";

	//vtkTest1 = "../../Data/Rect-4el.vtk";
}

//void TestParser::testVTK1()
//{
//	qDebug() << "TestVTK1 \n";
//	VTKParser *vtkParser = new VTKParser(vtkTest1, this);
//
//	QCOMPARE((int)vtkParser->dataSet->GetNumberOfPoints(), 5);
//}
//
//void TestParser::testVTK2()
//{
//
//}

void TestParser::testVerifyMeshNumbers()
{
	verifyMSHNumbers(meshTest1, 961, 1792);
	verifyMSHNumbers(meshTest2, 217, 384);
}

void TestParser::testVerifyNodeIds()
{
	MSHParser *parser1 = new MSHParser(this, meshTest1);
	qDebug() << parser1->getNumberOfNodes() << " " << parser1->getNumberOfElements() << "\n";
	QVERIFY(uniqueIds(parser1));

	MSHParser *parser2 = new MSHParser(this, meshTest2);
	qDebug() << parser2->getNumberOfNodes() << " " << parser2->getNumberOfElements() << "\n";
	QVERIFY(uniqueIds(parser2));
}

bool TestParser::uniqueIds(MSHParser *parser)
{
	std::vector<Element> elements = parser->getElements();
	std::vector<Node> nodes = parser->getNodes();
	
	int lastId = 0;		//Should begin at 1
	for each(Node node in nodes)
	{
		if(node.id == lastId)
		{
			return false;
		}
		lastId = node.id;
	}

	return true;
}

void TestParser::verifyMSHNumbers(std::string fileName, int nNod, int nElem)
{
	MSHParser *parser = new MSHParser(this, fileName);

	std::vector<Element> elements = parser->getElements();
	std::vector<Node> nodes = parser->getNodes();

	QVERIFY(nodes.size() == nNod);
	QVERIFY(elements.size() == nElem);

}

