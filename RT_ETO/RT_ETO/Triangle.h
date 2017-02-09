#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glm/vec3.hpp>
#include "Shape.h"

using namespace std;

class Triangle : public Shape
{
	public:
		
		/**
		* First triangle point.
		*/
		glm::vec3 p1;

		/**
		* Second triangle point.
		*/
		glm::vec3 p2;

		/**
		* Third triangle point.
		*/
		glm::vec3 p3;

	public:

		/**
		* Triangle constructor.
		*/
		Triangle(glm::vec3 _p1, glm::vec3 _p2, glm::vec3 _p3);

		/**
		* Triangle deconstructor.
		*/
		~Triangle();
};

#endif