#pragma once

#ifndef RAY_H
#define RAY_H

#include <glm/vec3.hpp>

using namespace std;

class Ray
{
	public:
		glm::vec3 direction;

		glm::vec3 initial_position;

	public:
		Ray(glm::vec3 _direction, glm::vec3 _initial_position);

		~Ray();
};

#endif