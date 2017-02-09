#pragma once

#ifndef MATH_UTIL_TEST_H
#define MATH_UTIL_TEST_H

#include "Test.h"
#include "MathUtil.h"
#include <glm/vec3.hpp>

using namespace std;

class MathUtilTest : public Test
{
	public:
		MathUtilTest();

		~MathUtilTest();

		virtual void print_header();

		virtual bool do_test();
};

#endif
