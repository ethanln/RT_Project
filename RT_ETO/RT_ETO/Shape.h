#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include <glm/vec3.hpp>

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

};
#endif