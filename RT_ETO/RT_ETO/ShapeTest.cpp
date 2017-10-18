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
	Shape* shape = new Triangle(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(-3.0f, 1.0f, -2.0f));
	Shape* clone_shape = shape->clone();

	Triangle* triangle = static_cast<Triangle*>(shape);
	Triangle* clone_triangle = static_cast<Triangle*>(clone_shape);
	this->ASSERT_EQUALS("Test clone triangle x equals to triangle x.", triangle->p1.x, clone_triangle->p1.x);
	this->ASSERT_EQUALS("Test clone triangle y equals to triangle y.", triangle->p1.y, clone_triangle->p1.y);
	this->ASSERT_EQUALS("Test clone triangle z equals to triangle z.", triangle->p1.z, clone_triangle->p1.z);

	Sphere* sphere = new Sphere(2.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	Sphere* clone_sphere = static_cast<Sphere*>(sphere->clone());

	this->ASSERT_EQUALS("Test clone sphere center x equals to sphere center x.", sphere->center.x, clone_sphere->center.x);
	this->ASSERT_EQUALS("Test clone sphere center y equals to sphere center y.", sphere->center.y, clone_sphere->center.y);
	this->ASSERT_EQUALS("Test clone sphere center z equals to sphere center z.", sphere->center.z, clone_sphere->center.z);

	this->ASSERT_EQUALS("Test clone sphere radius equals to sphere radius.", sphere->radius, clone_sphere->radius);

	clone_sphere->radius = 5.0f;

	this->ASSERT_NOT_EQUAL("Test clone sphere radius is not equals to sphere radius.", sphere->radius, clone_sphere->radius);

	delete shape;
	delete clone_shape;
	delete sphere;
	delete clone_sphere;

	return is_pass;
}