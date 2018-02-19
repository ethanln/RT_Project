#include "stdafx.h"
#include "Vec3Util.h"

using namespace Vec3Util;

vec3 Vec3Util::NORMALIZE(vec3 v)
{
	float dx = powf(v.x, 2.0f);
	float dy = powf(v.y, 2.0f);
	float dz = powf(v.z, 2.0f);

	float c = sqrtf(dx + dy + dz);

	float nx = v.x / c;
	float ny = v.y / c;
	float nz = v.z / c;

	return vec3(nx, ny, nz);
}

float Vec3Util::DOT(vec3 v1, vec3 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float Vec3Util::MAGNITUDE(vec3 v)
{
	return sqrt(pow(v.x, 2.0f) + pow(v.y, 2.0f) + pow(v.z, 2.0f));
}

vec3 Vec3Util::CROSS_PRODUCT(vec3 v1, vec3 v2, bool is_normalized)
{
	float xn = (v1.y * v2.z) - (v2.y * v1.z);
	float yn = (v1.z * v2.x) - (v2.z * v1.x);
	float zn = (v1.x * v2.y) - (v2.x * v1.y);

	return is_normalized ? NORMALIZE(vec3(xn, yn, zn)) : vec3(xn, yn, zn);
}