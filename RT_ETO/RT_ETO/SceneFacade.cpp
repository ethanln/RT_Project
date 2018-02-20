#include "stdafx.h"
#include "SceneFacade.h"

SceneFacade::SceneFacade(Scene _scene)
{
	this->scene = _scene;
}

SceneFacade::~SceneFacade()
{

}

Ray SceneFacade::get_eyeview_ray(int x, int y)
{
	// TEST
	try
	{
		return this->scene.get_camera_view()->get_initial_ray(x, y, true, true);
	}
	catch (CameraViewException &e)
	{
		throw new SceneFacadeException(e.what());
	}
}

IntersectionResult SceneFacade::test_for_intersection(Ray ray)
{
	// TEST
	IntersectionResult* result = nullptr;

	// Iterate through each scene object in the scene.
	for (SceneObject* scene_object : this->scene)
	{
		// Iterate through each shape of the scene object.
		for (Shape* shape : scene_object->get_shapes())
		{
			IntersectionResult* temp_result = nullptr;
			switch (shape->shape_type)
			{
				case Shape::SHAPE_TYPE::SPHERE:
				{
					// If shape is a sphere, test for its intersection.
					Sphere* sphere = static_cast<Sphere*>(shape);
					temp_result = &sphere->test_line_collision(ray); 
					break;
				}
				case Shape::SHAPE_TYPE::TRIANGLE:
				{
					// If shape is a sphere, test for its intersection.
					Triangle* triangle = static_cast<Triangle*>(shape);
					temp_result = &triangle->test_line_collision(ray);
					break;
				}
				default:
					break;
			}
			
			// If the ray intersects a shape, check if its closer than the current intersection instance.
			if (temp_result->does_intersect)
			{
				result = this->get_closest_intersection(ray, result, temp_result);
			}
		}
	}

	return *result;
}

IntersectionResult* SceneFacade::get_closest_intersection(Ray ray, IntersectionResult* inter1, IntersectionResult* inter2)
{
	// TEST

	// If the first intersection instance is null, return the second intersection instance.
	if (inter1 == nullptr)
	{
		return inter2;
	}

	// Calculate the distances between the 
	float dist1 = MAGNITUDE(ray.initial_position - inter1->intersection);
	float dist2 = MAGNITUDE(ray.initial_position - inter2->intersection);

	// Compare magnitudes
	return dist1 <= dist2 ? inter1 : inter2;
}
