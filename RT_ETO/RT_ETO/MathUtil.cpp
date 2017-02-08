#include "stdafx.h"
#include "MathUtil.h"

using namespace std;

float MathUtil::PI = 3.14159265;

bool MathUtil::IS_SEED_GENERATED = false;

glm::vec3 MathUtil::NORMALIZE(glm::vec3 v)
{
	float dx = powf(v.x, 2.0f);
	float dy = powf(v.y, 2.0f);
	float dz = powf(v.z, 2.0f);

	float c = sqrtf(dx + dy + dz);

	float nx = v.x / c;
	float ny = v.y / c;
	float nz = v.z / c;

	return glm::vec3(nx, ny, nz);
}

float MathUtil::DOT(glm::vec3 v1, glm::vec3 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float MathUtil::MAG(glm::vec3 v)
{
	return sqrt(pow(v.x, 2.0f) + pow(v.y, 2.0f) + pow(v.z, 2.0f));
}

float MathUtil::TO_RADIANS(float degree)
{
	return (degree * PI) / 180.0f;
}

float MathUtil::TO_DEGREES(float radians)
{
	return (radians * 180.0f) / PI;
}

glm::vec3 MathUtil::CAST_RAY(glm::vec3 p1, glm::vec3 p2, bool is_normalized)
{
	// TEST - unit test.

	// Calculate ray, and normalize it if flagged to do so.
	glm::vec3 ray = is_normalized ? MathUtil::NORMALIZE(p2 - p1) : p2 - p1;
	return ray;
}

glm::vec3 MathUtil::CAST_RAY_JITTER(glm::vec3 p1, glm::vec3 p2, float radius_x, float radius_y, bool is_normalized)
{
	// TEST
	MathUtil::INITIALIZE_RANDOM_SEED();

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
	glm::vec3 ray = is_normalized ? MathUtil::NORMALIZE(variation_coor - p1) : variation_coor - p1;
	return ray;
}

glm::vec3 MathUtil::CAST_RAY_REFLECTION()
{
	// IMPLEMENT
	return glm::vec3(0.0f, 0.0f, 0.0f);
}

glm::vec3 MathUtil::CAST_RAY_REFLECTION_GLOSS()
{
	// IMPLEMENT
	return glm::vec3(0.0f, 0.0f, 0.0f);
}

glm::vec3 MathUtil::CAST_RAY_REFRACTION_GLOSS()
{
	// IMPLEMENT
	return glm::vec3(0.0f, 0.0f, 0.0f);
}

void MathUtil::INITIALIZE_RANDOM_SEED()
{
	if (!MathUtil::IS_SEED_GENERATED) 
	{
		srand(static_cast <unsigned> (time(0)));
		MathUtil::IS_SEED_GENERATED = true;
	}
}