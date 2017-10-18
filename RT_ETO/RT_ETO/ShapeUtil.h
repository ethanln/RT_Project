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
		static glm::vec3 GET_TRIANGLE_NORMAL(Triangle triangle, bool is_normalized);

		/**
		* Global get normal for sphere.
		*/
		static glm::vec3 GET_SPHERE_NORMAL(glm::vec3 intersection, Sphere sphere, bool is_normalized);

		/**
		* Global get intersection for triangle.
		*/
		static IntersectionResult TEST_TRIANGLE_INTERSECTION(Ray ray, Triangle triangle);

		/**
		* Global get intersection for sphere.
		*/
		static IntersectionResult TEST_SPHERE_INTERSECTION(Ray ray, Sphere sphere);

	private:
		/**
		* Private global checks to see if a line interesects a triangle.
		*/
		static bool DOES_INTERSECT_TRIANGLE(glm::vec3 direction, glm::vec3 origin, glm::vec3 intersection, Triangle triangle);

		/**
		* Private global checks to see if a given point is on the triangle.
		*/
		static bool IS_POINT_ON_TRIANGLE(glm::vec3 point, Triangle triangle);

		/**
		* Checks to see if a point is on the plane.
		*/
		static bool IS_ON_PLANE(glm::vec3 point, Triangle triangle);
};

#endif