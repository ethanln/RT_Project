#include "stdafx.h"
#include "Shape.h"

Shape::Shape(SHAPE_TYPE _shape_type)
{
	this->shape_type = _shape_type;
}

Shape::~Shape()
{

}

void Shape::add_material(string key, string value)
{
	try 
	{
		this->materials.insert(std::pair<string, string>(key, value));
	}
	catch (exception& e)
	{
		throw ShapeException("Could not insert material into shape.");
	}
}

string Shape::get_material(string key)
{
	try
	{
		return this->materials[key];
	}
	catch (exception& e) 
	{
		throw ShapeException("Could not fetch shape material.");
	}
	
}
