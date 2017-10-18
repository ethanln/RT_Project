#pragma once

#ifndef SPHERE_H
#define SPHERE_H

#include <glm/vec3.hpp>
#include "Shape.h"

using namespace std;

class Sphere : public Shape
{
	public:

		/**
		* Sphere radius.
		*/
		float radius;

		/**
		* Center.
		*/
		glm::vec3 center;

	public:

		/**
		* Triangle constructor.
		*/
		Sphere(float _radius, glm::vec3 _center);

		/**
		* Triangle deconstructor.
		*/
		~Sphere();

		/**
		* Clone sphere instance.
		*/
		virtual Shape* clone() throw(ShapeException);
};

#endif