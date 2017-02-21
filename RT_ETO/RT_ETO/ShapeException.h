#pragma once
#ifndef SHAPE_EXCEPTION_H
#define SHAPE_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class ShapeException : public exception
{
private:
	string msg;

public:
	ShapeException(const char* _msg);

	ShapeException(const string& _msg);

	virtual ~ShapeException() throw();

	virtual const char* what() const throw ();
};

#endif