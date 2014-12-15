#pragma once
#ifndef MATERIAL_H
#define MATERIAL_H

#include <vtkSmartPointer.h>
#include <vtkFloatArray.h>
#include <vtkLookupTable.h>

#include <qmetatype.h>
#include <qstring.h>

#include <vector>

class Material
{
public:
	

	Material(std::string);
	~Material();

	bool isSelectable;
	bool isBase;
	QString name;
	int baseColorRGB[3];

	friend bool operator== (Material m1, Material m2);

	std::vector<Material*> components;
	/*!
		Collection of cells used to color a crossection made by this material
	*/
	vtkSmartPointer<vtkFloatArray> cellData;
	/*!
		Collection of colors used to color a crossection using this material
	*/
	vtkSmartPointer<vtkLookupTable> colorTable;

	/*!
		Generate new values and populate cellData and ColorTable
	*/
	void updateTables();
};
#endif //MATERIAL_H