#pragma once
#ifndef SHAPE_TEST_H
#define SHAPE_TEST_H

#include "Test.h"
#include "Shape.h"
#include "Triangle.h"
#include "Sphere.h"

using namespace std;

class ShapeTest : public Test
{
	public:
		ShapeTest();

		~ShapeTest();

		virtual void print_header();

		virtual bool do_test();
};
#endif