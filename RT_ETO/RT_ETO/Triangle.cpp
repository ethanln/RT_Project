#include "stdafx.h"
#include "Triangle.h"

Triangle::Triangle(glm::vec3 _p1, glm::vec3 _p2, glm::vec3 _p3) : Shape(SHAPE_TYPE::TRIANGLE)
{
	this->p1 = _p1;
	this->p2 = _p2;
	this->p3 = _p3;
}

Triangle::~Triangle()
{

}

Shape* Triangle::clone()
{
	try
	{
		glm::vec3 clone_p1 = glm::vec3(this->p1.x, this->p1.y, this->p1.z);
		glm::vec3 clone_p2 = glm::vec3(this->p2.x, this->p2.y, this->p2.z);
		glm::vec3 clone_p3 = glm::vec3(this->p3.x, this->p3.y, this->p3.z);

		Shape* clone_triangle = new Triangle(clone_p1, clone_p2, clone_p3);

		return clone_triangle;
	}
	catch (exception& e)
	{
		throw new ShapeException("Could not clone triangle object.");
	}
}