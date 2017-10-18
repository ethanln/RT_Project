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

	ImageBuffer buffer(700, 700, Color(1.0f, 0.0f, 0.0f));
	Color* c1 = buffer.get_pixel(0, 0);

	c1->r -= 0.5f;
	c1->g += 0.3f;
	c1->b += 0.1f;

	this->ASSERT_EQUALS("Test buffer get pixel color change r.", 0.5f, buffer.get_pixel(0, 0)->r);
	this->ASSERT_EQUALS("Test buffer get pixel color change g.", 0.300000012f, buffer.get_pixel(0, 0)->g);
	this->ASSERT_EQUALS("Test buffer get pixel color change b.", 0.100000001f, buffer.get_pixel(0, 0)->b);

	buffer.update_pixel(Color(0.2f, 0.1f, 0.9f), 349, 349);

	this->ASSERT_EQUALS("Test buffer update pixel r.", 0.2f, buffer.get_pixel(349, 349)->r);
	this->ASSERT_EQUALS("Test buffer update pixel g.", 0.1f, buffer.get_pixel(349, 349)->g);
	this->ASSERT_EQUALS("Test buffer update pixel b.", 0.9f, buffer.get_pixel(349, 349)->b);

	this->ASSERT_EQUALS("Test buffer size.", 1470000, buffer.get_size());

	try 
	{
		c1 = buffer.get_pixel(-1, -1);
	}
	catch (ImageBufferException e)
	{
		this->ASSERT_EQUALS("Test out of index error lower bound", "Pixel index (-1, -1) out of range.", e.what());
	}

	try
	{
		c1 = buffer.get_pixel(700, 700);
	}
	catch (ImageBufferException e)
	{
		this->ASSERT_EQUALS("Test out of index error upper bound", "Pixel index (700, 700) out of range.", e.what());
	}

	ImageBuffer clone_buffer = buffer.clone();
	this->ASSERT_EQUALS("Test clone buffer update pixel r equal to buffer pixel r.", buffer.get_pixel(349, 349)->r, clone_buffer.get_pixel(349, 349)->r);
	this->ASSERT_EQUALS("Test clone buffer update pixel g equal to buffer pixel g.", buffer.get_pixel(349, 349)->g, clone_buffer.get_pixel(349, 349)->g);
	this->ASSERT_EQUALS("Test clone buffer update pixel b equal to buffer pixel b.", buffer.get_pixel(349, 349)->b, clone_buffer.get_pixel(349, 349)->b);
	buffer.update_pixel(Color(0.4f, 0.3f, 0.1f), 349, 349);
	this->ASSERT_NOT_EQUAL("Test clone buffer update pixel r not equal to buffer pixel r.", buffer.get_pixel(349, 349)->r, clone_buffer.get_pixel(349, 349)->r);
	this->ASSERT_NOT_EQUAL("Test clone buffer update pixel g not equal to buffer pixel g.", buffer.get_pixel(349, 349)->g, clone_buffer.get_pixel(349, 349)->g);
	this->ASSERT_NOT_EQUAL("Test clone buffer update pixel b not equal to buffer pixel b.", buffer.get_pixel(349, 349)->b, clone_buffer.get_pixel(349, 349)->b);

	FileSystem::save_bmp("../../output/stuff", buffer);

	return is_pass;
}