#pragma once

#ifndef CAMERA_VIEW_H
#define CAMERA_VIEW_H

#include <glm/mat4x4.hpp>
#include <vector>
#include <math.h>
#include "Camera.h"
#include "MathUtil.h"

using namespace std;

class CameraView
{
	private:
		/**
		* Camera instance.
		*/
		Camera* cam;

		/**
		* Camera view plane.
		*/
		vector<vector<glm::vec3>> view_plane;

		/**
		* Look from.
		*/
		glm::vec3 look_from;

		/**
		* Look at.
		*/
		glm::vec3 look_at;

		/**
		* Dimension X
		*/
		float dim_x;

		/**
		* Dimension Y
		*/
		float dim_y;

		/**
		* Field of view.
		*/
		float fov;

	public:

		/**
		* CameraView constructor.
		*/
		CameraView(glm::vec3 _pos, glm::vec3 _orientation, glm::vec3 _look_from, glm::vec3 _look_at, float _dim_x, float _dim_y, float _fov);

		/**
		* CameraView deconstructor.
		*/
		~CameraView();

		/**
		* Cast initial ray from cam postion to view plane.
		*/
		virtual glm::vec3 cast_ray(int _x, int _y);

		/**
		* Cast initial ray from cam postion to view plane with variation.
		*/
		virtual glm::vec3 cast_jitter_ray(int _x, int _y);

		/**
		* Set cam position.
		*/
		virtual void set_cam_pos(glm::vec3 _new_pos);

		/**
		* Set cam orientation.
		*/
		virtual void set_cam_orientation(glm::vec3 _new_orientation);

		/**
		* Get camera postion.
		*/
		virtual glm::vec3 get_cam_pos();

		/**
		* Get camera orientation.
		*/
		virtual glm::vec3 get_cam_orientation();
		
		/**
		* Get dimension x.
		*/
		virtual int get_dim_x();

		/**
		* Get dimension y.
		*/
		virtual int get_dim_y();

		/**
		* Print view plane table;
		*/
		virtual void print_viewplane();

	private:

		/**
		* Sets up the view plane coordinates.
		*/
		virtual void setup_view_plane_coor();
};

#endif 