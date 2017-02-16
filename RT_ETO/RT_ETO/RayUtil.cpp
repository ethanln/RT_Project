#include "stdafx.h"
#include "RayUtil.h"

bool RayUtil::IS_SEED_GENERATED = false;

glm::vec3 RayUtil::CAST_RAY(glm::vec3 p1, glm::vec3 p2, bool is_normalized)
{
	// Calculate ray, and normalize it if flagged to do so.
	glm::vec3 ray = is_normalized ? Vec3Util::NORMALIZE(p2 - p1) : p2 - p1;
	return ray;
}

glm::vec3 RayUtil::CAST_RAY_JITTER(glm::vec3 p1, glm::vec3 p2, float radius_x, float radius_y, bool is_normalized)
{
	RayUtil::INITIALIZE_RANDOM_SEED();

	// Get the x variation between the minimum and maximum x edges.
	float HI_X = p2.x + radius_x;
	float LO_X = p2.x - radius_x;
	float variation_X = LO_X + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI_X - LO_X)));

	// Get the y variation between the minimum and maximum y edges.
	float HI_Y = p2.y + radius_y;
	float LO_Y = p2.y - radius_y;
	float variation_Y = LO_Y + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI_Y - LO_Y)));

	glm::vec3 variation_coor = glm::vec3(variation_X, variation_Y, p2.z);

	// Calculate ray, and normalize it if flagged to do so.
	glm::vec3 ray = is_normalized ? Vec3Util::NORMALIZE(variation_coor - p1) : variation_coor - p1;
	return ray;
}

glm::vec3 RayUtil::CAST_RAY_REFLECTION()
{
	// IMPLEMENT, will do this after testing JITTERING
	return glm::vec3(0.0f, 0.0f, 0.0f);
}

glm::vec3 RayUtil::CAST_RAY_REFLECTION_GLOSS()
{
	// IMPLEMENT, will do this after testing JITTERING
	return glm::vec3(0.0f, 0.0f, 0.0f);
}

glm::vec3 RayUtil::CAST_RAY_REFRACTION_GLOSS()
{
	// IMPLEMENT, will do this after testing JITTERING
	return glm::vec3(0.0f, 0.0f, 0.0f);
}

void RayUtil::INITIALIZE_RANDOM_SEED()
{
	if (!RayUtil::IS_SEED_GENERATED)
	{
		srand(static_cast <unsigned> (time(0)));
		RayUtil::IS_SEED_GENERATED = true;
	}
}