#include "stdafx.h"
#include "ImageBufferException.h"

ImageBufferException::ImageBufferException(const char* _msg)
{
	this->msg = _msg;
}

ImageBufferException::ImageBufferException(const string& _msg)
{
	this->msg = _msg;
}

ImageBufferException::~ImageBufferException() throw()
{

}

const char* ImageBufferException::what() const throw ()
{
	return this->msg.c_str();
}