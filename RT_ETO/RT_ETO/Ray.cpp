#include "stdafx.h"
#include "Ray.h"

Ray::Ray(vec3 _direction, vec3 _initial_position, RAY_TYPE _ray_type)
{
	this->ray_type = _ray_type;
	this->direction = _direction;
	this->initial_position = _initial_position;
}

Ray::~Ray()
{

}