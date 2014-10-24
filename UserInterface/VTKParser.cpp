#include "VTKParser.h"

VTKParser::VTKParser(std::string inputFilename, QObject* parent) : QObject(parent)
{
	dataSetMapper = vtkSmartPointer<vtkDataSetMapper>::New();
	vtkSmartPointer<vtkDataSetReader> reader = vtkSmartPointer<vtkDataSetReader>::New();
	reader->SetFileName(inputFilename.c_str());
	reader->ReadAllScalarsOn();
	reader->ReadAllVectorsOn();
	reader->Update();
	
	dataSet = reader->GetOutput();
	pd = dataSet->GetPointData();

	dataSetMapper->SetInputData(reader->GetOutput());
}

vtkSmartPointer<vtkPointData> VTKParser::getPointData()
{
	return pd;
}
