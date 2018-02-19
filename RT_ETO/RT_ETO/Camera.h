#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/vec3.hpp>

using namespace std;
using namespace glm;

class Camera
{
	public:
		/**
		* Camera position.
		*/
		vec3 position;

		/**
		* Camera orienation.
		*/
		vec3 orientation;

	public:

		/**
		* Camera constructor.
		*/
		Camera(vec3 _position, vec3 _orientation);

		/**
		* Camera constructor.
		*/
		Camera();

		/**
		* Camera deconstructor.
		*/
		~Camera();

		/**
		* Clone camera instance;
		*/
		Camera clone();
};

#endif