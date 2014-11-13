#pragma once
#ifndef RESULTMODEL_H
#define RESULTMODEL_H

#include <qobject.h>
#include <vtkPointData.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkLookupTable.h>
#include <map>

#include "VTKParser.h"
#include "MSHParser.h"
#include "Mesh.h"

//!	Model which holds the data and functions to manipulate the VTK and Mesh datasets.
class ResultModel : public QObject
{
	Q_OBJECT
public:
	ResultModel(QObject *parent);
	
	vtkSmartPointer<vtkLookupTable> lut;	//!< Lookup table to create a color map for a range of values
	
	bool meshVisible;		//!< Mesh actor visibility.
	bool resultVisible;		//!< Result actor visibility.
	bool scalarBarVisible;	//!< Scalar actor visibility.

	std::vector<std::string> resultNames;	//!< Name of results in file
	/*!
		Loops through the pointData arrays in the loaded dataset, and creates a list of data names.
		It also computes a map containing scale ranges based with the resultName as a key
	*/
	void computeResultNameAndRange();

	/*!
		\return vtkSmartPointer<vtkDataSetMapper> Contains result data
	*/
	vtkSmartPointer<vtkDataSetMapper> getMapper();

	/*!
		Sets the active scalar pointData given the pointData's name.
	*/
	void setActiveResult(QString);

	/*!
		Set the Mesh datasource and loads the data from the meshparser into the model.
		When done, the model fires "modelDataSourceChanged" and the view is invalidated.
	*/
	void setDataSource(MSHParser *);
	
	/*!
		Set the Result datasource and loads the data from the vtkparser into the model.
		When done, the model fires "modelDataSourceChanged" and the view is invalidated.
	*/
	void setDataSource(VTKParser *);

	/*!
		Checks if polyData has points > 0 & lines > 0 & polygons > 0.
		\return True if model has vtkData. False otherwise.
	*/
	bool hasResultData();
	/*!
		Checks if the mesh entity is initialized
		\return True if model has mesh data. False otherwise.
	*/
	bool hasMeshData();

	/*!
		Gets the active mesh entity in the model.
		\return Mesh*
	*/
	Mesh* getMesh();

	/*!
		Sets the mesh visibility in the model and fires modelChanged
	*/
	void setMeshVisible(bool);
	
	/*!
		Sets the result visibility in the model and fires modelChanged
	*/
	void setResultVisible(bool);

	/*!
		\return std::string Name of the active result
	*/
	std::string getActiveResultName();
	
public slots:
	void showScalarBar();
	void hideScalarBar();

signals:
	/*!
		Fires if activeResult changes.
	*/
	void modelChanged();

	/*!
		Fires if one of the model's data sources changes.
	*/
	void modelDataSourceChanged();

private:
	Mesh *mesh;			//!< Mesh entity currently displayed in results
	int activeResult;	//!< Current point data mapped on result object

	std::string activeResultName;
	vtkSmartPointer<vtkDataSet> dataSet;
	vtkSmartPointer<vtkDataSetMapper> dMapper;
	vtkSmartPointer<vtkPointData> pd;

	std::map<std::string, double*> ranges;
};
#endif //RESULTMODEL_H