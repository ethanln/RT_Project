#include "stdafx.h"
#include "Vec3UtilTest.h"

Vec3UtilTest::Vec3UtilTest() : Test()
{

}

Vec3UtilTest::~Vec3UtilTest()
{

}

void Vec3UtilTest::print_header() 
{
	this->HEADER_PRINT("TEST: Vec3 Util class tests...");
}

bool Vec3UtilTest::do_test()
{
	// Test cross-product functionality.
	bool is_pass = true;
	vec3 v1 = vec3(3, 5, 3);
	vec3 v2 = vec3(5, 2, 3);
	vec3 result = CROSS_PRODUCT(v1, v2, false);

	this->ASSERT_EQUALS("Cross product: [3, 5, 3] X [5, 2, 3], x should be 9", result.x, 9.0f);
	this->ASSERT_EQUALS("Cross product: [3, 5, 3] X [5, 2, 3], y should be 6", result.y, 6.0f);
	this->ASSERT_EQUALS("Cross product: [3, 5, 3] X [5, 2, 3], z should be -19", result.z, -19.0f);

	v1 = vec3(-3, -9, -3);
	v2 = vec3(1, 7, 0);
	result = CROSS_PRODUCT(v1, v2, false);

	this->ASSERT_EQUALS("Cross product: [-3, -9, -3] X [1, 7, 0], x should be 21", result.x, 21.0f);
	this->ASSERT_EQUALS("Cross product: [-3, -9, -3] X [1, 7, 0], y should be -3", result.y, -3.0f);
	this->ASSERT_EQUALS("Cross product: [-3, -9, -3] X [1, 7, 0], z should be -12", result.z, -12.0f);

	return is_pass;
}