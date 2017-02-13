#include "stdafx.h"
#include "RayUtilTest.h"

RayUtilTest::RayUtilTest()
{

}

RayUtilTest::~RayUtilTest()
{

}

void RayUtilTest::print_header()
{
	this->HEADER_PRINT("TEST: RayUtil class tests...");
}

bool RayUtilTest::do_test()
{
	bool is_pass = true;
	const int ITERATIONS = 25;
	float radius = 2.0f;

	for (unsigned int i = 0; i < ITERATIONS; i++)
	{
		stringstream ss;
		ss << i;
		glm::vec3 v1 = RayUtil::CAST_RAY_JITTER(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, 0.0f), radius, radius, false);

		stringstream sx;
		sx << fixed << setprecision(4) << v1.x << " > " << -radius;
		stringstream sy;
		sy << fixed << setprecision(4) << v1.y << " > " << -radius;

		ASSERT_GREATER_THAN_EQUAL("Test 1 jitter-x ITERATION-" + ss.str() + "- RESULT=(" + sx.str() + ")", v1.x, -radius);
		ASSERT_GREATER_THAN_EQUAL("Test 1 jitter-y ITERATION-" + ss.str() + "- RESULT=(" + sy.str() + ")", v1.y, -radius);

		sx.str("");
		sy.str("");

		sx << fixed << setprecision(4) << v1.x << " < " << radius;
		sy << fixed << setprecision(4) << v1.y << " < " << radius;

		ASSERT_LESS_THAN_EQUAL("Test 1 jitter-x ITERATION-" + ss.str() + "- RESULT=(" + sx.str() + ")", v1.x, radius);
		ASSERT_LESS_THAN_EQUAL("Test 1 jitter-y ITERATION-" + ss.str() + "- RESULT=(" + sy.str() + ")", v1.y, radius);
	}
	

	radius = 0.02165f;
	for (unsigned int i = 0; i < ITERATIONS; i++)
	{
		stringstream ss;
		ss << i;
		glm::vec3 v2 = RayUtil::CAST_RAY_JITTER(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(-10.8239f, 10.8239f, 0.0f), radius, radius, false);

		stringstream sx;
		sx << fixed << setprecision(4) << v2.x << " > " << -10.8239f - radius;
		stringstream sy;
		sy << fixed << setprecision(4) << v2.y << " > " << 10.8239f - radius;

		ASSERT_GREATER_THAN_EQUAL("Test 2 jitter-x ITERATION-" + ss.str() + "- RESULT=(" + sx.str() + ")", v2.x, -10.8239f - radius);
		ASSERT_GREATER_THAN_EQUAL("Test 2 jitter-y ITERATION-" + ss.str() + "- RESULT=(" + sx.str() + ")", v2.y, 10.8239f - radius);

		sx.str("");
		sy.str("");

		sx << fixed << setprecision(4) << v2.x << " < " << -10.8239f + radius;
		sy << fixed << setprecision(4) << v2.y << " < " << 10.8239f + radius;

		ASSERT_LESS_THAN_EQUAL("Test 2 jitter-x ITERATION-" + ss.str() + "- RESULT=(" + sx.str() + ")", v2.x, -10.8239f + radius);
		ASSERT_LESS_THAN_EQUAL("Test 2 jitter-y ITERATION-" + ss.str() + "- RESULT=(" + sx.str() + ")", v2.y, 10.8239f + radius);
	}
	return is_pass;
}