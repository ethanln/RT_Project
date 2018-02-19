#pragma once



#ifndef INTERSECTION_RESULT_H
#define INTERSECTION_RESULT_H

#include "Shape.h"
#include "glm/vec3.hpp"

using namespace std;
using namespace glm;

class Shape;
class IntersectionResult 
{
	public:
		/*
		* Shape that was intersected.
		*/
		Shape* shape;

		/*
		* The intersection coordinate.
		*/
		vec3 intersection;

		/*
		* Intersection marker.
		*/
		bool does_intersect;

		/*
		* Constructor.
		*/
		IntersectionResult(Shape* _shape, vec3 _intersection, bool _does_intersect);

		/*
		* Deconstructor.
		*/
		~IntersectionResult();
};

#endif