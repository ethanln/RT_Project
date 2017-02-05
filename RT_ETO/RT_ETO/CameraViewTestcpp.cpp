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

	CameraView view = CameraView(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(20.0f, 20.0f, 20.0f), glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, 0.0f), 500, 500, 45.0f);

	view.print_viewplane("../../output/view_test.csv");

	glm::vec3 ray = view.cast_ray(0, 0, false);

	ASSERT_EQUALS("Test cast ray without normalization x-coor.", 10.8239222f, ray.x);
	ASSERT_EQUALS("Test cast ray without normalization y-coor.", -10.8239222f, ray.y);
	ASSERT_EQUALS("Test cast ray without normalization z-coor.", 10.0000000f, ray.z);

	ray = view.cast_ray(0, 0, true);

	ASSERT_EQUALS("Test cast ray with normalization x-coor.", 0.591979980f, ray.x);
	ASSERT_EQUALS("Test cast ray with normalization y-coor.", -0.591979980f, ray.y);
	ASSERT_EQUALS("Test cast ray with normalization z-coor.", 0.546918154f, ray.z);

	return is_pass;
}