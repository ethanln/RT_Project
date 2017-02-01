#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <Windows.h>
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
		const char* BMP_EXT = ".bmp";

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

		virtual bool _save_bmp(string filename, ImageBuffer image);

	public:
		
		/**
		* Singleton: saves image buffer as bmp file. 
		*/
		static bool save_bmp(string filename, ImageBuffer image);
};

#endif