#pragma once
#ifndef CAMERA_VIEW_EXCEPTION_H
#define CAMERA_VIEW_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class CameraViewException : public exception
{
private:
	string msg;

public:
	CameraViewException(const char* _msg);

	CameraViewException(const string& _msg);

	virtual ~CameraViewException() throw();

	virtual const char* what() const throw ();
};

#endif