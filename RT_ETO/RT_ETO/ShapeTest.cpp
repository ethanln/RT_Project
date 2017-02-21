#include "stdafx.h"
#include "ShapeTest.h"

ShapeTest::ShapeTest()
{

}

ShapeTest::~ShapeTest()
{

}

void ShapeTest::print_header()
{
	this->HEADER_PRINT("TEST: Shape class tests...");
}

bool ShapeTest::do_test()
{
	bool is_pass = true;
	Shape* s = new Triangle(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(-3.0f, 1.0f, -2.0f));

	s->add_material("stuff", "0.0f");

	this->ASSERT_EQUALS("Test add material shape.", s->get_material("stuff"), "0.0f");

	try
	{
		s->get_material("ERROR");
	}
	catch (ShapeException& e)
	{
		this->ASSERT_EQUALS("Test improper material query.", e.what(), "Could not fetch shape material.");
	}


	return is_pass;
}