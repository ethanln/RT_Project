#pragma once
#ifndef SCENE_EXCEPTION_H
#define SCENE_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class SceneException : public exception
{
private:
	string msg;

public:
	SceneException(const char* _msg);

	SceneException(const string& _msg);

	virtual ~SceneException() throw();

	virtual const char* what() const throw ();
};

#endif