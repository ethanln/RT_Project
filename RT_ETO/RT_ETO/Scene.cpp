#include "stdafx.h"
#include "Scene.h"

Scene::Scene() 
{
	this->camera_view = new CameraView(new Camera(vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f)), vec3(0.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f), 500, 500, 22.5);
}

Scene::Scene(CameraView* _camera)
{
	this->camera_view = _camera;
}

Scene::~Scene()
{
	// Delete all scene objects.
	for (map<string, SceneObject*>::iterator iter = this->objects.begin(); iter != this->objects.end(); ++iter) 
	{
		delete iter->second;
	}
	
	// Delete all light sources.
	for (vector<LightSource*>::iterator iter = this->light_sources.begin(); iter != this->light_sources.end(); ++iter) 
	{
		delete *iter;
	}

	// Delete light source.
	delete this->camera_view;
}

void Scene::add_scene_object(string name, SceneObject* _object)
{
	// TEST
	try 
	{
		this->objects.insert(std::pair<string, SceneObject*>(name, _object));
	}
	catch (exception& e)
	{
		// Throw Scene Exception if scene object could not be added.
		stringstream ss;
		ss << "Could not add " << name << " scene.";
		throw SceneException(ss.str());
	}
}

SceneObject* Scene::get_scene_object(string name)
{
	// TEST
	// Check to see if the key value exists in the map.
	if (this->objects.count(name) == 0) 
	{
		stringstream ss;
		ss << "Scene object " << name << " does not exist.";
		throw SceneException(ss.str());
	}

	try
	{
		return this->objects[name];
	}
	catch (exception& e)
	{
		// Throw Scene Exception if scene object could not be fetched..
		stringstream ss;
		ss << "Scene object " << name << " could not be fetched.";
		throw SceneException(ss.str());
	}
}

void Scene::add_light_source(LightSource* _light_source) 
{
	// TEST
	try 
	{
		this->light_sources.push_back(_light_source);
	}
	catch (exception& e) 
	{
		// Throw Scene Exception if light source could not be added.
		stringstream ss;
		ss << "Light source could not be added.";
		throw SceneException(ss.str());
	}
}

LightSource* Scene::get_light_source(int index)
{
	if (this->light_sources.size() >= index) 
	{
		// Throw Scene Exception if light source does not exist.
		stringstream ss;
		ss << "Light source does not exist at index " << index;
		throw SceneException(ss.str());
	}

	try 
	{
		return this->light_sources.at(index);
	}
	catch (exception& e)
	{
		stringstream ss;
		ss << "Light source could not be fetched.";
		throw SceneException(ss.str());
	}
}

int Scene::get_light_source_count() 
{
	return this->light_sources.size();
}

void Scene::set_camera_view(CameraView* _camera_view)
{
	this->camera_view = _camera_view;
}

CameraView* Scene::get_camera_view()
{
	return this->camera_view;
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
	// TEST
	Scene scene;
	/*LightSource* cloned_light_source = new LightSource(this->light_source->get_position(), this->light_source->get_color());
	CameraView* cloned_camera_view = new CameraView(this->camera_view->get_cam_pos(), 
													this->camera_view->get_cam_orientation(), 
													this->camera_view->get_look_from(), 
													this->camera_view->get_look_at(), 
													this->camera_view->get_dim_x(),
													this->camera_view->get_dim_y(),
													this->camera_view->get_fov());

	Scene scene = Scene(cloned_light_source, cloned_camera_view);
	for (map<string, SceneObject*>::iterator iter = this->objects.begin(); iter != this->objects.end(); ++iter)
	{
		scene.add_scene_object(iter->first, iter->second);
	}*/

	return scene;
}