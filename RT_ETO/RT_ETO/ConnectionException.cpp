#include "stdafx.h"
#include "ConnectionException.h"

ConnectionException::ConnectionException(const char* _msg)
{
	this->msg = _msg;
}

ConnectionException::ConnectionException(const string& _msg)
{
	this->msg = _msg;
}

ConnectionException::~ConnectionException() throw()
{

}

const char* ConnectionException::what() const throw ()
{
	return this->msg.c_str();
}