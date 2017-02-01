#include "stdafx.h"
#include "ImageBufferTest.h"

ImageBufferTest::ImageBufferTest()
{

}

ImageBufferTest::~ImageBufferTest()
{

}

void ImageBufferTest::print_header()
{
	this->HEADER_PRINT("TEST: ImageBuffer class tests...");
}

bool ImageBufferTest::do_test()
{
	bool is_pass = true;

	ImageBuffer buffer(700, 700, new Color(1.0f, 0.0f, 0.0f));

	FileSystem::save_bmp("../../output/stuff", buffer);

	return is_pass;
}