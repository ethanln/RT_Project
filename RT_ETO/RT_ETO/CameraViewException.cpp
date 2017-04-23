#include "stdafx.h"
#include "CameraViewException.h"

CameraViewException::CameraViewException(const char* _msg)
{
	this->msg = _msg;
}

CameraViewException::CameraViewException(const string& _msg)
{
	this->msg = _msg;
}

CameraViewException::~CameraViewException() throw()
{

}

const char* CameraViewException::what() const throw ()
{
	return this->msg.c_str();
}