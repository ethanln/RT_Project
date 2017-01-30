#pragma once

#ifndef TEST_MANAGER_H
#define TEST_MANAGER_H

#include <string>
#include <iostream>
#include <vector>

#include "ITest.h"
#include "TestFactory.h"

using namespace std;

class TestManager
{
	private:
		vector<ITest*> tests;

	public:
		TestManager();

		~TestManager();

		virtual void loadTests(vector<string> l_tests);

		virtual void runTests();
};

#endif