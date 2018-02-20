#include "stdafx.h"
#include "SceneObjectTest.h"

SceneObjectTest::SceneObjectTest()
{

}

SceneObjectTest::~SceneObjectTest()
{

}

void SceneObjectTest::print_header()
{
	this->HEADER_PRINT("TEST: SceneObject class tests...");
}

bool SceneObjectTest::do_test()
{
	bool is_pass = true;

	SceneObject obj;

	obj.add_material("stuff", "0.0f");

	this->ASSERT_EQUALS("Test add material object.", obj.get_material("stuff"), "0.0f");

	try
	{
		obj.get_material("ERROR");
	}
	catch (SceneObjectException& e)
	{
		this->ASSERT_EQUALS("Test improper material query.", e.what(), "Could not fetch object material.");
	}

	try 
	{
		obj.get_bump_map_pixel(0, 0);
	}
	catch (SceneObjectException& e)
	{
		ASSERT_EQUALS("Test null pointer access error for bump map.", "Scene object does not contain a bump map buffer.", e.what());
	}

	obj.load_bump_map(new ImageBuffer(40, 40));
	try
	{
		obj.get_bump_map_pixel(40, 40);
	}
	catch (SceneObjectException& e)
	{
		ASSERT_EQUALS("Test index out of range access error for bump map.", "Pixel index (40, 40) out of range for bump map.", e.what());
	}

	Color cbm = obj.get_bump_map_pixel(0, 0);
	ASSERT_EQUALS("Test bump map pixel r.", 0.0f, cbm.r);
	ASSERT_EQUALS("Test bump map pixel g.", 0.0f, cbm.g);
	ASSERT_EQUALS("Test bump map pixel b.", 0.0f, cbm.b);
	
	try
	{
		obj.get_texture_map_pixel(0, 0);
	}
	catch (SceneObjectException& e)
	{
		ASSERT_EQUALS("Test null pointer access error for texture map.", "Scene object does not contain a texture map buffer.", e.what());
	}

	obj.load_texture_map(new ImageBuffer(40, 40));
	try
	{
		obj.get_texture_map_pixel(40, 40);
	}
	catch (SceneObjectException& e)
	{
		ASSERT_EQUALS("Test index out of range access error for texture map.", "Pixel index (40, 40) out of range for texture map.", e.what());
	}

	Color ctm = obj.get_bump_map_pixel(0, 0);
	ASSERT_EQUALS("Test texture map pixel r.", 0.0f, ctm.r);
	ASSERT_EQUALS("Test texture map pixel g.", 0.0f, ctm.g);
	ASSERT_EQUALS("Test texture map pixel b.", 0.0f, ctm.b);


	ASSERT_EQUALS("Test initial list size of geometry shapes.", 0, obj.get_shapes().size());
	obj.add_shape(new Sphere(2.0f, vec3(0.0f, 1.0f, 2.0f)));
	for (auto s : obj.get_shapes())
	{
		Sphere* sphere = static_cast<Sphere*>(s);
		ASSERT_EQUALS("Test iteration process of object with Sphere params radius", 2.0f, sphere->radius);
		ASSERT_EQUALS("Test iteration process of object with Sphere params center x", 0.0f, sphere->center.x);
		ASSERT_EQUALS("Test iteration process of object with Sphere params center y", 1.0f, sphere->center.y);
		ASSERT_EQUALS("Test iteration process of object with Sphere params center z", 2.0f, sphere->center.z);
	}

	SceneObject clone_obj = obj.clone();
	this->ASSERT_EQUALS("Test clone object material equal to object material", obj.get_material("stuff"), clone_obj.get_material("stuff"));

	clone_obj.add_material("stuff_1", "1.0f");
	this->ASSERT_FALSE("Test object to see if it does not contain the new clone material.", obj.has_material("stuff_1"));
	this->ASSERT_TRUE("Test clone object to see if it does contain the new clone material.", clone_obj.has_material("stuff_1"));

	for (auto s : clone_obj.get_shapes())
	{
		Sphere* sphere = static_cast<Sphere*>(s);
		ASSERT_EQUALS("Test iteration process of clone object with Sphere params radius", 2.0f, sphere->radius);
		ASSERT_EQUALS("Test iteration process of clone object with Sphere params center x", 0.0f, sphere->center.x);
		ASSERT_EQUALS("Test iteration process of clone object with Sphere params center y", 1.0f, sphere->center.y);
		ASSERT_EQUALS("Test iteration process of clone object with Sphere params center z", 2.0f, sphere->center.z);
	}

	return is_pass;
}