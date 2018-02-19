#pragma once

#ifndef SPHERE_H
#define SPHERE_H

#include <glm/vec3.hpp>
#include "Shape.h"

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
		vec3 center;

	public:

		/**
		* Triangle constructor.
		*/
		Sphere(float _radius, vec3 _center);

		/**
		* Triangle deconstructor.
		*/
		~Sphere();

		/**
		* Calculates and returns the normal of the sphere.
		*/
		virtual vec3 get_normal(bool normalize, vec3 point = vec3(0, 0, 0));

		/**
		* Tests to see if a line collides with the sphere.
		*/
		virtual IntersectionResult test_line_collision(Ray ray);

		/**
		* Clone sphere instance.
		*/
		virtual Shape* clone() throw(ShapeException);

	private:

		/**
		* Checks to see if a ray intersects the sphere.
		*/
		bool does_intersect_sphere(vec3 direction, vec3 origin);
};

#endif