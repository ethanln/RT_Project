#include "stdafx.h"
#include "IntersectionResult.h"

IntersectionResult::IntersectionResult(Shape* _shape, glm::vec3 _intersection, bool _does_intersect)
{
	this->shape = _shape;
	this->intersection = _intersection;
	this->does_intersect = _does_intersect;
}

IntersectionResult::~IntersectionResult()
{
	delete this->shape;
}