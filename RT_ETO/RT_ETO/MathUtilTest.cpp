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
	
	float d1 = 50.0f;
	float d2 = 180.0f;
	float d3 = 30.0f;

	this->ASSERT_EQUALS("Test from degrees to radians 1", TO_RADIANS(d1), 0.872664630f);
	this->ASSERT_EQUALS("Test from degrees to radians 2", TO_RADIANS(d2), PI);
	this->ASSERT_EQUALS("Test from degrees to radians 3", TO_RADIANS(d3), PI / 6.0f);

	float r1 = 2.0f * PI;
	float r2 = PI / 3.0f;

	this->ASSERT_EQUALS("Test from radians to degrees 1", TO_DEGREES(r1), 360.0f);
	this->ASSERT_EQUALS("Test from radians to degrees 2", TO_DEGREES(r2), 60.0f);
	return is_pass;
}