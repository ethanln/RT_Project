#ifndef MATH_UTIL_H
#define MATH_UTIL_H

#include <glm/vec3.hpp>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "IShape.h"
#include "Triangle.h"
#include "Sphere.h"

#pragma once

using namespace std;

class MathUtil
{
	private:
		/**
		* Random seed variable state
		*/
		static bool IS_SEED_GENERATED;

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
		* Global get normal for triangles.
		*/
		static glm::vec3 GET_TRIANGLE_NORMAL(Triangle t, bool is_normalized);

		/**
		* Global get normal for sphere.
		*/
		static glm::vec3 GET_SPHERE_NORMAL(glm::vec3 intersection, Sphere s, bool is_normalized);

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

		/**
		* Global get vector ray.
		*/
		static glm::vec3 CAST_RAY(glm::vec3 p1, glm::vec3 p2, bool is_normalized);

		/**
		* Global get vector ray with jittering.
		*/
		static glm::vec3 CAST_RAY_JITTER(glm::vec3 p1, glm::vec3 p2, float radius_x, float radius_y, bool is_normalized);

		/**
		* Global get vector reflection ray.
		*/
		static glm::vec3 CAST_RAY_REFLECTION();

		/**
		* Global get vector reflection ray with gloss.
		*/
		static glm::vec3 CAST_RAY_REFLECTION_GLOSS();

		/**
		* Global get vector refraction ray.
		*/
		static glm::vec3 CAST_RAY_REFRACTION_GLOSS();

		/**
		* Set random seed generator.
		*/
		static void INITIALIZE_RANDOM_SEED();
};
#endif