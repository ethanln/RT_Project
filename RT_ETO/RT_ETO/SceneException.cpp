#include "stdafx.h"
#include "SceneException.h"

SceneException::SceneException(const char* _msg)
{
	this->msg = _msg;
}

SceneException::SceneException(const string& _msg)
{
	this->msg = _msg;
}

SceneException::~SceneException() throw()
{

}

const char* SceneException::what() const throw ()
{
	return this->msg.c_str();
}