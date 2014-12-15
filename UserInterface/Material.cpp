#include "Material.h"


Material::Material(std::string name)
{
	this->name = QString::fromStdString(name);
	this->isBase = true;
	this->isSelectable = true;
	this->baseColorRGB[0] = 153;
	this->baseColorRGB[1] = 194;
	this->baseColorRGB[2] = 23;
}

Material::~Material()
{
}


// \return vtkBrush used to color a crossection using this material
void Material::updateTables()
{
	if (isBase)
	{
		colorTable->SetNumberOfTableValues(1);
		colorTable->Build();

		colorTable->SetTableValue(0, baseColorRGB[0] / 255.0, baseColorRGB[1] / 255.0, baseColorRGB[2] / 255.0, 1);
	}
}

bool operator== (Material m1, Material m2)
{
	return (m1.name == m2.name && m1.baseColorRGB == m2.baseColorRGB);
}
