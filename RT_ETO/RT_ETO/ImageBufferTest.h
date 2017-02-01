#pragma once
#ifndef IMAGE_BUFFER_TEST_H
#define IMAGE_BUFFER_TEST_H

#include "Test.h"
#include "ImageBuffer.h"
#include "FileSystem.h"

using namespace std;

class ImageBufferTest : public Test
{
	public:
		ImageBufferTest();

		~ImageBufferTest();

		virtual void print_header();

		virtual bool do_test();
};

#endif