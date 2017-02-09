#include "stdafx.h"
#include "Sphere.h"

Sphere::Sphere(float _radius, glm::vec3 _center) : Shape(SHAPE_TYPE::SPHERE)
{
	this->radius = _radius;
	this->center = _center;
}

Sphere::~Sphere()
{

}