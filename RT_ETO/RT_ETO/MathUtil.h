#ifndef MATH_UTIL_H
#define MATH_UTIL_H

#include <glm/vec3.hpp>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "VecUtil.h"
#include "IShape.h"
#include "Triangle.h"
#include "Sphere.h"

#pragma once

using namespace std;

class MathUtil
{
	public:

		/**
		* PI value.
		*/
		static const float PI;

	public:

		/**
		* Global to radians.
		*/
		static float TO_RADIANS(float degree);

		/**
		* Global to degrees.
		*/
		static float TO_DEGREES(float radians);

};
#endif