#include "stdafx.h"
#include "FileSystemTest.h"

FileSystemTest::FileSystemTest() : Test()
{

}

FileSystemTest::~FileSystemTest()
{

}

void FileSystemTest::print_header()
{
	this->HEADER_PRINT("TEST: FileSystem class tests...");
}

bool FileSystemTest::do_test()
{
	bool is_pass = true;
	string url = "test1.jpg";
	//ImageBuffer img = FileSystem::load_bump_map(url);
	//FileSystem::save_bmp("../../output/test1", img);

	return is_pass;
}