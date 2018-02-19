//#include "stdafx.h"
//#include "ShapeUtil.h"
//
//glm::vec3 ShapeUtil::GET_TRIANGLE_NORMAL(Triangle triangle, bool is_normalized)
//{
//	// DELETE
//	glm::vec3 e1 = triangle.p2 - triangle.p1;
//	glm::vec3 e2 = triangle.p3 - triangle.p1;
//
//	float xn = (e1.y * e2.z) - (e2.y * e1.z);
//	float yn = (e1.z * e2.x) - (e2.z * e1.x);
//	float zn = (e1.x * e2.y) - (e2.x * e1.y);
//	glm::vec3 normal = Vec3Util::CROSS_PRODUCT(e1, e2, is_normalized);
//
//	return normal;
//}
//
//glm::vec3 ShapeUtil::GET_SPHERE_NORMAL(glm::vec3 intersection, Sphere sphere, bool is_normalized)
//{
//	// DELETE
//	glm::vec3 vec = is_normalized ? Vec3Util::NORMALIZE(intersection - sphere.center) : intersection - sphere.center;
//	return vec;
//}
//
//IntersectionResult ShapeUtil::TEST_TRIANGLE_INTERSECTION(Ray ray, Triangle triangle)
//{
//	// DELETE
//	// Normalize the direction of the ray.
//	glm::vec3 dir = Vec3Util::NORMALIZE(ray.direction);
//	// Get the normal of the triangle.
//	glm::vec3 n = ShapeUtil::GET_TRIANGLE_NORMAL(triangle, true);
//	// Fetch the initial position of the ray.
//	glm::vec3 o = ray.initial_position;
//	
//	// Test to see if the ray is parallel with the plane of the triangle.
//	bool isParallel = Vec3Util::DOT(dir, n) == 0;
//	if (Vec3Util::DOT(dir, n) == 0)
//	{
//		return IntersectionResult(nullptr, glm::vec3(0, 0, 0), false);
//	}
//
//	// Calculate the intersection point.
//	glm::vec3 p = (triangle.p1 + triangle.p2 + triangle.p3) / 3.0f;
//	float t = (-1.0f) * Vec3Util::DOT((o - p), n) / Vec3Util::DOT(dir, n);
//	glm::vec3 intersection = o + (dir * t);
//
//	// The initial increment of the initial position (to offset the initial position);
//	glm::vec3 e = ray.direction * 0.0001f;
//
//	// Test for intersection.
//	bool result = ShapeUtil::DOES_INTERSECT_TRIANGLE(dir, ray.initial_position + e, intersection, triangle);
//	if (result) 
//	{
//		return IntersectionResult(new Triangle(triangle), intersection, result);
//	}
//
//	// Return the result.
//	return IntersectionResult(nullptr, glm::vec3(0, 0, 0), false);
//}
//
//IntersectionResult ShapeUtil::TEST_SPHERE_INTERSECTION(Ray ray, Sphere sphere)
//{
//	throw "Not Yet Implemented";
//	// IMPLEMENT
//}
//
//bool ShapeUtil::DOES_INTERSECT_TRIANGLE(glm::vec3 direction, glm::vec3 origin, glm::vec3 intersection, Triangle triangle)
//{
//	// DELETE
//	glm::vec3 intersectTemp = glm::vec3(intersection.x, intersection.y, intersection.z);
//	glm::vec3 edge1 = triangle.p2 - triangle.p1;
//	glm::vec3 edge2 = triangle.p3 - triangle.p1;
//
//	glm::vec3 pVec = Vec3Util::CROSS_PRODUCT(direction, edge2, false);
//	float det = Vec3Util::DOT(edge1, pVec);
//
//	if (det == 0)
//	{
//		return ShapeUtil::IS_ON_PLANE(origin, triangle) && ShapeUtil::IS_POINT_IN_TRIANGLE(origin, triangle);
//	}
//
//	det = 1.0f / det;
//
//	glm::vec3 tVec = origin - triangle.p1;
//	float u = Vec3Util::DOT(tVec, pVec) * det;
//	if (u < 0.0f || u > 1.0f)
//	{
//		return false;
//	}
//
//	glm::vec3 qVec = Vec3Util::CROSS_PRODUCT(tVec, edge1, false);
//	float v = Vec3Util::DOT(direction, qVec) * det;
//	if (v < 0.0f || u + v > 1.0f)
//	{
//		return false;
//	}
//
//	float t = Vec3Util::DOT(edge2, qVec) * det;
//	if (t < 0)
//	{
//		return false;
//	}
//
//	return true;
//}
//
//bool ShapeUtil::IS_POINT_IN_TRIANGLE(glm::vec3 point, Triangle triangle)
//{
//	// DELETE
//	glm::vec3 v1 = triangle.p1 - point;
//	glm::vec3 v2 = triangle.p2 - point;
//	glm::vec3 v3 = triangle.p3 - point;
//
//	float e1 = Vec3Util::DOT(v1, v2);
//	float e2 = Vec3Util::DOT(v1, v3);
//	float e3 = Vec3Util::DOT(v2, v3);
//	float e4 = Vec3Util::DOT(v3, v3);
//
//	if (e3 * e2 - e4 * e1 < 0)
//	{
//		return false;
//	}
//
//	float bb = Vec3Util::DOT(v2, v2);
//	if (e1 * e3 - e2 * bb < 0)
//	{
//		return false;
//	}
//
//	return true;
//}
//
//bool ShapeUtil::IS_ON_PLANE(glm::vec3 point, Triangle triangle)
//{
//	// DELETE
//	glm::vec3 p1 = triangle.p1;
//	glm::vec3 p2 = triangle.p2;
//	glm::vec3 p3 = triangle.p3;
//
//	glm::vec3 n = Vec3Util::CROSS_PRODUCT(p1 - p3, glm::vec3(p2.x - p3.x, p2.y - p3.y, p2.z - p3.z), true);
//
//	float d = (1.0f) * Vec3Util::DOT(p2, n);
//	float dist = Vec3Util::DOT(n, point) + d;
//
//	return dist == 0.0f;
//}
//
//bool ShapeUtil::DOES_INTERSET_SPHERE(glm::vec3 direction, glm::vec3 origin, Sphere sphere)
//{
//	// IMPLEMENT
//	return false;
//}
//
//
