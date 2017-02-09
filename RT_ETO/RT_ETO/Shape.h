#pragma once
#ifndef GEO_SHAPE_H
#define GEO_SHAPE_H

#include <glm/vec3.hpp>
#include "IShape.h"

using namespace std;

class Shape : public IShape
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