#pragma once

#ifndef RAY_H
#define RAY_H

#include <glm/vec3.hpp>

using namespace std;
using namespace glm;

class Ray
{
	public:
		vec3 direction;

		vec3 initial_position;

	public:
		Ray(vec3 _direction, vec3 _initial_position);

		~Ray();
};

#endif