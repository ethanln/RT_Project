#include "stdafx.h"
#include "MathUtil.h"

using namespace std;
using namespace MathUtil;

float MathUtil::TO_RADIANS(float degree)
{
	return (degree * PI) / 180.0f;
}

float MathUtil::TO_DEGREES(float radians)
{
	return (radians * 180.0f) / PI;
}