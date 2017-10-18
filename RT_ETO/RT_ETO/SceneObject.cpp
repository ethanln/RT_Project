#include "stdafx.h"
#include "SceneObject.h"

SceneObject::SceneObject() 
{
	this->bump_map = nullptr;
	this->texture_map = nullptr;
}

SceneObject::~SceneObject()
{
	// Delete the texture map image buffer.
	if (this->bump_map != nullptr)
	{
		delete this->bump_map;
	}
	
	// Delete the texture map image buffer.
	if (this->texture_map != nullptr)
	{
		delete this->texture_map;
	}
	
	// Delete all shape pointers.
	for (unsigned int i = 0; i < this->shapes.size(); i++)
	{
		Shape* color = this->shapes.at(i);
		delete color;
	}
	shapes.clear();
}

void SceneObject::load_bump_map(ImageBuffer* _bump_map)
{
	this->bump_map = _bump_map;
}

void SceneObject::load_texture_map(ImageBuffer* _texture_map)
{
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

void SceneObject::add_material(string key, string value)
{
	try
	{
		this->materials.insert(std::pair<string, string>(key, value));
	}
	catch (exception& e)
	{
		throw SceneObjectException("Could not insert material into object.");
	}
}

string SceneObject::get_material(string key)
{
	try
	{
		return this->materials[key];
	}
	catch (exception& e)
	{
		throw SceneObjectException("Could not fetch shape object.");
	}
}

bool SceneObject::has_material(string key)
{
	return this->materials.count(key) > 0;
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

SceneObject SceneObject::clone()
{
	try
	{
		SceneObject* clone_scene_object = new SceneObject();
		// Add all shape information to the cloned object.
		for (Shape* shape : this->shapes) 
		{
			Shape* clone_shape = shape->clone();
			clone_scene_object->add_shape(clone_shape);
		}

		// Copy the bump_map buffer instance over.
		if (this->bump_map != nullptr)
		{
			ImageBuffer* clone_bump_map = new ImageBuffer(this->bump_map->clone());
			clone_scene_object->load_bump_map(clone_bump_map);
		}

		// Copy the texture map buffer instance over.
		if (this->texture_map != nullptr)
		{
			ImageBuffer* clone_texture_map = new ImageBuffer(this->texture_map->clone());
			clone_scene_object->load_texture_map(clone_texture_map);
		}
	

		// Add all material values to the cloned object.
		for (map<string, string>::iterator iter = this->materials.begin(); iter != this->materials.end(); ++iter)
		{
			clone_scene_object->add_material(iter->first, iter->second);
		}

		return *clone_scene_object;
	}
	catch (exception& e)
	{
		throw SceneObjectException("Could not clone scene object.");
	}
}

