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

	bool isSelectable;		//!< Should this be added to the list of selectable materials
	bool isBase;			//!< This material is not compunded by any oher materials, same as component.size = 0
	QString name;			//!< Identifier used in lists
	int baseColorRGB[3];	//!< Base color used for quick identification in lists, and calculation of composit colors. Format: [255,255,255]

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