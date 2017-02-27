#include "stdafx.h"
#include "SceneObjectException.h"

SceneObjectException::SceneObjectException(const char* _msg)
{
	this->msg = _msg;
}

SceneObjectException::SceneObjectException(const string& _msg)
{
	this->msg = _msg;
}

SceneObjectException::~SceneObjectException() throw()
{

}

const char* SceneObjectException::what() const throw ()
{
	return this->msg.c_str();
}