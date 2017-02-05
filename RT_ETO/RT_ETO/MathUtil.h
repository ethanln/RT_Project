#ifndef MATH_UTIL_H
#define MATH_UTIL_H

#include <glm/vec3.hpp>
#include <math.h>

#pragma once

using namespace std;

class MathUtil
{
	public:

		/**
		* PI value.
		*/
		static float PI;

	public:
	
		/**
		* Global normalize function.
		*/
		static glm::vec3 NORMALIZE(glm::vec3 v);


		/**
		* Global dot product function.
		*/
		static float DOT(glm::vec3 v1, glm::vec3 v2);

		/**
		* Global magnitude function.
		*/
		static float MAG(glm::vec3 v);

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