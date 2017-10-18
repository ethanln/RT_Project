#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include "ShapeException.h"
#include <glm/vec3.hpp>
#include <exception>
#include <string>
#include <map>

using namespace std;

class Shape
{
	public:
		enum SHAPE_TYPE
		{
			TRIANGLE = 1,
			SPHERE = 2
		};

		SHAPE_TYPE shape_type;

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
		* Clone shape instance;
		*/
		virtual Shape* clone() throw(ShapeException) = 0;

};
#endif