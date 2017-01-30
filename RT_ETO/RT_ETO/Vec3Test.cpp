#include "stdafx.h"
#include "Vec3Test.h"

Vec3Test::Vec3Test() : Test()
{

}

Vec3Test::~Vec3Test()
{

}

void Vec3Test::print_header()
{
	this->HEADER_PRINT("TEST: Vec3 class tests...");
}

bool Vec3Test::do_test()
{
	bool is_pass = true;
	glm::vec3 v1(1.0f, 1.0f, 1.0f);
	glm::vec3 v2(4.0f, 4.0f, 4.0f);

	// TEST VEC3 ADD
	glm::vec3 v3 = v1 + v2;


	this->ASSERT_EQUALS("Vec3 basic add arithmetic test ved.x", v3.x, 5.0f);
	this->ASSERT_EQUALS("Vec3 basic add arithmetic test ved.y", v3.y, 5.0f);
	this->ASSERT_EQUALS("Vec3 basic add arithmetic test vec.z", v3.z, 5.0f);


	// TEST VEC3 SUBTRACT
	v3 -= v1;

	this->ASSERT_EQUALS("Vec3 basic subtract arithmetic test ved.x", v3.x, 4.0f);
	this->ASSERT_EQUALS("Vec3 basic subtract arithmetic test ved.y", v3.y, 4.0f);
	this->ASSERT_EQUALS("Vec3 basic subtract arithmetic test vec.z", v3.z, 4.0f);


	// TEST VEC3 MULTIPLY
	v3 *= v3;

	this->ASSERT_EQUALS("Vec3 basic multiply arithmetic test ved.x", v3.x, 16.0f);
	this->ASSERT_EQUALS("Vec3 basic multiply arithmetic test ved.y", v3.y, 16.0f);
	this->ASSERT_EQUALS("Vec3 basic multiply arithmetic test vec.z", v3.z, 16.0f);


	// TEST VEC3 DIVIDE
	v3 /= v2;

	this->ASSERT_EQUALS("Vec3 basic divide arithmetic test ved.x", v3.x, 4.0f);
	this->ASSERT_EQUALS("Vec3 basic divide arithmetic test ved.y", v3.y, 4.0f);
	this->ASSERT_EQUALS("Vec3 basic divide arithmetic test vec.z", v3.z, 4.0f);
	
	// TEST VEC3 DOT
	float dot_product = MathUtil::DOT(v3, v3);
	this->ASSERT_EQUALS("Vec3 dot product", dot_product, 48.0f);

	// TEST VEC3 NORMALIZE
	v3 = MathUtil::NORMALIZE(v3);

	this->ASSERT_EQUALS("Vec3 basic divide arithmetic test ved.x", v3.x, 0.577350259f);
	this->ASSERT_EQUALS("Vec3 basic divide arithmetic test ved.y", v3.y, 0.577350259f);
	this->ASSERT_EQUALS("Vec3 basic divide arithmetic test vec.z", v3.z, 0.577350259f);

	// TEST VEC3 ADD WITH FLOAT
	v3 += 1.0f;

	this->ASSERT_EQUALS("Vec3 basic add arithmetic test with float ved.x", v3.x, 1.57735026f);
	this->ASSERT_EQUALS("Vec3 basic add arithmetic test with float ved.y", v3.y, 1.57735026f);
	this->ASSERT_EQUALS("Vec3 basic add arithmetic test with float vec.z", v3.z, 1.57735026f);

	// TEST VEC3 SUBTRACT WITH FLOAT
	v3 = 1.0f - v3;

	this->ASSERT_EQUALS("Vec3 basic subtract arithmetic test with float ved.x", v3.x, -0.577350259f);
	this->ASSERT_EQUALS("Vec3 basic subtract arithmetic test with float ved.y", v3.y, -0.577350259f);
	this->ASSERT_EQUALS("Vec3 basic subtract arithmetic test with float vec.z", v3.z, -0.577350259f);

	return is_pass;
}