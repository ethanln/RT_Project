#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Shape.h"
#include "ImageBuffer.h"
#include "Color.h"

using namespace std;

class SceneObject {
	private:
		/**
		* Shape meshes of object.
		*/
		vector<Shape> shapes;

		/**
		* Bump map buffer.
		*/
		ImageBuffer bump_map;

		/**
		* Texture map buffer.
		*/
		ImageBuffer texture_map;

	public:

		SceneObject();

		SceneObject(ImageBuffer _bump_map);

		SceneObject(ImageBuffer _bump_map, ImageBuffer _texture_map);

		SceneObject(ImageBuffer _bump_map, ImageBuffer _texture_map, vector<Shape> _shapes);

		virtual ~SceneObject();

		virtual void load_bump_map(ImageBuffer _bump_map);

		virtual void load_texture_map(ImageBuffer _texture_map);

		virtual Color get_bump_map_pixel(int x, int y);
		
		virtual Color get_texture_map_pixel(int x, int y);

		virtual vector<Shape> get_shapes();

		virtual void add_shape(Shape shape);
};

#endif