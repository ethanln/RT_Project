#pragma once
#ifndef RAY_UTIL_H
#define RAY_UTIL_H

#include <glm/vec3.hpp>
#include "MathUtil.h"

class RayUtil
{
	private:
		/**
		* Random seed variable state
		*/
		static bool IS_SEED_GENERATED;

	public:
		/**
		* Global get vector ray.
		*/
		static vec3 CAST_RAY(vec3 p1, vec3 p2, bool is_normalized);

		/**
		* Global get vector ray with jittering.
		*/
		static vec3 CAST_RAY_JITTER(vec3 p1, vec3 p2, float radius_x, float radius_y, bool is_normalized);

		/**
		* Global get vector reflection ray.
		*/
		static vec3 CAST_RAY_REFLECTION();

		/**
		* Global get vector reflection ray with gloss.
		*/
		static vec3 CAST_RAY_REFLECTION_GLOSS();

		/**
		* Global get vector refraction ray.
		*/
		static vec3 CAST_RAY_REFRACTION();

		/**
		* Set random seed generator.
		*/
		static void INITIALIZE_RANDOM_SEED();
};

#endif