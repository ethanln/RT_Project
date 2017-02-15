#pragma once

#ifndef TEST_FACTORY_H
#define TEST_FACTORY_H

#include <string>
#include "ITest.h"
#include "Vec3Test.h"
#include "ColorTest.h"
#include "ImageBufferTest.h"
#include "CameraViewTest.h"
#include "RayUtilTest.h"
#include "MathUtilTest.h"

using namespace std;

class TestFactory 
{
	private:

		/**
		* Singleton TestFactory isntance.
		*/
		static TestFactory* instance;

	private:

		/**
		* TestFactory Constructor.
		*/
		TestFactory();

		/**
		* TestFactory Deconstructor.
		*/
		~TestFactory();

		/**
		* Grabs singleton instance of TestFactory.
		*/
		static TestFactory* inst();

		virtual Test* _make_test(string key);

	public:

		/**
		* Singleton: fetch test instance.
		*/
		static Test* make_test(string key);
};

#endif
