#include "stdafx.h";
#include "Color.h"

Color::Color(float _r, float _g, float _b)
{
	this->r = _r;
	this->g = _g;
	this->b = _b;
}

Color::Color()
{
	this->r = 0.0f;
	this->g = 0.0f;
	this->b = 0.0f;
}

Color::~Color()
{
	// no deconstructor action required.
}

Color Color::operator +(const Color& obj)
{
	float nr = this->r + obj.r > 1.0f ? 1.0f : this->r + obj.r;
	float ng = this->g + obj.g > 1.0f ? 1.0f : this->g + obj.g;
	float nb = this->b + obj.b > 1.0f ? 1.0f : this->b + obj.b;

	nr = nr < 0.0f ? 0.0f : nr;
	ng = ng < 0.0f ? 0.0f : ng;
	nb = nb < 0.0f ? 0.0f : nb;

	return Color(nr, ng, nb);
}

Color Color::operator -(const Color& obj)
{
	float nr = this->r - obj.r > 1.0f ? 1.0f : this->r - obj.r;
	float ng = this->g - obj.g > 1.0f ? 1.0f : this->g - obj.g;
	float nb = this->b - obj.b > 1.0f ? 1.0f : this->b - obj.b;

	nr = nr < 0.0f ? 0.0f : nr;
	ng = ng < 0.0f ? 0.0f : ng;
	nb = nb < 0.0f ? 0.0f : nb;

	return Color(nr, ng, nb);
}

Color Color::operator *(const Color& obj)
{
	float nr = this->r * obj.r > 1.0f ? 1.0f : this->r * obj.r;
	float ng = this->g * obj.g > 1.0f ? 1.0f : this->g * obj.g;
	float nb = this->b * obj.b > 1.0f ? 1.0f : this->b * obj.b;

	nr = nr < 0.0f ? 0.0f : nr;
	ng = ng < 0.0f ? 0.0f : ng;
	nb = nb < 0.0f ? 0.0f : nb;

	return Color(nr, ng, nb);
}

Color Color::operator /(const Color& obj)
{
	float nr = this->r / obj.r > 1.0f ? 1.0f : this->r / obj.r;
	float ng = this->g / obj.g > 1.0f ? 1.0f : this->g / obj.g;
	float nb = this->b / obj.b > 1.0f ? 1.0f : this->b / obj.b;

	nr = nr < 0.0f ? 0.0f : nr;
	ng = ng < 0.0f ? 0.0f : ng;
	nb = nb < 0.0f ? 0.0f : nb;

	return Color(nr, ng, nb);
}

void Color::operator +=(const Color& obj)
{
	this->r += obj.r;
	this->g += obj.g;
	this->b += obj.b;

	this->r = this->r < 0.0f ? 0.0f : this->r;
	this->g = this->g < 0.0f ? 0.0f : this->g;
	this->b = this->b < 0.0f ? 0.0f : this->b;

	this->r = this->r > 1.0f ? 1.0f : this->r;
	this->g = this->g > 1.0f ? 1.0f : this->g;
	this->b = this->b > 1.0f ? 1.0f : this->b;

}

void Color::operator -=(const Color& obj)
{
	this->r -= obj.r;
	this->g -= obj.g;
	this->b -= obj.b;

	this->r = this->r < 0.0f ? 0.0f : this->r;
	this->g = this->g < 0.0f ? 0.0f : this->g;
	this->b = this->b < 0.0f ? 0.0f : this->b;

	this->r = this->r > 1.0f ? 1.0f : this->r;
	this->g = this->g > 1.0f ? 1.0f : this->g;
	this->b = this->b > 1.0f ? 1.0f : this->b;
}

void Color::operator *=(const Color& obj)
{
	this->r *= obj.r;
	this->g *= obj.g;
	this->b *= obj.b;

	this->r = this->r < 0.0f ? 0.0f : this->r;
	this->g = this->g < 0.0f ? 0.0f : this->g;
	this->b = this->b < 0.0f ? 0.0f : this->b;

	this->r = this->r > 1.0f ? 1.0f : this->r;
	this->g = this->g > 1.0f ? 1.0f : this->g;
	this->b = this->b > 1.0f ? 1.0f : this->b;
}

