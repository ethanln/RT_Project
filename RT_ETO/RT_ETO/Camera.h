#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/vec3.hpp>

using namespace std;

class Camera
{
	public:
		/**
		* Camera position.
		*/
		glm::vec3 position;

		/**
		* Camera orienation.
		*/
		glm::vec3 orientation;

	public:

		/**
		* Camera constructor.
		*/
		Camera(glm::vec3 _position, glm::vec3 _orientation);

		/**
		* Camera constructor.
		*/
		Camera();

		/**
		* Camera deconstructor.
		*/
		~Camera();
};

#endif