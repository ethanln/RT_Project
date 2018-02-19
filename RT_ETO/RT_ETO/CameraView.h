#pragma once

#ifndef CAMERA_VIEW_H
#define CAMERA_VIEW_H

#include <glm/mat4x4.hpp>
#include <stdexcept> 
#include <vector>
#include <math.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "Camera.h"
#include "Vec3Util.h"
#include "RayUtil.h"
#include "Ray.h"
#include "CameraViewException.h"

using namespace std;
using namespace glm;
using namespace MathUtil;

class CameraView
{
	private:
		/**
		* Camera instance.
		*/
		Camera* camera;

		/**
		* Camera view plane.
		*/
		vector<vector<vec3>> view_plane;

		/**
		* Look from.
		*/
		vec3 look_from;

		/**
		* Look at.
		*/
		vec3 look_at;

		/**
		* Dimension X
		*/
		int dim_x;

		/**
		* Dimension Y
		*/
		int dim_y;

		/**
		* Field of view.
		*/
		float fov;

		/**
		* Radius x of each pixel location
		*/
		float pixel_radius_x;

		/**
		* Radius y of each pixel location
		*/
		float pixel_radius_y;

	public:

		/**
		* CameraView constructor.
		*/
		CameraView(Camera* _camera, vec3 _look_from, vec3 _look_at, int _dim_x, int _dim_y, float _fov);

		/**
		* CameraView deconstructor.
		*/
		~CameraView();

		/**
		* Cast initial ray from cam postion to view plane, jittering is an option.
		*/
		virtual Ray get_initial_ray(int _x, int _y, bool is_normalized, bool is_jitter) throw(CameraViewException);

		/**
		* Set cam position.
		*/
		virtual void set_cam_pos(vec3 _new_pos);

		/**
		* Set cam orientation.
		*/
		virtual void set_cam_orientation(vec3 _new_orientation);

		/**
		* Get camera postion.
		*/
		virtual vec3 get_cam_pos();

		/**
		* Get camera orientation.
		*/
		virtual vec3 get_cam_orientation();

		/**
		* Get frustrum look from.
		*/
		virtual vec3 get_look_from();

		/**
		* Get frustrum look at.
		*/
		virtual vec3 get_look_at();
		
		/**
		* Get dimension x.
		*/
		virtual int get_dim_x();

		/**
		* Get dimension y.
		*/
		virtual int get_dim_y();

		/**
		* Get fov.
		*/
		virtual float get_fov();

		/**
		* Get coordinate at pixel location (x,y).
		*/
		virtual vec3 get_pixel_coor(int _x, int _y);

		/**
		* Clone camera view instance.
		*/
		virtual CameraView clone() throw(CameraViewException);

		/**
		* Print view plane table.
		*/
		virtual void print_viewplane(string filename);

	private:

		/**
		* Sets up the view plane coordinates.
		*/
		virtual void setup_view_plane_coor();
};

#endif 