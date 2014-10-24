//#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
//#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)

#include <QtWidgets>
#include <QtTest/QtTest>

#include "TestParser.h"

int main(int argc, char *argv[])
{
	TestParser test1;
	QTest::qExec(&test1, argc, argv);
	
	return 0;
}