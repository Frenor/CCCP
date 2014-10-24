//#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
//#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)

#include <QtWidgets>
#include <QtTest/QtTest>

#include "TestDrawMode.h"

int main(int argc, char *argv[])
{
	TestDrawMode test1(argc, argv);
	QTest::qExec(&test1, argc, argv);
	
	return 0;
}