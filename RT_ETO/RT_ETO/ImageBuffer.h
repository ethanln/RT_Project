#ifndef IMAGE_BUFFER_H
#define IMAGE_BUFFER_H

#include <vector>
#include <array>
#include "Color.h"
#pragma once

class ImageBuffer
{
	private:

		/**
		* Y dimension.
		*/
		int dim_x;

		/**
		* Y dimension.
		*/
		int dim_y;

		/**
		* Image buffer instance.
		*/
		vector<vector<Color*>> buffer;
	
	private:

		/**
		* Initializes the image buffer, called from the constructor.
		*/
		virtual void initiate_buffer(Color* color);

	public:

		/**
		* ImageBuffer Constructor.
		*/
		ImageBuffer(int _dim_x, int _dim_y);

		/**
		* ImageBuffer Constructor.
		*/
		ImageBuffer(int _dim_x, int _dim_y, Color* c);

		/**
		* ImageBuffer Deconstructor.
		*/
		~ImageBuffer();

		/**
		* Updates pixel value at x and y position.
		*/
		virtual void update_pixel(Color* color, int x, int y);

		/**
		* Fetches pixel value from buffer.
		*/
		virtual Color* get_pixel(int x, int y);

		/**
		* Fetches x dimension.
		*/
		virtual int get_x_dim();

		/**
		* Fetches y dimension.
		*/
		virtual int get_y_dim();

		/**
		* Converts image buffer into binary array.
		*/
		virtual uint8_t* get_binary();

		/**
		* Fetches size of buffer.
		*/
		virtual int get_size();
};
#endif
