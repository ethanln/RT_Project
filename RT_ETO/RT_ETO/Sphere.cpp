#include "stdafx.h"
#include "Sphere.h"

Sphere::Sphere(float _radius, vec3 _center) : Shape(SHAPE_TYPE::SPHERE)
{
	this->radius = _radius;
	this->center = _center;
}

Sphere::~Sphere()
{

}

vec3 Sphere::get_normal(bool normalize, vec3 point)
{
	vec3 vec = normalize ? NORMALIZE(point - this->center) : point - this->center;
	return vec;
}

IntersectionResult Sphere::test_line_collision(Ray ray)
{
	// IMPLEMENT
	return IntersectionResult(nullptr, vec3(0, 0, 0), false);
}

Shape* Sphere::clone() 
{
	try 
	{
		vec3 clone_center = vec3(this->center.x, this->center.y, this->center.z);
		Shape* clone_sphere = new Sphere(this->radius, clone_center);

		return clone_sphere;
	}
	catch (exception& e)
	{
		throw new ShapeException("Could not clone sphere object.");
	}
}

bool Sphere::does_intersect_sphere(vec3 direction, vec3 origin)
{
	// IMPLEMENT
	return false;
}