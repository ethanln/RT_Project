#include "stdafx.h"
#include "MathUtil.h"

using namespace std;

float MathUtil::PI = 3.14159265;

glm::vec3 MathUtil::GET_TRIANGLE_NORMAL(Triangle t, bool is_normalized)
{
	// TEST
	glm::vec3 e1 = t.p2 - t.p1;
	glm::vec3 e2 = t.p3 - t.p1;

	float xn = (e1.y * e2.z) - (e2.y * e1.z);
	float yn = (e1.z * e2.x) - (e2.z * e1.x);
	float zn = (e1.x * e2.y) - (e2.x * e1.y);

	glm::vec3 vec = is_normalized ? VecUtil::NORMALIZE(glm::vec3(xn, yn, zn)) : glm::vec3(xn, yn, zn);

	return vec;
}

glm::vec3 MathUtil::GET_SPHERE_NORMAL(glm::vec3 intersection, Sphere s, bool is_normalized)
{
	// TEST
	glm::vec3 vec = is_normalized ? VecUtil::NORMALIZE(intersection - s.center) : intersection - s.center;
	return vec;
}

float MathUtil::TO_RADIANS(float degree)
{
	return (degree * PI) / 180.0f;
}

float MathUtil::TO_DEGREES(float radians)
{
	return (radians * 180.0f) / PI;
}