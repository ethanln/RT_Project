#pragma once

#ifndef RAY_H
#define RAY_H

#include <glm/vec3.hpp>

using namespace std;

class Ray
{
	public:
		glm::vec3 ray;

	public:
		Ray(glm::vec3 _ray);

		~Ray();
};

#endif