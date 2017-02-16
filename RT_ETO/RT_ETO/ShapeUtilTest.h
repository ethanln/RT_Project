#pragma once
#ifndef SHAPE_UTIL_TEST_H
#define SHAPE_UTIL_TEST_H

#include "Test.h"
#include "ShapeUtil.h"
#include "Sphere.h"
#include "Triangle.h"

class ShapeUtilTest : public Test
{
	public:
		ShapeUtilTest();

		~ShapeUtilTest();

		virtual void print_header();

		virtual bool do_test();
};

#endif