#pragma once

#ifndef VEC3_TEST_H
#define VEC3_TEST_H

#include "Test.h"
#include "Vec3Util.h"
#include <glm/vec3.hpp>

using namespace std;

class Vec3Test : public Test
{
	public:
		Vec3Test();

		~Vec3Test();

		virtual void print_header();

		virtual bool do_test();
};

#endif
