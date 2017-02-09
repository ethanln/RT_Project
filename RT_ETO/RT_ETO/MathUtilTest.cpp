#include "stdafx.h"
#include "MathUtilTest.h"

MathUtilTest::MathUtilTest()
{

}

MathUtilTest::~MathUtilTest()
{

}

void MathUtilTest::print_header()
{
	this->HEADER_PRINT("TEST: MathUtil class tests...");
}

bool MathUtilTest::do_test()
{
	bool is_pass = true;
	const int ITERATIONS = 25;
	float radius = 2.0f;

	for (unsigned int i = 0; i < ITERATIONS; i++)
	{
		stringstream ss;
		ss << i;
		glm::vec3 v1 = MathUtil::CAST_RAY_JITTER(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, 0.0f), radius, radius, false);

		ASSERT_GREATER_THAN_EQUAL("Test 1 cast ray jitter x-coor ITERATION " + ss.str() , v1.x, -radius);
		ASSERT_GREATER_THAN_EQUAL("Test 1 cast ray jitter y-coor ITERATION " + ss.str(), v1.y, -radius);

		ASSERT_LESS_THAN_EQUAL("Test 1 cast ray jitter x-coor ITERATION " + ss.str(), v1.x, radius);
		ASSERT_LESS_THAN_EQUAL("Test 1 cast ray jitter y-coor ITERATION " + ss.str(), v1.y, radius);
	}
	

	radius = 0.02165f;
	for (unsigned int i = 0; i < ITERATIONS; i++)
	{
		stringstream ss;
		ss << i;
		glm::vec3 v2 = MathUtil::CAST_RAY_JITTER(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(-10.8239f, 10.8239f, 0.0f), radius, radius, false);

		ASSERT_GREATER_THAN_EQUAL("Test 2 cast ray jitter x-coor ITERATION " + ss.str(), v2.x, -10.8239f - radius);
		ASSERT_GREATER_THAN_EQUAL("Test 2 cast ray jitter y-coor ITERATION " + ss.str(), v2.y, 10.8239f - radius);

		ASSERT_LESS_THAN_EQUAL("Test 2 cast ray jitter x-coor ITERATION " + ss.str(), v2.x, -10.8239f + radius);
		ASSERT_LESS_THAN_EQUAL("Test 2 cast ray jitter y-coor ITERATION " + ss.str(), v2.y, 10.8239f + radius);
	}
	return is_pass;
}