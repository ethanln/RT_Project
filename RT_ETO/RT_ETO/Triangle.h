#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glm/vec3.hpp>
#include "Shape.h"

class Triangle : public Shape
{
	public:
		
		/**
		* First triangle point.
		*/
		vec3 p1;

		/**
		* Second triangle point.
		*/
		vec3 p2;

		/**
		* Third triangle point.
		*/
		vec3 p3;

	public:

		/**
		* Triangle constructor.
		*/
		Triangle(vec3 _p1, vec3 _p2, vec3 _p3);

		/**
		* Triangle deconstructor.
		*/
		~Triangle();

		/**
		* Calculates and returns the normal of the triangle.
		*/
		virtual vec3 get_normal(bool normalize, vec3 point = vec3(0, 0, 0));

		/**
		* Tests to see if a line collides with the triangle.
		*/
		virtual IntersectionResult test_line_collision(Ray ray);

		/**
		* Clone triangle instance.
		*/
		virtual Shape* clone() throw(ShapeException);

	private:
		
		/**
		* Checks to see if a ray intersects the triangle.
		*/
		bool does_intersect_triangle(vec3 direction, vec3 origin, vec3 intersection);

		/**
		* Checks to see if a point is inside the triangle.
		*/
		bool is_point_in_triangle(vec3 point);

		/**
		* Checks to see if a point is on the same plane as the triangle.
		*/
		bool is_on_plane(vec3 point);
};

#endif