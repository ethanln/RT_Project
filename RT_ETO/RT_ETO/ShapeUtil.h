#pragma once
#ifndef SHAPE_UTIL_H
#define SHAPE_UTIL_H

#include "Triangle.h"
#include "Sphere.h"
#include "Vec3Util.h"
#include "IntersectionResult.h"
#include "Ray.h"
#include <glm/vec3.hpp>

using namespace std;

class ShapeUtil
{
	public:

		/**
		* Global get normal for triangles.
		*/
		static glm::vec3 GET_TRIANGLE_NORMAL(Triangle t, bool is_normalized);

		/**
		* Global get normal for sphere.
		*/
		static glm::vec3 GET_SPHERE_NORMAL(glm::vec3 intersection, Sphere s, bool is_normalized);

		/**
		* Global get intersection for triangle.
		*/
		static IntersectionResult TEST_TRIANGLE_INTERSECTION(Ray ray, Triangle t);

		/**
		* Global get intersection for sphere.
		*/
		static IntersectionResult TEST_SPHERE_INTERSECTION(Ray ray, Sphere s);
};

#endif