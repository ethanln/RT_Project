#pragma once
#ifndef LIGHT_SOURCE_H
#define LIGHT_SOURCE_H

#include <glm/vec3.hpp>
#include "Color.h"
using namespace std;

class LightSource {

	private:
		/**
		* Position of light source.
		*/
		glm::vec3 position;

		/**
		* Color of light source.
		*/
		Color color;

	public:

		/**
		* Contructor.
		*/
		LightSource(glm::vec3 _position);

		/**
		* Contructor.
		*/
		LightSource(glm::vec3 _position, Color _color);

		/**
		* Decontructor.
		*/
		virtual ~LightSource();

		/**
		* Fetches light source position.
		*/
		virtual glm::vec3 get_position();

		/**
		* Fetches light source color.
		*/
		virtual Color get_color();
};

#endif
