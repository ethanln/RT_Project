#include "stdafx.h"
#include "ShapeException.h"

ShapeException::ShapeException(const char* _msg)
{
	this->msg = _msg;
}

ShapeException::ShapeException(const string& _msg)
{
	this->msg = _msg;
}

ShapeException::~ShapeException() throw()
{

}

const char* ShapeException::what() const throw ()
{
	return this->msg.c_str();
}