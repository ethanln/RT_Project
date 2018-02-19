#include "stdafx.h"
#include "LightSource.h"

LightSource::LightSource(vec3 _position)
{
	this->position = _position;
	this->color = Color(1.0f, 1.0f, 1.0f);
}

LightSource::LightSource(vec3 _position, Color _color)
{
	this->position = _position;
	this->color = color;
}

LightSource::~LightSource()
{

}

vec3 LightSource::get_position()
{
	return this->position;
}

Color LightSource::get_color() 
{
	return this->color;
}

LightSource LightSource::clone()
{
	vec3 clone_position = vec3(this->position.x, this->position.y, this->position.z);
	Color clone_color = Color(this->color.r, this->color.g, this->color.b);
	return LightSource(clone_position, clone_color);
}