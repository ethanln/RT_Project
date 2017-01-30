#include "stdafx.h"
#include "ColorTest.h"

ColorTest::ColorTest()
{

}

ColorTest::~ColorTest()
{

}

void ColorTest::print_header()
{
	this->HEADER_PRINT("TEST: Color class tests...");
}

bool ColorTest::do_test()
{
	bool is_pass = true;

	Color* c1 = new Color(0.3f, 0.3f, 0.3f);
	Color* c2 = new Color(0.1f, 0.1f, 0.1f);

	// TEST COLOR ADD
	Color c3 = *c1 + *c2;

	this->ASSERT_EQUALS("Color basic add arithmetic test color.r", c3.r, 0.4f);
	this->ASSERT_EQUALS("Color basic add arithmetic test color.g", c3.g, 0.4f);
	this->ASSERT_EQUALS("Color basic add arithmetic test color.b", c3.b, 0.4f);

	// TEST COLOR SUBTRACT
	c3 = *c1 - *c2;

	this->ASSERT_EQUALS("Color basic subtract arithmetic test color.r", c3.r, 0.200000018f);
	this->ASSERT_EQUALS("Color basic subtract arithmetic test color.g", c3.g, 0.200000018f);
	this->ASSERT_EQUALS("Color basic subtract arithmetic test color.b", c3.b, 0.200000018f);

	// TEST COLOR MULTIPLY WITH FLOAT
	c3 *= 2.0f;

	this->ASSERT_EQUALS("Color multiply arithmetic with float test color.r", c3.r, 0.400000036f);
	this->ASSERT_EQUALS("Color multiply arithmetic with float test color.g", c3.g, 0.400000036f);
	this->ASSERT_EQUALS("Color multiply arithmetic with float test color.b", c3.b, 0.400000036f);

	// TEST COLOR DIVIDE WITH FLOAT
	Color c4(c3.r, c3.g, c3.b);
	c4 /= 2.0f;

	this->ASSERT_EQUALS("Color divide arithmetic with float test color.r", c4.r, 0.200000018f);
	this->ASSERT_EQUALS("Color divide arithmetic with float test color.g", c4.g, 0.200000018f);
	this->ASSERT_EQUALS("Color divide arithmetic with float test color.b", c4.b, 0.200000018f);

	// TEST COLOR MULTIPLY
	c4 *= *c2;

	this->ASSERT_EQUALS("Color multiply arithmetic test color.r", c4.r, 0.0200000014f);
	this->ASSERT_EQUALS("Color multiply arithmetic test color.g", c4.g, 0.0200000014f);
	this->ASSERT_EQUALS("Color multiply arithmetic test color.b", c4.b, 0.0200000014f);

	// TEST COLOR DIVIDE
	c4 /= *c2;

	this->ASSERT_EQUALS("Color divide arithmetic test color.r", c4.r, 0.200000018f);
	this->ASSERT_EQUALS("Color divide arithmetic test color.g", c4.g, 0.200000018f);
	this->ASSERT_EQUALS("Color divide arithmetic test color.b", c4.b, 0.200000018f);


	// TEST COLOR SUBTRACT AND ADD
	c3 = c3 - *c2 + *c1;

	this->ASSERT_EQUALS("Color subtract and add arithmetic test color.r", c3.r, 0.600000024f);
	this->ASSERT_EQUALS("Color subtract and add arithmetic test color.g", c3.g, 0.600000024f);
	this->ASSERT_EQUALS("Color subtract and add arithmetic test color.b", c3.b, 0.600000024f);

	// TEST COLOR SUBTRACT AND ADD WITH FLOAT
	c3 = c3 - *c2 + 0.2f;

	this->ASSERT_EQUALS("Color subtract and add arithmetic with float test color.r", c3.r, 0.699999988f);
	this->ASSERT_EQUALS("Color subtract and add arithmetic with float test color.g", c3.g, 0.699999988f);
	this->ASSERT_EQUALS("Color subtract and add arithmetic with float test color.b", c3.b, 0.699999988f);

	// TEST ADD OVERFLOW WITH FLOAT
	c3 += 0.7f;

	this->ASSERT_EQUALS("Color add overflow with float test color.r", c3.r, 1.0f);
	this->ASSERT_EQUALS("Color add overflow with float test color.g", c3.g, 1.0f);
	this->ASSERT_EQUALS("Color add overflow with float test color.b", c3.b, 1.0f);

	// TEST SUBTRACT OVERFLOW WITH FLOAT
	c3 -= 1.7f;

	this->ASSERT_EQUALS("Color subtract overflow with float test color.r", c3.r, 0.0f);
	this->ASSERT_EQUALS("Color subtract overflow with float test color.g", c3.g, 0.0f);
	this->ASSERT_EQUALS("Color subtract overflow with float test color.b", c3.b, 0.0f);

	// TEST ADD MULTIPILY OVERFLOW
	c3 = c3 + *c2 * 15.0f;

	this->ASSERT_EQUALS("Color add multiply overflow test color.r", c3.r, 1.0f);
	this->ASSERT_EQUALS("Color add multiply overflow test color.g", c3.g, 1.0f);
	this->ASSERT_EQUALS("Color add multiply overflow test color.b", c3.b, 1.0f);
	return is_pass;
}