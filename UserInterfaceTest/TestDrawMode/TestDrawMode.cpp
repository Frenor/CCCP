#include "TestDrawMode.h"
#include <iostream>

using namespace QTest;

TestDrawMode::TestDrawMode(int &argc, char *argv[], QObject *parent) : QObject(parent)
{
	this->argc =argc;
	this->argv = argv;
}
void TestDrawMode::initTestCase()
{
	QApplication a(this->argc, this->argv);
	
	w = new MainWindow;
	
	connect(this, SIGNAL(newCircle()), w, SLOT(addCircle()));
	connect(this, SIGNAL(escapePressed()), w->gController, SLOT(escapePressed()));
}

void TestDrawMode::testCreateDrawView()
{
	int nEntities;
	nEntities = w->cModel->drawModel->entities.size();
	qDebug() << "\n" <<  "nEntities: " << nEntities;
	QCOMPARE(nEntities, 1);

	emit newCircle();
	nEntities = w->cModel->drawModel->entities.size();
	qDebug() << "\n" << "nEntities: " << nEntities;
	QCOMPARE(nEntities, 2);
	
	emit escapePressed();

	nEntities = w->cModel->drawModel->entities.size();
	qDebug() << "\n" << "nEntities: " << nEntities;
	QCOMPARE(nEntities, 1);
}
