#include "stdafx.h"
#include "VecUtil.h"


glm::vec3 VecUtil::NORMALIZE(glm::vec3 v)
{
	float dx = powf(v.x, 2.0f);
	float dy = powf(v.y, 2.0f);
	float dz = powf(v.z, 2.0f);

	float c = sqrtf(dx + dy + dz);

	float nx = v.x / c;
	float ny = v.y / c;
	float nz = v.z / c;

	return glm::vec3(nx, ny, nz);
}

float VecUtil::DOT(glm::vec3 v1, glm::vec3 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float VecUtil::MAG(glm::vec3 v)
{
	return sqrt(pow(v.x, 2.0f) + pow(v.y, 2.0f) + pow(v.z, 2.0f));
}