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

Shape* Sphere::clone() 
{
	try 
	{
		glm::vec3 clone_center = glm::vec3(this->center.x, this->center.y, this->center.z);
		Shape* clone_sphere = new Sphere(this->radius, clone_center);

		return clone_sphere;
	}
	catch (exception& e)
	{
		throw new ShapeException("Could not clone sphere object.");
	}
}