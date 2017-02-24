#pragma once
#ifndef FILE_SYSTEM_TEST_H
#define FILE_SYSTEM_TEST_H

#include "Test.h"
#include "FileSystem.h"

using namespace std;

class FileSystemTest : public Test
{
public:
	FileSystemTest();

	~FileSystemTest();

	virtual void print_header();

	virtual bool do_test();
};
#endif