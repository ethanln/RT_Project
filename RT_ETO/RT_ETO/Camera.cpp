#include "stdafx.h"
#include "Camera.h"

Camera::Camera(glm::vec3 _position, glm::vec3 _orientation)
{
	this->position = _position;
	this->orientation = _orientation;
}

Camera::Camera()
{
	this->position = glm::vec3(0.0f, 0.0f, 0.0f);
	this->orientation = glm::vec3(0.0f, 0.0f, 0.0f);
}

Camera::~Camera()
{

}

Camera Camera::clone()
{
	glm::vec3 clone_position = glm::vec3(this->position.x, this->position.y, this->position.z);
	glm::vec3 clone_orientation = glm::vec3(this->orientation.x, this->orientation.y, this->orientation.z);
	return Camera(clone_position, clone_orientation);
}