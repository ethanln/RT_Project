#pragma once



#ifndef SHAPE_H
#define SHAPE_H

#include "ShapeException.h"
#include <glm/vec3.hpp>
#include <exception>
#include <string>
#include <map>
#include <sstream>
#include "IntersectionResult.h"
#include "Ray.h"
#include "Vec3Util.h"

using namespace std;
using namespace glm;
using namespace Vec3Util;

class IntersectionResult;
class Shape
{
	public:
		enum SHAPE_TYPE
		{
			TRIANGLE = 1,
			SPHERE = 2
		};

		SHAPE_TYPE shape_type;

		int seed;

	public:

		/**
		* Shape constructor.
		*/
		Shape(SHAPE_TYPE _shape_type);

		/**
		* Shape deconstructor.
		*/
		virtual ~Shape();

		/**
		* Calculates and returns the normal of the shape.
		*/
		virtual vec3 get_normal(bool normalize, vec3 point = vec3(0, 0, 0)) = 0;

		/**
		* Tests to see if a line collides with the shape.
		*/
		virtual IntersectionResult test_line_collision(Ray ray) = 0;

		/**
		* Clone shape instance;
		*/
		virtual Shape* clone() throw(ShapeException) = 0;

		/**
		* Generates hash value of object.
		*/
		virtual string hash() = 0;

};
#endif