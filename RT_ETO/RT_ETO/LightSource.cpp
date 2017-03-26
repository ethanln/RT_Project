#include "stdafx.h"
#include "LightSource.h"

LightSource::LightSource(glm::vec3 _position)
{
	this->position = _position;
	this->color = Color(1.0f, 1.0f, 1.0f);
}

LightSource::LightSource(glm::vec3 _position, Color _color)
{
	this->position = _position;
	this->color = color;
}

LightSource::~LightSource()
{

}

glm::vec3 LightSource::get_position()
{
	return this->position;
}

Color LightSource::get_color() 
{
	return this->color;
}