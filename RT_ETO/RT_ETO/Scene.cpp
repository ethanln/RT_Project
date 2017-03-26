#include "stdafx.h"
#include "Scene.h"

Scene::Scene() 
{
	this->light_source = new LightSource(glm::vec3(0.0f, 0.0f, 0.0f));
}

Scene::Scene(LightSource* _light_source)
{
	this->light_source = _light_source;
}

Scene::~Scene()
{
	// Delete all scene objects.
	for (map<string, SceneObject*>::iterator iter = this->objects.begin(); iter != this->objects.end(); ++iter) 
	{
		delete iter->second;
	}
	// Delete light source.
	delete this->light_source;
}

void Scene::add_scene_object(string name, SceneObject* _object)
{
	try 
	{
		this->objects.insert(std::pair<string, SceneObject*>(name, _object));
	}
	catch (exception& e)
	{
		// Throw Scene Exception if scene object does not exist.
		stringstream ss;
		ss << "Could not add " << name << " scene.";
		throw SceneException(ss.str());
	}
}

SceneObject* Scene::get_scene_object(string name)
{
	try
	{
		return this->objects[name];
	}
	catch (exception& e)
	{
		// Throw Scene Exception if scene object does not exist.
		stringstream ss;
		ss << "Scene object " << name << " does not exist.";
		throw SceneException(ss.str());
	}
}

std::vector<SceneObject*>::iterator Scene::begin()
{
	vector<SceneObject*> values;
	for (map<string, SceneObject*>::iterator iter = this->objects.begin(); iter != this->objects.end(); ++iter)
	{
		values.push_back(iter->second);
	}

	return values.begin();
}

std::vector<SceneObject*>::const_iterator Scene::begin() const
{
	vector<SceneObject*> values;
	for (map<string, SceneObject*>::const_iterator iter = this->objects.begin(); iter != this->objects.end(); ++iter)
	{
		values.push_back(iter->second);
	}

	return values.begin();
}

std::vector<SceneObject*>::iterator Scene::end()
{
	vector<SceneObject*> values;
	for (map<string, SceneObject*>::iterator iter = this->objects.begin(); iter != this->objects.end(); ++iter)
	{
		values.push_back(iter->second);
	}

	return values.end();
}

std::vector<SceneObject*>::const_iterator Scene::end() const
{
	vector<SceneObject*> values;
	for (map<string, SceneObject*>::const_iterator iter = this->objects.begin(); iter != this->objects.end(); ++iter)
	{
		values.push_back(iter->second);
	}

	return values.end();
}

Scene Scene::clone()
{	
	LightSource* cloned_light_source = new LightSource(this->light_source->get_position(), this->light_source->get_color());
	Scene scene = Scene(cloned_light_source);
	for (map<string, SceneObject*>::iterator iter = this->objects.begin(); iter != this->objects.end(); ++iter)
	{
		scene.add_scene_object(iter->first, iter->second);
	}

	return scene;
}