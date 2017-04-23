#pragma once
#ifndef CONNECTION_EXCEPTION_H
#define CONNECTION_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class ConnectionException : public exception
{
private:
	string msg;

public:
	ConnectionException(const char* _msg);

	ConnectionException(const string& _msg);

	virtual ~ConnectionException() throw();

	virtual const char* what() const throw ();
};

#endif