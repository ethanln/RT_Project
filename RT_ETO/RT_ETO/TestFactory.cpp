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
	return nullptr;
}

Test* TestFactory::make_test(string key)
{
	return TestFactory::inst()->_make_test(key);
}