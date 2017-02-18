#pragma once
#ifndef IMAGE_BUFFER_EXCEPTION_H
#define IMAGE_BUFFER_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class ImageBufferException : public exception
{
	private:
		string msg;

	public:
		ImageBufferException(const char* _msg);

		ImageBufferException(const string& _msg);

		virtual ~ImageBufferException() throw();

		virtual const char* what() const throw ();
};

#endif