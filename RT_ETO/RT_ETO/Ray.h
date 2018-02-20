#pragma once

#ifndef RAY_H
#define RAY_H

#include <glm/vec3.hpp>

using namespace std;
using namespace glm;

class Ray
{
	public:
		enum RAY_TYPE {
			TRANSMISSION,
			REFLECTION,
			SHADOW,
			PRIMARY,
			NONE
		};

		RAY_TYPE ray_type;

		vec3 direction;

		vec3 initial_position;

	public:
		Ray(vec3 _direction, vec3 _initial_position, RAY_TYPE _ray_type = RAY_TYPE::NONE);

		~Ray();
};

#endif