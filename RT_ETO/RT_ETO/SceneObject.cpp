#include "stdafx.h"
#include "SceneObject.h"

SceneObject::SceneObject() 
{
	this->bump_map = nullptr;
	this->texture_map = nullptr;
}

SceneObject::~SceneObject()
{
	delete this->bump_map;
	delete this->texture_map;

	// Delete all shape pointers.
	for (auto it = shapes.begin(); it != shapes.end(); ++it) {
		delete *it;
	}
	shapes.clear();
}

void SceneObject::load_bump_map(ImageBuffer* _bump_map)
{
	// TEST
	this->bump_map = _bump_map;
}

void SceneObject::load_texture_map(ImageBuffer* _texture_map)
{
	// TEST
	this->texture_map = _texture_map;
}

Color SceneObject::get_bump_map_pixel(int x, int y)
{
	if (this->bump_map == nullptr) 
	{
		// Throw Scene Object Exception if there is no bump map.
		stringstream ss;
		ss << "Scene object does not contain a bump map buffer.";
		throw SceneObjectException(ss.str());
	}

	try
	{
		Color* c = this->bump_map->get_pixel(x, y);
		return *c;
	}
	catch (ImageBufferException& e)
	{
		// Throw Scene Object Exception if indices are out of range.
		stringstream ss;
		ss << "Pixel index (" << x << ", " << y << ") out of range for bump map.";
		throw SceneObjectException(ss.str());
	}
}

Color SceneObject::get_texture_map_pixel(int x, int y)
{
	if (this->texture_map == nullptr)
	{
		// Throw Scene Object Exception if there is no texture map.
		stringstream ss;
		ss << "Scene object does not contain a texture map buffer.";
		throw SceneObjectException(ss.str());
	}

	try
	{
		Color* c = this->texture_map->get_pixel(x, y);
		return *c;
	}
	catch (ImageBufferException& e)
	{
		// Throw Scene Object Exception if indices are out of range.
		stringstream ss;
		ss << "Pixel index (" << x << ", " << y << ") out of range for texture map.";
		throw SceneObjectException(ss.str());
	}
}

vector<Shape*> SceneObject::get_shapes()
{
	return this->shapes;
}

void SceneObject::add_shape(Shape* shape)
{
	this->shapes.push_back(shape);
}

std::vector<Shape*>::iterator SceneObject::begin()
{
	return this->shapes.begin();
}

std::vector<Shape*>::const_iterator SceneObject::begin() const
{
	return this->shapes.begin();
}

std::vector<Shape*>::iterator SceneObject::end()
{
	return this->shapes.end();
}

std::vector<Shape*>::const_iterator SceneObject::end() const
{
	return this->shapes.end();
}

