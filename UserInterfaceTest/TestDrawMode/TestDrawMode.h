#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)

#include <QtTest/QtTest>
#include "qobject.h"	//	Math Macro redef warning: if more than qObject in header..
#include "CModel.h"
#include "mainwindow.h"	
#include "DrawController.h"
#include "../IncludeMainProject.h"

class TestDrawMode : public QObject
{
	Q_OBJECT
public: 
	TestDrawMode(int &, char**, QObject *parent = 0);
	~TestDrawMode(){}

	int argc;
	char** argv;
	MainWindow *w;

private slots:
	void initTestCase();
	void testCreateDrawView();

signals:
	void newCircle();
	void enterPressed();
	void escapePressed();
};