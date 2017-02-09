#pragma once
#ifndef CAMERA_VIEW_TEST_H
#define CAMERA_VIEW_TEST_H

#include "Test.h"
#include "CameraView.h"
#include <glm/vec3.hpp>

using namespace std;

class CameraViewTest : public Test
{
	public:
		CameraViewTest();

		~CameraViewTest();

		virtual void print_header();

		virtual bool do_test();
};
#endif