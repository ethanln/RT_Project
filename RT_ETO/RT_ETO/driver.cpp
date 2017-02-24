// RT_ETO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "TestManager.h"

using namespace std;

int main(int argc, const char * argv[])
{
	bool is_test = string(argv[argc - 1]) == "test";

	if (is_test)
	{
		// run tests.
		TestManager* tests = new TestManager();
		tests->loadTests({ "Vec3Test", "ColorTest", "ImageBufferTest", "CameraViewTest", "RayUtilTest", "MathUtilTest", "ShapeUtilTest", "ShapeTest", "FileSystemTest" });
		tests->runTests();
	}
	else 
	{
		// run application.
	}
    return 0;
}

