#include "stdafx.h"
#include "CameraViewTest.h"

CameraViewTest::CameraViewTest() : Test()
{

}

CameraViewTest::~CameraViewTest()
{

}

void CameraViewTest::print_header()
{
	this->HEADER_PRINT("TEST: CameraView class tests...");
}

bool CameraViewTest::do_test()
{
	bool is_pass = true;

	CameraView view = CameraView(new Camera(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(20.0f, 20.0f, 20.0f)), glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, 0.0f), 500, 500, 45.0f);

	view.print_viewplane("../../output/view_test.csv");

	Ray ray = view.get_initial_ray(0, 0, false, false);

	ASSERT_EQUALS("Test cast ray without normalization x-coor.", -10.8239222f, ray.direction.x);
	ASSERT_EQUALS("Test cast ray without normalization y-coor.", 10.8239222f, ray.direction.y);
	ASSERT_EQUALS("Test cast ray without normalization z-coor.", -10.0000000f, ray.direction.z);

	ray = view.get_initial_ray(0, 0, true, false);

	ASSERT_EQUALS("Test cast ray with normalization x-coor.", -0.591979980f, ray.direction.x);
	ASSERT_EQUALS("Test cast ray with normalization y-coor.", 0.591979980f, ray.direction.y);
	ASSERT_EQUALS("Test cast ray with normalization z-coor.", -0.546918154f, ray.direction.z);
	
	ASSERT_EQUALS("Test view plane pixel x-coordinate.", -10.8239222f, view.get_pixel_coor(0, 0).x);
	ASSERT_EQUALS("Test view plane pixel y-coordinate.", 10.8239222f, view.get_pixel_coor(0, 0).y);

	ASSERT_EQUALS("Test view plane pixel x-coordinate.", 10.7806759f, view.get_pixel_coor(499, 0).x);
	ASSERT_EQUALS("Test view plane pixel y-coordinate.", 10.8239222f, view.get_pixel_coor(499, 0).y);

	ASSERT_EQUALS("Test view plane pixel x-coordinate.", -10.823922f, view.get_pixel_coor(0, 499).x);
	ASSERT_EQUALS("Test view plane pixel y-coordinate.", -10.7806759f, view.get_pixel_coor(0, 499).y);

	ASSERT_EQUALS("Test view plane pixel x-coordinate.", 10.7806759f, view.get_pixel_coor(499, 499).x);
	ASSERT_EQUALS("Test view plane pixel y-coordinate.", -10.7806759f, view.get_pixel_coor(499, 499).y);

	return is_pass;
}