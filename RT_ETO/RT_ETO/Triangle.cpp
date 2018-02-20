#include "stdafx.h"
#include "Triangle.h"

Triangle::Triangle(vec3 _p1, vec3 _p2, vec3 _p3) : Shape(SHAPE_TYPE::TRIANGLE)
{
	this->p1 = _p1;
	this->p2 = _p2;
	this->p3 = _p3;
	this->get_normal(true);
}

Triangle::~Triangle()
{

}

vec3 Triangle::get_normal(bool normalize, vec3 point)
{
	vec3 e1 = this->p2 - this->p1;
	vec3 e2 = this->p3 - this->p1;

	float xn = (e1.y * e2.z) - (e2.y * e1.z);
	float yn = (e1.z * e2.x) - (e2.z * e1.x);
	float zn = (e1.x * e2.y) - (e2.x * e1.y);
	vec3 normal = CROSS_PRODUCT(e1, e2, normalize);

	return normal;
}

IntersectionResult Triangle::test_line_collision(Ray ray)
{
	// Normalize the direction of the ray.
	vec3 dir = NORMALIZE(ray.direction);
	// Get the normal of the triangle.
	vec3 n = this->get_normal(true);
	// Fetch the initial position of the ray.
	vec3 o = ray.initial_position;

	// Test to see if the ray is parallel with the plane of the triangle.
	bool isParallel = DOT(dir, n) == 0;
	if (DOT(dir, n) == 0)
	{
		return IntersectionResult(nullptr, vec3(0, 0, 0), false);
	}

	// Calculate the intersection point.
	vec3 p = (this->p1 + this->p2 + this->p3) / 3.0f;
	float t = (-1.0f) * DOT((o - p), n) / DOT(dir, n);
	vec3 intersection = o + (dir * t);

	// The initial increment of the initial position (to offset the initial position);
	vec3 e = ray.direction * 0.0001f;

	// Test for intersection.
	bool result = this->does_intersect_triangle(dir, ray.initial_position + e, intersection);
	if (result)
	{
		return IntersectionResult(new Triangle(this->p1, this->p2, this->p3), intersection, result);
	}

	// Return the result.
	return IntersectionResult(nullptr, vec3(0, 0, 0), false);
}

Shape* Triangle::clone()
{
	try
	{
		vec3 clone_p1 = vec3(this->p1.x, this->p1.y, this->p1.z);
		vec3 clone_p2 = vec3(this->p2.x, this->p2.y, this->p2.z);
		vec3 clone_p3 = vec3(this->p3.x, this->p3.y, this->p3.z);

		Shape* clone_triangle = new Triangle(clone_p1, clone_p2, clone_p3);

		return clone_triangle;
	}
	catch (exception& e)
	{
		throw new ShapeException("Could not clone triangle object.");
	}
}


string Triangle::hash()
{
	ostringstream ss;
	ss << this->seed << this->p1.x << this->p1.y << this->p1.z << this->p2.x << this->p2.y << this->p2.z << this->p3.x << this->p3.y << this->p3.z;
	// We should make sure that the id's are 256 bit.
	return ss.str();
}


bool Triangle::does_intersect_triangle(vec3 direction, vec3 origin, vec3 intersection)
{
	vec3 intersectTemp = vec3(intersection.x, intersection.y, intersection.z);
	vec3 edge1 = this->p2 - this->p1;
	vec3 edge2 = this->p3 - this->p1;

	vec3 pVec = CROSS_PRODUCT(direction, edge2, false);
	float det = DOT(edge1, pVec);

	if (det == 0)
	{
		return this->is_on_plane(origin) && this->is_point_in_triangle(origin);
	}

	det = 1.0f / det;

	vec3 tVec = origin - this->p1;
	float u = DOT(tVec, pVec) * det;
	if (u < 0.0f || u > 1.0f)
	{
		return false;
	}

	vec3 qVec = CROSS_PRODUCT(tVec, edge1, false);
	float v = DOT(direction, qVec) * det;
	if (v < 0.0f || u + v > 1.0f)
	{
		return false;
	}

	float t = DOT(edge2, qVec) * det;
	if (t < 0)
	{
		return false;
	}

	return true;
}

bool Triangle::is_point_in_triangle(vec3 point)
{
	vec3 v1 = this->p1 - point;
	vec3 v2 = this->p2 - point;
	vec3 v3 = this->p3 - point;

	float e1 = DOT(v1, v2);
	float e2 = DOT(v1, v3);
	float e3 = DOT(v2, v3);
	float e4 = DOT(v3, v3);

	if (e3 * e2 - e4 * e1 < 0)
	{
		return false;
	}

	float bb = DOT(v2, v2);
	if (e1 * e3 - e2 * bb < 0)
	{
		return false;
	}

	return true;
}

bool Triangle::is_on_plane(vec3 point)
{
	vec3 p1 = this->p1;
	vec3 p2 = this->p2;
	vec3 p3 = this->p3;

	vec3 n = CROSS_PRODUCT(p1 - p3, vec3(p2.x - p3.x, p2.y - p3.y, p2.z - p3.z), true);

	float d = (1.0f) * DOT(p2, n);
	float dist = DOT(n, point) + d;

	return dist == 0.0f;
}