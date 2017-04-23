#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <map>
#include <string>
#include <exception>

#include "LightSource.h"
#include "CameraView.h"
#include "Shape.h"
#include "SceneObject.h"
#include "SceneException.h"

using namespace std;

class Scene {

	private:
		/**
		* Scene objects.
		*/
		map<string, SceneObject*> objects;

		/**
		* Light source of scene.
		*/
		LightSource* light_source;

		/**
		* Light source of scene.
		*/
		CameraView* camera_view;

	public:

		/**
		* Contructor.
		*/
		Scene();

		/**
		* Contructor.
		*/
		Scene(LightSource* _light_source, CameraView* _camera);

		/**
		* Decontructor.
		*/
		~Scene();

		/**
		* Adds new scene object to scene.
		*/
		virtual void add_scene_object(string name, SceneObject* _object) throw(SceneException);

		/**
		* Fetches a scene object from the scene.
		*/
		virtual SceneObject* get_scene_object(string name) throw(SceneException);

		/**
		* Fetches camera instance.
		*/
		virtual CameraView* get_camera_view();

		/**
		* Returns first iteration in memory of scene objects.
		*/
		virtual std::vector<SceneObject*>::iterator begin();

		/**
		* Returns first iteration in memory of scene objects.
		*/
		virtual std::vector<SceneObject*>::const_iterator begin() const;

		/**
		* Returns last iteration in memory of scene objects.
		*/
		virtual std::vector<SceneObject*>::iterator end();

		/**
		* Returns last iteration in memory of scene objects.
		*/
		virtual std::vector<SceneObject*>::const_iterator end() const;

		/**
		* Creates a copy of the object itself.
		*/
		virtual Scene clone();

};

#endif