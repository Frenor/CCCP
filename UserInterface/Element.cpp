#include "Element.h"

Element::Element() 
{

}

Element::~Element()
{
	deleteNodes();
}

void Element::deleteNodes()
{
	nodes.clear();
}
