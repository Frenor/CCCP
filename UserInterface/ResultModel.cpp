#include "ResultModel.h"

ResultModel::ResultModel(QObject *parent) : QObject(parent)
{
	mesh = NULL;
	activeResultName = "No data"; 

	pd = vtkSmartPointer<vtkPointData>::New();
	dMapper = vtkSmartPointer<vtkDataSetMapper>::New();
	lut =  vtkSmartPointer<vtkLookupTable>::New();
	lut->Build();

	scalarBarVisible = true;
}

void ResultModel::computeResultNameAndRange()
{
	resultNames.clear();
	ranges.clear();
	
	if(pd)
	{
		for (int i = 0; i < pd->GetNumberOfArrays(); i++)
        {
			std::string resultName = (pd->GetArrayName(i) ? pd->GetArrayName(i) : "NULL");
			resultNames.push_back(resultName);
			
			vtkDataArray* arr = pd->GetArray(i);
			double* range = arr->GetRange();
			ranges[resultName] = range;

			std::cout << "ResultName: " << resultName << std::endl;
		}
	}
	std::cout << "ResultNames created" << std::endl;
}

void ResultModel::setDataSource(VTKParser *parser)
{
	dataSet = parser->dataSet;
	dMapper = parser->dataSetMapper;
	dMapper->SetLookupTable(lut);
	dMapper->SetScalarRange(dataSet->GetScalarRange());

	pd = parser->getPointData();

	computeResultNameAndRange();
	setActiveResult(QString::fromStdString(resultNames.at(0)));
	
	emit modelDataSourceChanged();
}
void ResultModel::setDataSource(MSHParser *parser)
{
	if(mesh)
	{
		delete mesh;
	}
	mesh = new Mesh(QString(parser->getFilename().c_str()), parser->getNodes(), parser->getElements(), this);
	
	emit modelDataSourceChanged();
}

void ResultModel::setActiveResult(QString itemText)
{
	activeResultName = itemText.toStdString();
	pd->SetActiveScalars(activeResultName.c_str());
	
	double* range = ranges[activeResultName];
	if(range)
	{
		dMapper->SetScalarRange(range);
	}
	emit modelChanged();
}

bool ResultModel::hasResultData()
{
	//std::cout << "Numbers: " << polyData->GetNumberOfPoints() << ", "  << polyData->GetNumberOfLines() << ", " << polyData->GetNumberOfPolys() << ", " << std::endl;
	if(dataSet && (dataSet->GetNumberOfPoints() > 0 || dataSet->GetNumberOfCells() > 0))
	{
		return true;
	}
	return false;
}
bool ResultModel::hasMeshData()
{
	if(mesh && mesh->getNumberOfElements() > 0 && mesh->getNumberOfNodes())
	{
		return true;
	}
	return false;
}

vtkSmartPointer<vtkDataSetMapper> ResultModel::getMapper()
{
	return dMapper;
}
Mesh* ResultModel::getMesh()
{
	return mesh;
}
std::string ResultModel::getActiveResultName()
{
	return activeResultName;
}

void ResultModel::setMeshVisible(bool visible)
{
	this->meshVisible = visible;
	
	emit modelChanged();
}
void ResultModel::setResultVisible(bool visible)
{
	std::cout << "setResultVisibility: " << visible << std::endl;
	this->resultVisible = visible;
	
	emit modelChanged();
}

void ResultModel::showScalarBar()
{
	scalarBarVisible = true;
}
void ResultModel::hideScalarBar()
{
	scalarBarVisible = false;
}