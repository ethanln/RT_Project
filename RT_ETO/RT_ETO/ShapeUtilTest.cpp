#include "stdafx.h"
#include "ShapeUtilTest.h"

ShapeUtilTest::ShapeUtilTest() : Test()
{

}

ShapeUtilTest::~ShapeUtilTest()
{

}

void ShapeUtilTest::print_header()
{
	this->HEADER_PRINT("TEST: ShapeUtilTest class tests...");
}

bool ShapeUtilTest::do_test()
{
	bool is_pass = true;
	Triangle t1(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(6.0f, 2.0f, 2.0f), glm::vec3(-0.0f, -1.0f, -3.0f));
	glm::vec3 normalT1 = ShapeUtil::GET_TRIANGLE_NORMAL(t1, false);

	this->ASSERT_EQUALS("Check triangle normal one x.", normalT1.x, -2.0f);
	this->ASSERT_EQUALS("Check triangle normal one y.", normalT1.y, 19.0f);
	this->ASSERT_EQUALS("Check triangle normal one z.", normalT1.z, -9.0f);

	normalT1 = ShapeUtil::GET_TRIANGLE_NORMAL(t1, true);

	this->ASSERT_EQUALS("Check triangle normal with normalization one x.", normalT1.x, -0.0947027504f);
	this->ASSERT_EQUALS("Check triangle normal with normalization one y.", normalT1.y, 0.899676085f);
	this->ASSERT_EQUALS("Check triangle normal with normalization one z.", normalT1.z, -0.426162362f);

	Triangle t2(glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(-3.0f, 2.0f, 10.0f), glm::vec3(-1.0f, 3.0f, -3.0f));
	glm::vec3 normalT2 = ShapeUtil::GET_TRIANGLE_NORMAL(t2, false);

	this->ASSERT_EQUALS("Check triangle normal two x.", normalT2.x, -22.0f);
	this->ASSERT_EQUALS("Check triangle normal two y.", normalT2.y, -21.0f);
	this->ASSERT_EQUALS("Check triangle normal two z.", normalT2.z, -5.0f);

	normalT2 = ShapeUtil::GET_TRIANGLE_NORMAL(t2, true);

	this->ASSERT_EQUALS("Check triangle normal with normalization two x.", normalT2.x, -0.713774264f);
	this->ASSERT_EQUALS("Check triangle normal with normalization two y.", normalT2.y, -0.681329966f);
	this->ASSERT_EQUALS("Check triangle normal with normalization two z.", normalT2.z, -0.162221432f);


	Sphere s1(2.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	glm::vec3 normalS1 = ShapeUtil::GET_SPHERE_NORMAL(glm::vec3(-1.0f, 1.0f, 1.0f), s1, false);

	this->ASSERT_EQUALS("Check sphere normal one x.", normalS1.x, -2.0f);
	this->ASSERT_EQUALS("Check sphere normal one y.", normalS1.y, 0.0f);
	this->ASSERT_EQUALS("Check sphere normal one z.", normalS1.z, 0.0f);

	glm::vec3 normalS2 = ShapeUtil::GET_SPHERE_NORMAL(glm::vec3(1.0f, -1.0f, 1.0f), s1, false);

	this->ASSERT_EQUALS("Check sphere normal two x.", normalS2.x, 0.0f);
	this->ASSERT_EQUALS("Check sphere normal two y.", normalS2.y, -2.0f);
	this->ASSERT_EQUALS("Check sphere normal two z.", normalS2.z, 0.0f);

	return is_pass;
}