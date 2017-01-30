#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <fstream>
#include <iostream>
#include <string>
#include "ImageBuffer.h"

#pragma once

class FileSystem
{
	private:

		/**
		* Singleton FileSystem isntance.
		*/
		static FileSystem* instance;

		/**
		* Constant value for jpeg file extension.
		*/
		const char* JPEG_EXT = ".jpg";

	private:

		/**
		* FileSystem Constructor.
		*/
		FileSystem();


		/**
		* FileSystem Deconstructor.
		*/
		~FileSystem();

		/**
		* Grabs singleton instance of FileSystem.
		*/
		static FileSystem* inst();

		virtual bool _save_jpeg(string filename, ImageBuffer image);

	public:
		
		/**
		* Singleton: saves image buffer as jpeg file. 
		*/
		static bool save_jpeg(string filename, ImageBuffer image);
};

#endif