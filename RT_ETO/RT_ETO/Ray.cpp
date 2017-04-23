#include "stdafx.h"
#include "Ray.h"

Ray::Ray(glm::vec3 _direction, glm::vec3 _initial_position)
{
	this->direction = _direction;
	this->initial_position = _initial_position;
}

Ray::~Ray()
{

}