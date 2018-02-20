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
	vec3 dir = ray.direction;
	vec3 initial_pos = ray.initial_position;
	vec3 n = NORMALIZE(dir);

	// translate intersection a little higher to avoid collision with the same object.
	initial_pos += (n * 0.001f);

	float x0 = initial_pos.x;
	float y0 = initial_pos.y;
	float z0 = initial_pos.z;

	float cx = this->center.x;
	float cy = this->center.y;
	float cz = this->center.z;

	float dx = n.x;
	float dy = n.y;
	float dz = n.z;

	float a = (dx*dx) + (dy*dy) + (dz*dz);
	float b = 2.0f *((dx * x0) - (dx * cx) + (dy * y0) - (dy*cy) + (dz * z0) - (dz * cz));

	float c = (float)pow(x0, 2.0f) - (2.0f * x0 * cx) + (float)pow(cx, 2.0f)
		+ (float)pow(y0, 2.0f) - (2.0f * y0 * cy) + (float)pow(cy, 2.0f)
		+ (float)pow(z0, 2.0f) - (2.0f * z0 * cz) + (float)pow(cz, 2.0f)
		- (float)pow(this->radius, 2.0f);

	float discriminant = (float)pow(b, 2.0f) - (4.0f * a * c);
	if (discriminant < 0) {
		return IntersectionResult(nullptr, vec3(0, 0, 0), false);
	}

	float t0 = ((-b) - (float)sqrt((float)pow(b, 2.0f) - (4.0f * a * c))) / (2.0f * a);
	if (t0 <= 0.0f) {
		float t1 = ((-b) + (float)sqrt((float)pow(b, 2.0f) - (4.0f * a * c))) / (2.0f * a);
		if (t1 <= 0.0f) {
			return IntersectionResult(nullptr, vec3(0, 0, 0), false);
		}

		return IntersectionResult(new Sphere(this->radius, this->center), vec3(x0 + (t1 * dx), y0 + (t1 * dy), z0 + (t1 * dz)), true);
	}
	return IntersectionResult(new Sphere(this->radius, this->center), vec3(x0 + (t0 * dx), y0 + (t0 * dy), z0 + (t0 * dz)), true);
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

string Sphere::hash()
{
	ostringstream ss;
	ss << this->seed << this->center.x << this->center.y << this->center.z << this->radius;
	// We should make sure that the id's are 256 bit.
	return ss.str();
}
