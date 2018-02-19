#include "stdafx.h"
#include "Camera.h"

Camera::Camera(vec3 _position, vec3 _orientation)
{
	this->position = _position;
	this->orientation = _orientation;
}

Camera::Camera()
{
	this->position = vec3(0.0f, 0.0f, 0.0f);
	this->orientation = vec3(0.0f, 0.0f, 0.0f);
}

Camera::~Camera()
{

}

Camera Camera::clone()
{
	vec3 clone_position = vec3(this->position.x, this->position.y, this->position.z);
	vec3 clone_orientation = vec3(this->orientation.x, this->orientation.y, this->orientation.z);
	return Camera(clone_position, clone_orientation);
}