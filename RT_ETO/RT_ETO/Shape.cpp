#include "stdafx.h"
#include "Shape.h"

Shape::Shape(SHAPE_TYPE _shape_type)
{
	this->shape_type = _shape_type;
	this->seed = reinterpret_cast<int>(this);
}

Shape::~Shape()
{

}
