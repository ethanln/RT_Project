#include "stdafx.h"
#include "Triangle.h"

Triangle::Triangle(glm::vec3 _p1, glm::vec3 _p2, glm::vec3 _p3) : Shape(SHAPE_TYPE::TRIANGLE)
{
	this->p1 = _p1;
	this->p2 = _p2;
	this->p3 = _p3;
}

Triangle::~Triangle()
{

}