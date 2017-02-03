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