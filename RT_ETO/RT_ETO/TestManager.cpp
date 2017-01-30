#include "stdafx.h"
#include "TestManager.h"

TestManager::TestManager()
{
	
}

TestManager::~TestManager()
{

}

void TestManager::loadTests(vector<string> l_tests)
{
	cout << "Loading tests..." << endl;

	for (const string &key : l_tests)
	{
		this->tests.push_back(TestFactory::make_test(key));
	}
}

void TestManager::runTests()
{
	cout << "Running tests..." << endl;

	for (ITest* test : this->tests)
	{
		test->print_header();
		test->do_test();
	}

	system("pause");
}