#pragma once
#ifndef VEC3_UTIL_H
#define VEC3_UTIL_H

#include <glm/vec3.hpp>
#include <math.h>

using namespace std;
using namespace glm;

namespace Vec3Util
{
	/**
	* Global normalize function.
	*/
	vec3 NORMALIZE(vec3 v);

	/**
	* Global dot product function.
	*/
	float DOT(vec3 v1, vec3 v2);

	/**
	* Global magnitude function.
	*/
	float MAGNITUDE(vec3 v);

	/**
	* Global cross product function.
	*/ 
	vec3 CROSS_PRODUCT(vec3 v1, vec3 v2, bool is_normalized);
};

#endif