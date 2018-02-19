#pragma once

#ifndef VEC3_UTIL_TEST
#define VEC3_UTIL_TEST

#include "Test.h"
#include "Vec3Util.h"

using namespace std;
using namespace Vec3Util;

class Vec3UtilTest : public Test 
{
	public:
		Vec3UtilTest();

		~Vec3UtilTest();

		virtual void print_header();

		virtual bool do_test();
};

#endif