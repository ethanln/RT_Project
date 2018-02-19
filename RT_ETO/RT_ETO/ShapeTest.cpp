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
	Shape* shape = new Triangle(vec3(0.0f, 0.0f, 0.0f), vec3(1.0f, 1.0f, 1.0f), vec3(-3.0f, 1.0f, -2.0f));
	Shape* clone_shape = shape->clone();

	Triangle* triangle = static_cast<Triangle*>(shape);
	Triangle* clone_triangle = static_cast<Triangle*>(clone_shape);
	this->ASSERT_EQUALS("Test clone triangle x equals to triangle x.", triangle->p1.x, clone_triangle->p1.x);
	this->ASSERT_EQUALS("Test clone triangle y equals to triangle y.", triangle->p1.y, clone_triangle->p1.y);
	this->ASSERT_EQUALS("Test clone triangle z equals to triangle z.", triangle->p1.z, clone_triangle->p1.z);

	Sphere* sphere = new Sphere(2.0f, vec3(1.0f, 1.0f, 1.0f));
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

	// Test Triangle normal calculation.
	Triangle t1(vec3(1.0f, 1.0f, 1.0f), vec3(6.0f, 2.0f, 2.0f), vec3(-0.0f, -1.0f, -3.0f));
	vec3 normalT1 = t1.get_normal(false); 

	this->ASSERT_EQUALS("Check triangle normal one x.", normalT1.x, -2.0f);
	this->ASSERT_EQUALS("Check triangle normal one y.", normalT1.y, 19.0f);
	this->ASSERT_EQUALS("Check triangle normal one z.", normalT1.z, -9.0f);

	normalT1 = t1.get_normal(true);

	this->ASSERT_EQUALS("Check triangle normal with normalization one x.", normalT1.x, -0.0947027504f);
	this->ASSERT_EQUALS("Check triangle normal with normalization one y.", normalT1.y, 0.899676085f);
	this->ASSERT_EQUALS("Check triangle normal with normalization one z.", normalT1.z, -0.426162362f);

	Triangle t2(vec3(0.0f, 1.0f, 1.0f), vec3(-3.0f, 2.0f, 10.0f), vec3(-1.0f, 3.0f, -3.0f));
	vec3 normalT2 = t2.get_normal(false);

	this->ASSERT_EQUALS("Check triangle normal two x.", normalT2.x, -22.0f);
	this->ASSERT_EQUALS("Check triangle normal two y.", normalT2.y, -21.0f);
	this->ASSERT_EQUALS("Check triangle normal two z.", normalT2.z, -5.0f);

	normalT2 = t2.get_normal(true);

	this->ASSERT_EQUALS("Check triangle normal with normalization two x.", normalT2.x, -0.713774264f);
	this->ASSERT_EQUALS("Check triangle normal with normalization two y.", normalT2.y, -0.681329966f);
	this->ASSERT_EQUALS("Check triangle normal with normalization two z.", normalT2.z, -0.162221432f);

	// Test Sphere normal calculation.
	Sphere s1(2.0f, vec3(1.0f, 1.0f, 1.0f));
	vec3 normalS1 = s1.get_normal(false, vec3(-1.0f, 1.0f, 1.0f));

	this->ASSERT_EQUALS("Check sphere normal one x.", normalS1.x, -2.0f);
	this->ASSERT_EQUALS("Check sphere normal one y.", normalS1.y, 0.0f);
	this->ASSERT_EQUALS("Check sphere normal one z.", normalS1.z, 0.0f);

	vec3 normalS2 = s1.get_normal(false, vec3(1.0f, -1.0f, 1.0f));

	this->ASSERT_EQUALS("Check sphere normal two x.", normalS2.x, 0.0f);
	this->ASSERT_EQUALS("Check sphere normal two y.", normalS2.y, -2.0f);
	this->ASSERT_EQUALS("Check sphere normal two z.", normalS2.z, 0.0f);


	// Test Triangle intersection functionality.
	Triangle interTri = Triangle(vec3(0.0f, 0.0f, 0.0f), vec3(1.0f, 1.0f, 0.0f), vec3(2.0f, 0.0f, 0.0f));
	Ray ray = Ray(vec3(0.0f, 0.0f, 1.0f), vec3(1.0f, 0.5f, -1.0f));
	IntersectionResult result = interTri.test_line_collision(ray);

	this->ASSERT_TRUE("Test ray [0, 0, 1] intersection result for triangle starting from [1, 0.5, -1], should intersect", result.does_intersect);

	ray = Ray(vec3(0.0f, 0.0f, 1.0f), vec3(1.0f, 1.0f, -1.0f));
	result = interTri.test_line_collision(ray);

	this->ASSERT_TRUE("Test ray [0, 0, 1] intersection result for triangle starting from [1, 1, -1], should intersect", result.does_intersect);

	ray = Ray(vec3(0.0f, 0.0f, 1.0f), vec3(0.4f, 0.6f, -1.0f));
	result = interTri.test_line_collision(ray);

	this->ASSERT_FALSE("Test ray [0, 0, 1] intersection result for triangle starting from [0.4, 0.6, -1], should not intersect", result.does_intersect);

	ray = Ray(vec3(0.0f, 0.0f, 1.0f), vec3(1.0f, -0.1f, -1.0f));
	result = interTri.test_line_collision(ray);

	this->ASSERT_FALSE("Test ray [0, 0, 1] intersection result for triangle starting from [1, -0.1, -1], should not intersect", result.does_intersect);

	// Test Sphere intersection functionality.
	Sphere interSphere = Sphere(1.0f, vec3(0.0f, 0.0f, 0.0f));
	ray = Ray(vec3(0.5f, 0.5f, 1.0f), vec3(-0.5f, -0.5f, -1.0f));
	result = interSphere.test_line_collision(ray);

	this->ASSERT_TRUE("Test ray [0.5, 0.5, 1] intersection result for sphere starting from [-0.5, -0.5, -1.0], should intersect", result.does_intersect);

	ray = Ray(vec3(1.0f, 1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f));
	result = interSphere.test_line_collision(ray);

	this->ASSERT_TRUE("Test ray [1.0, 1.0, 1.0] intersection result for sphere starting from [0.0, 0.0, 0.0], should intersect", result.does_intersect);

	ray = Ray(vec3(0.0f, 0.0f, 1.0f), vec3(0.99f, 0.0f, -1.0f));
	result = interSphere.test_line_collision(ray);

	this->ASSERT_TRUE("Test ray [0.0, 0.0, 1.0] intersection result for sphere starting from [0.99, 0.0, -1.0], should intersect", result.does_intersect);

	ray = Ray(vec3(0.0f, 0.0f, 1.0f), vec3(1.0f, 0.0f, -1.0f));
	result = interSphere.test_line_collision(ray);

	this->ASSERT_FALSE("Test ray [0.0, 0.0, 1.0] intersection result for sphere starting from [1.0, 0.0, -1.0], should not intersect", result.does_intersect);

	ray = Ray(vec3(-1.0f, 0.0f, 0.0f), vec3(1.0f, 0.0f, -1.0f));
	result = interSphere.test_line_collision(ray);

	this->ASSERT_FALSE("Test ray [-1.0, 0.0, 0.0] intersection result for sphere starting from [1.0, 0.0, -1.0], should not intersect", result.does_intersect);

	return is_pass;
}