void Color::operator /=(const Color& obj)
{
	this->r /= obj.r;
	this->g /= obj.g;
	this->b /= obj.b;

	this->r = this->r < 0.0f ? 0.0f : this->r;
	this->g = this->g < 0.0f ? 0.0f : this->g;
	this->b = this->b < 0.0f ? 0.0f : this->b;

	this->r = this->r > 1.0f ? 1.0f : this->r;
	this->g = this->g > 1.0f ? 1.0f : this->g;
	this->b = this->b > 1.0f ? 1.0f : this->b;
}



Color Color::operator +(const float& obj)
{
	float nr = this->r + obj > 1.0f ? 1.0f : this->r + obj;
	float ng = this->g + obj > 1.0f ? 1.0f : this->g + obj;
	float nb = this->b + obj > 1.0f ? 1.0f : this->b + obj;

	nr = nr < 0.0f ? 0.0f : nr;
	ng = ng < 0.0f ? 0.0f : ng;
	nb = nb < 0.0f ? 0.0f : nb;

	return Color(nr, ng, nb);
}

Color Color::operator -(const float& obj)
{
	float nr = this->r - obj > 1.0f ? 1.0f : this->r - obj;
	float ng = this->g - obj > 1.0f ? 1.0f : this->g - obj;
	float nb = this->b - obj > 1.0f ? 1.0f : this->b - obj;

	nr = nr < 0.0f ? 0.0f : nr;
	ng = ng < 0.0f ? 0.0f : ng;
	nb = nb < 0.0f ? 0.0f : nb;

	return Color(nr, ng, nb);
}

Color Color::operator *(const float& obj)
{
	float nr = this->r * obj > 1.0f ? 1.0f : this->r * obj;
	float ng = this->g * obj > 1.0f ? 1.0f : this->g * obj;
	float nb = this->b * obj > 1.0f ? 1.0f : this->b * obj;

	nr = nr < 0.0f ? 0.0f : nr;
	ng = ng < 0.0f ? 0.0f : ng;
	nb = nb < 0.0f ? 0.0f : nb;

	return Color(nr, ng, nb);
}

Color Color::operator /(const float& obj)
{
	float nr = this->r / obj > 1.0f ? 1.0f : this->r / obj;
	float ng = this->g / obj > 1.0f ? 1.0f : this->g / obj;
	float nb = this->b / obj > 1.0f ? 1.0f : this->b / obj;

	nr = nr < 0.0f ? 0.0f : nr;
	ng = ng < 0.0f ? 0.0f : ng;
	nb = nb < 0.0f ? 0.0f : nb;

	return Color(nr, ng, nb);
}

void Color::operator +=(const float& obj)
{
	this->r += obj;
	this->g += obj;
	this->b += obj;

	this->r = this->r < 0.0f ? 0.0f : this->r;
	this->g = this->g < 0.0f ? 0.0f : this->g;
	this->b = this->b < 0.0f ? 0.0f : this->b;

	this->r = this->r > 1.0f ? 1.0f : this->r;
	this->g = this->g > 1.0f ? 1.0f : this->g;
	this->b = this->b > 1.0f ? 1.0f : this->b;
}

void Color::operator -=(const float& obj)
{
	this->r -= obj;
	this->g -= obj;
	this->b -= obj;

	this->r = this->r < 0.0f ? 0.0f : this->r;
	this->g = this->g < 0.0f ? 0.0f : this->g;
	this->b = this->b < 0.0f ? 0.0f : this->b;

	this->r = this->r > 1.0f ? 1.0f : this->r;
	this->g = this->g > 1.0f ? 1.0f : this->g;
	this->b = this->b > 1.0f ? 1.0f : this->b;
}

void Color::operator *=(const float& obj)
{
	this->r *= obj;
	this->g *= obj;
	this->b *= obj;

	this->r = this->r < 0.0f ? 0.0f : this->r;
	this->g = this->g < 0.0f ? 0.0f : this->g;
	this->b = this->b < 0.0f ? 0.0f : this->b;

	this->r = this->r > 1.0f ? 1.0f : this->r;
	this->g = this->g > 1.0f ? 1.0f : this->g;
	this->b = this->b > 1.0f ? 1.0f : this->b;
}

void Color::operator /=(const float& obj)
{
	this->r /= obj;
	this->g /= obj;
	this->b /= obj;

	this->r = this->r < 0.0f ? 0.0f : this->r;
	this->g = this->g < 0.0f ? 0.0f : this->g;
	this->b = this->b < 0.0f ? 0.0f : this->b;

	this->r = this->r > 1.0f ? 1.0f : this->r;
	this->g = this->g > 1.0f ? 1.0f : this->g;
	this->b = this->b > 1.0f ? 1.0f : this->b;
}