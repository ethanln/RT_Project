#include "stdafx.h"
#include "ShapeUtil.h"

glm::vec3 ShapeUtil::GET_TRIANGLE_NORMAL(Triangle t, bool is_normalized)
{
	glm::vec3 e1 = t.p2 - t.p1;
	glm::vec3 e2 = t.p3 - t.p1;

	float xn = (e1.y * e2.z) - (e2.y * e1.z);
	float yn = (e1.z * e2.x) - (e2.z * e1.x);
	float zn = (e1.x * e2.y) - (e2.x * e1.y);

	glm::vec3 vec = is_normalized ? Vec3Util::NORMALIZE(glm::vec3(xn, yn, zn)) : glm::vec3(xn, yn, zn);

	return vec;
}

glm::vec3 ShapeUtil::GET_SPHERE_NORMAL(glm::vec3 intersection, Sphere s, bool is_normalized)
{
	// TEST
	glm::vec3 vec = is_normalized ? Vec3Util::NORMALIZE(intersection - s.center) : intersection - s.center;
	return vec;
}