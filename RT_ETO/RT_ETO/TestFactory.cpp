#include "stdafx.h"
#include "TestFactory.h"

TestFactory* TestFactory::instance;


TestFactory::TestFactory()
{

}

TestFactory::~TestFactory()
{
	// TEST: for memory leaks.
	delete TestFactory::inst();
}

TestFactory* TestFactory::inst()
{
	if (TestFactory::instance == nullptr) {
		TestFactory::instance = new TestFactory();
	}
	return TestFactory::instance;
}

Test* TestFactory::_make_test(string key)
{
	if (key == "Vec3Test") 
	{
		return new Vec3Test();
	}
	else if (key == "ColorTest")
	{
		return new ColorTest();
	}
	else if (key == "ImageBufferTest")
	{
		return new ImageBufferTest();
	}
	else if (key == "CameraViewTest") 
	{
		return new CameraViewTest();
	}
	else if (key == "RayUtilTest")
	{
		return new RayUtilTest();
	}
	return nullptr;
}

Test* TestFactory::make_test(string key)
{
	return TestFactory::inst()->_make_test(key);
}