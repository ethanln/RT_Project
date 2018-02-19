#include "stdafx.h"
#include "IntersectionResult.h"

IntersectionResult::IntersectionResult(Shape* _shape, vec3 _intersection, bool _does_intersect)
{
	this->shape = _shape;
	this->intersection = _intersection;
	this->does_intersect = _does_intersect;
}

IntersectionResult::~IntersectionResult()
{
	if (this->shape != nullptr)
	{
		delete shape;
		this->shape = nullptr;
	}
}