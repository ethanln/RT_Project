#pragma once
#ifndef SCENE_FACADE_H
#define SCENE_FACADE_H

#include <glm/vec3.hpp>
#include <vector>
#include "Scene.h"
#include "Ray.h"
#include "CameraView.h"
#include "IntersectionResult.h"
#include "ShapeUtil.h"
#include "Vec3Util.h"
#include "SceneFacadeException.h"
#include "SceneException.h"

using namespace std;

class SceneFacade 
{
	private:
		Scene scene;

		/**
		* Checks to see which intersection instance is closest from the initial position.
		*/
		virtual IntersectionResult* get_closest_intersection(Ray ray, IntersectionResult* inter1, IntersectionResult* inter2);

	public:

		/**
		* Constructor.
		*/
		SceneFacade(Scene _scene);

		/**
		* Deconstructor.
		*/
		~SceneFacade();

		/**
		* Grabs the initial eye view ray.
		*/
		virtual Ray get_eyeview_ray(int x, int y) throw(SceneFacadeException);

		/**
		* Test for intersection in the scene with a given ray.
		*/
		virtual IntersectionResult test_for_intersection(Ray ray) throw(SceneFacadeException);
};

#endif