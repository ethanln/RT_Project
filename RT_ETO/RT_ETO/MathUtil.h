#pragma once
#ifndef MATH_UTIL_H
#define MATH_UTIL_H

#include <glm/vec3.hpp>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "Vec3Util.h"
#include "Triangle.h"
#include "Sphere.h"

#pragma once

using namespace std;

namespace MathUtil
{
	/**
	* PI value.
	*/
	const float PI = 3.14159265;

	/**
	* Global to radians.
	*/
	float TO_RADIANS(float degree);

	/**
	* Global to degrees.
	*/
	float TO_DEGREES(float radians);

};
#endif