#include "stdafx.h"
#include "ImageBuffer.h"

void ImageBuffer::initiate_buffer(Color c)
{
	for (unsigned int i = 0; i < this->dim_y; i++)
	{
		this->buffer.push_back(vector<Color*>());
		for (unsigned int j = 0; j < this->dim_x; j++)
		{
			// Intialize pixel to parameter color.
			this->buffer.at(i).push_back(new Color(c.r, c.g, c.b));
		}
	}
}

ImageBuffer::ImageBuffer(int _dim_x, int _dim_y)
{
	this->dim_x = _dim_x;
	this->dim_y = _dim_y;

	// instantiate buffer.
	this->buffer = vector<vector<Color*>>();
	this->initiate_buffer(Color(0.0f, 0.0f, 0.0f));
}

ImageBuffer::ImageBuffer(int _dim_x, int _dim_y, Color c)
{
	this->dim_x = _dim_x;
	this->dim_y = _dim_y;

	// instantiate buffer.
	this->buffer = vector<vector<Color*>>();
	this->initiate_buffer(c);
}

ImageBuffer::~ImageBuffer()
{
	
}

void ImageBuffer::update_pixel(Color color, int x, int y)
{
	try
	{
		// update rgb values at index y and x.
		this->buffer.at(y).at(x)->r = color.r;
		this->buffer.at(y).at(x)->g = color.g;
		this->buffer.at(y).at(x)->b = color.b;
	}
	catch (exception& e)
	{
		// throw Image Buffer Exception if x and y are out of range.
		stringstream ss;
		ss << "Pixel index (" << x << ", " << y << ") out of range.";
		throw ImageBufferException(ss.str());
	}
}

Color* ImageBuffer::get_pixel(int x, int y)
{
	try
	{
		// fetch color pointer reference
		return this->buffer.at(y).at(x);
	}
	catch (exception& e)
	{
		// throw Image Buffer Exception if x and y are out of range.
		stringstream ss;
		ss << "Pixel index (" << x << ", " << y << ") out of range.";
		throw ImageBufferException(ss.str());
	}
}

int ImageBuffer::get_x_dim()
{
	return this->dim_x;
}

int ImageBuffer::get_y_dim()
{
	return this->dim_y;
}

uint8_t* ImageBuffer::get_binary()
{

	// Initialize binary array.
	uint8_t* binary = new uint8_t[this->get_size()];

	// Set current binary index position.
	int current_binary_pos = 0;

	// Loop through each pixel and store them in the binary array as 8 bit value.
	for (unsigned int i = 0; i < this->dim_y; i++)
	{
		for (unsigned int j = 0; j < this->dim_x; j++) {
			binary[current_binary_pos] = this->buffer.at(i).at(j)->r * 255.0f;
			current_binary_pos++;
			binary[current_binary_pos] = this->buffer.at(i).at(j)->g * 255.0f;
			current_binary_pos++;
			binary[current_binary_pos] = this->buffer.at(i).at(j)->b * 255.0f;
			current_binary_pos++;
		}
	}

	// return binary array.
	return binary;
}

int ImageBuffer::get_size()
{
	return this->dim_x * this->dim_y * 3;
}