#pragma once
#ifndef VEC3_UTIL_H
#define VEC3_UTIL_H

#include <glm/vec3.hpp>
#include <math.h>

using namespace std;

class Vec3Util
{
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
};

#endif