#ifndef ITEST_H
#define ITEST_H

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

class ITest
{
	public:
		virtual ~ITest() {}

		virtual void print_header() = 0; 

		virtual bool do_test() = 0;
};

#endif
