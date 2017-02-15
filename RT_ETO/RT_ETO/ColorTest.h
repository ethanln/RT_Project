#pragma once
#ifndef COLOR_TEST_H
#define COLOR_TEST_H

#include "Test.h"
#include "Color.h"

class ColorTest : public Test
{
	public:
		ColorTest();

		~ColorTest();

		virtual void print_header();

		virtual bool do_test();
};

#endif
