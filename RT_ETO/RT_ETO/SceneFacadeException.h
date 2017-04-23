#pragma once
#ifndef SCENE_FACADE_EXCEPTION_H
#define SCENE_FACADE_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class SceneFacadeException : public exception
{
	private:
		string msg;

	public:
		SceneFacadeException(const char* _msg);

		SceneFacadeException(const string& _msg);

		virtual ~SceneFacadeException() throw();

		virtual const char* what() const throw ();
};

#endif