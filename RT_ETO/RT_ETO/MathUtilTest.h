#pragma once

#ifndef MATH_UTIL_TEST_H
#define MATH_UTIL_TEST_H

#include "Test.h"
#include "MathUtil.h"

class MathUtilTest : public Test
{
public:
	MathUtilTest();

	~MathUtilTest();

	virtual void print_header();

	virtual bool do_test();
};

#endif
