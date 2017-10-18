#include "stdafx.h"
#include "LightSourceException.h";

LightSourceException::LightSourceException(const char* _msg)
{
	this->msg = _msg;
}

LightSourceException::LightSourceException(const string& _msg)
{
	this->msg = _msg;
}

LightSourceException::~LightSourceException() throw()
{

}

const char* LightSourceException::what() const throw ()
{
	return this->msg.c_str();
}