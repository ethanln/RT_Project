#include "stdafx.h"
#include "SceneFacadeException.h"

SceneFacadeException::SceneFacadeException(const char* _msg)
{
	this->msg = _msg;
}

SceneFacadeException::SceneFacadeException(const string& _msg)
{
	this->msg = _msg;
}

SceneFacadeException::~SceneFacadeException() throw()
{

}

const char* SceneFacadeException::what() const throw ()
{
	return this->msg.c_str();
}