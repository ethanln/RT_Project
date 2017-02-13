#pragma once

#ifndef RAY_UTIL_TEST_H
#define RAY_UTIL_TEST_H

#include "Test.h"
#include "RayUtil.h"
#include <glm/vec3.hpp>

using namespace std;

class RayUtilTest : public Test
{
	public:
		RayUtilTest();

		~RayUtilTest();

		virtual void print_header();

		virtual bool do_test();
};

#endif
