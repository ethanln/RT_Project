#pragma once
#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include <vector>
#include "Shape.h"
#include "ImageBuffer.h"
#include "Color.h"
#include "ImageBufferException.h"
#include "SceneObjectException.h"

using namespace std;

class SceneObject {
	private:
		/**
		* Shape meshes of object.
		*/
		map<string, Shape*> shapes;

		/**
		* Bump map buffer.
		*/
		ImageBuffer* bump_map;

		/**
		* Texture map buffer.
		*/
		ImageBuffer* texture_map;

		/**
		* Materials of object.
		*/
		map<string, string> materials;

	public:

		/**
		* Contructor.
		*/
		SceneObject();

		/**
		* Decontructor.
		*/
		virtual ~SceneObject();

		/**
		* Load a bump map buffer into the scene object.
		*/
		virtual void load_bump_map(ImageBuffer* _bump_map);

		/**
		* Load a texture map buffer into the scene object.
		*/
		virtual void load_texture_map(ImageBuffer* _texture_map);

		/**
		* Fetches pixel from bump map with specified location.
		*/
		virtual Color get_bump_map_pixel(int x, int y) throw(SceneObjectException);
		
		/**
		* Fetches pixel from texture map with specified location.
		*/
		virtual Color get_texture_map_pixel(int x, int y) throw(SceneObjectException);

		/**
		* Returns list structure of all shape data in the object.
		*/
		virtual vector<Shape*> get_shapes();

		/**
		* Returns a shape instance from the list of shapes.
		*/
		virtual Shape* get_shape(string id);

		/**
		* Adds shape data to the objects list structure.
		*/
		virtual void add_shape(Shape* shape);

		/**
		* Add material to shape.
		*/
		virtual void add_material(string key, string value) throw(SceneObjectException);

		/**
		* Get material from shape.
		*/
		virtual string get_material(string key) throw(SceneObjectException);

		/**
		* Check if material exists.
		*/
		virtual bool has_material(string key) throw(SceneObjectException);

		/**
		* Clone scene object instance.
		*/
		virtual SceneObject clone() throw(SceneObjectException);
};

#endif