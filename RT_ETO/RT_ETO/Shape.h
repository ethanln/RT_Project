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

		map<string, string> materials;

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
		* Add material to shape.
		*/
		virtual void add_material(string key, string value) throw(ShapeException);

		/**
		* Get material from shape.
		*/
		virtual string get_material(string key) throw(ShapeException);

};
#endif