#pragma once

#include <qobject.h>
#include <vtkGenericDataObjectReader.h>
#include <vtkSmartPointer.h>

#include <vtkDataSetReader.h>
#include <vtkDataSet.h>
#include <vtkPointData.h>
#include <vtkPolyDataReader.h>
#include <vtkUnstructuredGridReader.h>
#include <vtkDataReader.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkDataSetMapper.h>

#include "TestLib.h"

//!	A parser for interpreting VTK files using VTK's vtkDataSetReader, and provides a convenient way to extract the data.
class TEST_LIB VTKParser : public QObject
{
public:
	vtkSmartPointer<vtkDataSet> dataSet;
	vtkSmartPointer<vtkDataSetMapper> dataSetMapper;
	vtkSmartPointer<vtkPointData> pd;

	VTKParser(std::string inputFilename, QObject *parent);

	vtkSmartPointer<vtkPointData> getPointData();
};