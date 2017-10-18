#include "stdafx.h"
#include "ShapeUtil.h"

glm::vec3 ShapeUtil::GET_TRIANGLE_NORMAL(Triangle triangle, bool is_normalized)
{
	glm::vec3 e1 = triangle.p2 - triangle.p1;
	glm::vec3 e2 = triangle.p3 - triangle.p1;

	float xn = (e1.y * e2.z) - (e2.y * e1.z);
	float yn = (e1.z * e2.x) - (e2.z * e1.x);
	float zn = (e1.x * e2.y) - (e2.x * e1.y);

	glm::vec3 vec = is_normalized ? Vec3Util::NORMALIZE(glm::vec3(xn, yn, zn)) : glm::vec3(xn, yn, zn);

	return vec;
}

glm::vec3 ShapeUtil::GET_SPHERE_NORMAL(glm::vec3 intersection, Sphere sphere, bool is_normalized)
{
	glm::vec3 vec = is_normalized ? Vec3Util::NORMALIZE(intersection - sphere.center) : intersection - sphere.center;
	return vec;
}

IntersectionResult ShapeUtil::TEST_TRIANGLE_INTERSECTION(Ray ray, Triangle triangle)
{
	// TEST

	// Normalize the direction of the ray.
	glm::vec3 dir = Vec3Util::NORMALIZE(ray.direction);
	// Get the normal of the triangle.
	glm::vec3 n = ShapeUtil::GET_TRIANGLE_NORMAL(triangle, true);
	// Fetch the initial position of the ray.
	glm::vec3 o = ray.initial_position;
	
	// Calculate the intersection point.
	glm::vec3 p = (triangle.p1 + triangle.p2 + triangle.p3) / 3.0f;
	float t = (-1.0f) * Vec3Util::DOT((o - p), n) / Vec3Util::DOT(dir, n);
	glm::vec3 intersection = o + (dir * t);

	// The initial increment of the initial position (to offset the initial position);
	glm::vec3 e = ray.direction * 0.0001f;

	// Test for intersection.
	bool result = ShapeUtil::DOES_INTERSECT_TRIANGLE(ray.direction, ray.initial_position + e, intersection, triangle);

	// Return the result.
	return IntersectionResult(&triangle, intersection, result);
}

bool ShapeUtil::DOES_INTERSECT_TRIANGLE(glm::vec3 direction, glm::vec3 origin, glm::vec3 intersection, Triangle triangle)
{
	// IMPLEMENT
	return false;
}

bool ShapeUtil::IS_POINT_ON_TRIANGLE(glm::vec3 point, Triangle triangle)
{
	// IMPLEMENT
	return false;
}

bool ShapeUtil::IS_ON_PLANE(glm::vec3 point, Triangle triangle)
{
	// IMPLEMENT
	return false;
}

IntersectionResult ShapeUtil::TEST_SPHERE_INTERSECTION(Ray ray, Sphere sphere)
{
	throw "Not Yet Implemented";
	// IMPLEMENT
}