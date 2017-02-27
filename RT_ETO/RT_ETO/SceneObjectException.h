#pragma once
#ifndef SCENE_OBJECT_EXCEPTION_H
#define SCENE_OBJECT_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class SceneObjectException : public exception
{
private:
	string msg;

public:
	SceneObjectException(const char* _msg);

	SceneObjectException(const string& _msg);

	virtual ~SceneObjectException() throw();

	virtual const char* what() const throw ();
};

#endif