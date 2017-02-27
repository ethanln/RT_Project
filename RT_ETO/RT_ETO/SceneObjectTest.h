#pragma once
#ifndef SCENE_OBJECT_TEST_H
#define SCENE_OBJECT_TEST_H

#include "Test.h"
#include "SceneObject.h"
#include "Sphere.h"
#include "Triangle.h"
#include <glm/vec3.hpp>

using namespace std;

class SceneObjectTest : public Test
{
public:
	SceneObjectTest();

	~SceneObjectTest();

	virtual void print_header();

	virtual bool do_test();
};
#endif